/*
* Принимает один аргумент - OneWireSearchROMCommand или OneWireAlarmSearchCommand
* После каждого найденного ROM или ALARM попадаем по метке ROMCodeNormal или ROMCodeAlarm
*/

.macro OneWireROMSearching
	push r20											; вталкиваем r20 в STACK
	ldi r20, @0
	_call OneWireROMSearching_act
	pop r20												; выталкиваем r20 из STACK
.endm 
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireROMSearching_act:
	
	push zh												; вталкиваем zh в STACK
	push zl												; вталкиваем zl в STACK
	push r16											; вталкиваем r16 в STACK
	push r17											; вталкиваем r17 в STACK
	push r18											; вталкиваем r18 в STACK

	WRITE_BYTE OneWireFlags, $00						; обнуляем переменные ROM поиска
	
OneWireMainLoop:
	READ_REG OneWireFlags, r16						; копируем регистр флагов в r16
	sbrc r16, OneWireDeviceNotDetected				; проверяем флат присутствия на шине
		_jump OneWireROMSearching_act_fihish	; заканчиваем поиск
	
	cpi r20, OneWireSearchROMCommand
	brne AlarmSearchROMString
	ldi zh, high(OneWireROMCode)			; копируем старший байт адреса OneWireROMCode
	ldi zl, low(OneWireROMCode)				; копируем младший байт адреса OneWireROMCode
	_jump DevicesIs

AlarmSearchROMString:
	ldi zh, high(OneWireAlarmROMCode)		; копируем старший байт адреса OneWireAlarmROMCode
	ldi zl, low(OneWireAlarmROMCode)		; копируем младший байт адреса OneWireAlarmROMCode

DevicesIs:
	// Проверяем остались еще девайсы или нет
	READ_REG OneWireFlags, r16
	sbrc r16, OneWireLastDevice
		_jump OneWireROMSearching_act_fihish	; переходми если поднят

	WRITE_BYTE OneWireZeroFork, $ff					; пишем 255 в переменную
	WRITE_BYTE OneWireStep, $00						; обнуляем переменную

	cpi r20, OneWireSearchROMCommand
	brne AlarmSearch
	OneWireSendCommand OneWireSearchROMCommand		; приказываем начать поиск
	_jump TwoBitsRead

AlarmSearch:
	OneWireSendCommand OneWireAlarmSearchCommand

TwoBitsRead:
	OneWireReadBit							; читаем первый бит
	READ_REG SREG, r16						; смотрим флаг Т
	READ_REG OneWireFlags, r17				; считываем байт флагов поиска ROM
	sbrs r16, 6
		cbr r17, (1<<OneWireSlaveBit)		; очищаем флаг первого бита
	sbrc r16, 6
		sbr r17, (1<<OneWireSlaveBit)		; устанавливаем флаг первого бита
	WRITE_REG OneWireFlags, r17				; записываем байт флагов в память
	OneWireReadBit							; читаем второй бит и сохраняем его в SREG T

TwoBitsMatch:
	// Сравниваем два бита и переходим
	READ_REG SREG, r16						; смотрим флаг Т
	READ_REG OneWireFlags, r17				; считываем байт флагов поиска ROM
	// Проверяем равенство прочтенных 2-х битов
	sbrc r17, OneWireSlaveBit				; проверяем состояние флага
		_jump OneWireSlaveBit1				; переходми если поднят

OneWireSlaveBit0:
	sbrc r16, 6								; проверяем состояние флага Т
		_jump BitsNotAqual					; переходми если поднят
		_jump BitsAqual						; переходми если очищен

OneWireSlaveBit1:
	sbrc r16, 6
		_jump BitsAqual						; переходми если поднят
		_jump BitsNotAqual					; переходми если очищен

BitsAqual:
	READ_REG OneWireFlags, r17				; считываем байт флагов поиска ROM
	sbrc r17, OneWireSlaveBit				; если SlaveBit равен 0, то пропускаем след строку
		_jump OneWire_SearchROMError		; переходми если поднят

StepMatchLastFork1:
	READ_REG OneWireStep, r16				; читаем Step
	READ_REG OneWireLastFork, r17			; читаем LastFork
	cp r16, r17								; сравниваем Step и LastFork
	brne StepMatchLastFork2					; если не равны, то переходим

MasterBitSet1:
	SETB OneWireFlags, OneWireMasterBit		; устанавливаем MasterBit в 1
	_jump ROMVarAddBit						; перепрыгиваем

StepMatchLastFork2:
	cp r16, r17								; сравниваем r16 и r17
	brlo MasterBitSetLastROMBit				; если меньше то переходим
	CLRB OneWireFlags, OneWireMasterBit		; устанавливаем MasterBit в 0
	_jump MasterBitCheck					; перепрыгиваем

MasterBitSetLastROMBit:
	READ_REG OneWireFlags, r16				; копируем байт флагов ROM
	READ_REG OneWireROMVar, r17				; копируем переменную ROM
	sbrs r17, 7		
		cbr r16, (1<<OneWireMasterBit)		; очищаем мастер бит
	sbrc r17, 7
		sbr r16, (1<<OneWireMasterBit)		; устанавливаем мастер бит
	WRITE_REG OneWireFlags, r16				; записываем бай флагов ROM в память

MasterBitCheck:
	READ_REG OneWireFlags, r17				; копируем байт флагов ROM
	READ_REG OneWireStep, r16				; копируем байт шагов
	sbrs r17, OneWireMasterBit				; если VasterBit равен единице, то пропускаем следующую строку
		WRITE_REG OneWireZeroFork, r16		; записываем регистр в память
	_jump ROMVarAddBit						; перепрыгиваем

// Биты не равны
BitsNotAqual:
	// Устанавливаем MasterBit таким же как был SlaveBit
	READ_REG OneWireFlags, r17						; считываем байт флагов поиска ROM
	sbrs r17, OneWireSlaveBit
		cbr r17, (1<<OneWireMasterBit)
	sbrc r17, OneWireSlaveBit
		sbr r17, (1<<OneWireMasterBit)
	WRITE_REG OneWireFlags, r17						; записываем байт флагов в память
		
// Записываем бит в байт для записи в память
ROMVarAddBit:
	READ_REG OneWireFlags, r17						; считываем байт флагов поиска ROM
	READ_REG OneWireROMVar, r16						; копируем переменную байта ROM в r16
	lsr r16											; сдвигаем r16 вправо для записи младшего бита
	// Добавляем MasteBit в переменную байта ROM
	sbrs r17, OneWireMasterBit
		cbr r16, (1<<7)
	sbrc r17, OneWireMasterBit
		sbr r16, (1<<7)
	inc r17									; увеличиваем количество сдвигов
	WRITE_REG OneWireROMVar, r16			; записываем r16 в переменную байта ROM
	WRITE_REG OneWireFlags, r17				; сохраняем состояния байт
	// Проверяем закончился ли байт
	mov r18, r17							; копируем r17 в r18
	andi r18, $0f							; обнуляем старшую тетраду
	cpi r18, $08							; сравниваем с 8
	brne MasterBitSending					; если не равно, то переходим
	st z+, r16								; записываем в память с пост-инкрементом
	andi r17, $f0							; обнуляем младшую тетраду
	WRITE_REG OneWireFlags, r17				; сохраняем состояния байт

MasterBitSending:
	READ_REG OneWireFlags, r17				; считываем байт флагов поиска ROM
	// Посылаем MasterBit в шину
	sbrs r17, OneWireMasterBit
		OneWireWriteBit 0
	sbrc r17, OneWireMasterBit
		OneWireWriteBit 1

IncreaseStep:
	READ_REG OneWireStep, r17				; читаем байт с количеством шагов
	inc r17									; увеличиваем r17 на 1
	WRITE_REG OneWireStep, r17				; записываем в память

StepCheck:
	READ_REG OneWireStep, r17				; читаем байт с количеством шагов
	cpi r17, 64								; сравниваем шаг с 64
	brsh OneWireStepLoopContinue			; переходим если равно или больше
	// Усли меньше, то возвращаемся для чтения следующих бит
	_jump TwoBitsRead						; перепрыгиваем

OneWireStepLoopContinue:
	READ_REG OneWireZeroFork, r16			; копируем байт из памяти
	WRITE_REG OneWireLastFork, r16			; записываем байт в память
	cpi r16, $ff							; сравниваем R16 с 255
	brne CheckCRC							; переходим если не равно
	SETB OneWireFlags, OneWireLastDevice	; устанавливаем флаг в регистре флагов

CheckCRC:
	OneWireCRCCheck	8						; запускаем проверку CRC
	_call OneWire_ROM
	_jump OneWireMainLoop					; перепрыгиваем

OneWireROMSearching_act_fihish:

	pop r18									; выталкиваем r18 из STACK
	pop r17									; выталкиваем r17 из STACK
	pop r16									; выталкиваем r16 из STACK
	pop zl									; выталкиваем zl из STACK
	pop zh									; выталкиваем zh из STACK

ret

OneWire_SearchROMError:
	_call ReadROMError						; переходми если поднят
	_jump OneWireROMSearching_act_fihish

OneWire_ROM:
	cpi r20, OneWireSearchROMCommand		; узнаем,что ищем Alarm или Normal ROM коды
	brne OneWire_ROMAlarm					; если Alarm, то переходим к OneWire_ROMAlarm
	_call ROMCodeNormal						; переходим (находится в OneWire_config.inc)
	ret
OneWire_ROMAlarm:
	_call ROMCodeAlarm						; переходим (находится в OneWire_config.inc)
	ret
