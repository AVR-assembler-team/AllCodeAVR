.macro OneWire_TemperatureDataConvertation

	push r16													; вталкиваем r16 в STACK
	push r17													; вталкиваем r17 в STACK
	push r18													; вталкиваем r18 в STACK
	push zh														; вталкиваем zh в STACK
	push zl														; вталкиваем zl в STACK

	_call OneWireTemperatureConversation_act
	
	pop zl														; выталкиваем zl из STACK
	pop zh														; выталкиваем zh из STACK
	pop r18														; выталкиваем r18 из STACK
	pop r17														; выталкиваем r17 из STACK
	pop r16														; выталкиваем r16 из STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireTemperatureConversation_act:

	READ_REG OneWireFlags, r16							; копируем регистр флагов в r16
	sbrc r16, OneWireDeviceNotDetected					; проверяем флат присутствия на шине
		_jump OneWireTemperatureConversation_act_finish	; перепрыгиваем
	READ_REG OneWireScratchpad + 1, r16					; копируем старший байт температуры
	READ_REG OneWireScratchpad, r17						; копируем младший байт температуры

	lsl r17												; сдвиг влево
	rol r16												; сдвиг влево

	lsl r17												; сдвиг влево
	rol r16												; сдвиг влево

	lsl r17												; сдвиг влево
	rol r16												; сдвиг влево

	lsl r17												; сдвиг влево
	rol r16												; сдвиг влево

	sbrs r16, 7											; проверяем бит знака температуры
		_jump IsPlus									; переходим на плюс

IsMinus:
	SETB OneWireFlags, OneWireNegativeTemperature		; поднимаем флаг минуса
	com r16												; делаем побитную инверсию старшего байта
	com r17												; делаем побитную инверсию старшего байта
	_jump Is1											; перепрыгиваем дальше

IsPlus:
	CLRB OneWireFlags, OneWireNegativeTemperature		; очищаем флаг минуса

Is1:
	swap r17											; меняем местами тетрады младшего байта
	WRITE_REG OneWireTemperature + 1, r17				; сохраняем показания температуры после запятой 

DegreesCalc:
	ldi r17, $64										; записываем в r17 значение 100
	CLRB OneWireFlags, OneWireOneHundredDegrees			; очищаем флаг 100 градусов

loop_100:								
	sub r16, r17										; отнимаем от r16 r17
	brmi loop_100_finish								; если получился -, то переходим
	SETB OneWireFlags, OneWireOneHundredDegrees			; устанавливаем флаг 100 градусов
	_jump loop_100										; перескакиваем по метке

loop_100_finish:
	add r16, r17										; добавляем к r16 r17
	clr r18												; очищаем r18
	ldi r17, $0a										; записываем в r17 значение 10

loop_10:
	sub r16, r17										; отнимаем от r16 r17
	brmi loop_10_finish									; если получился -, то переходим
	inc r18												; увеличиваем r18 на 1
	_jump loop_10										; перепрыгиваем по метке
		
loop_10_finish:
	add r16, r17										; добавляем к r16 r17
	swap r16											; меняем тетрады r16

	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	WRITE_REG OneWireTemperature, r18					; сохраняем целые значения температуры в память

AfterDotCalc:
	ldi zh, high(TempTable * 2)							; записываем младший байт адреса метки
	ldi zl, low(TempTable * 2)							; записываем младший байт адреса метки
	READ_REG OneWireTemperature + 1, r16				; считываем показания после точки в r16
	add zl, r16											; добавляем r16 к младшему регистру адреса таблицы
	clr r16												; очищаем r16
	adc zh, r16											; добавляем с переносом r16 к младшему регистру адреса таблицы

	lpm r16, z											; копируем байт из таблицы
	clr r18												; очищаем r18
	ldi r17, $0a										; записываем в r17 значение 10

loop_10th:
	sub r16, r17										; отнимаем от r16 r17
	brmi loop_10th_finish								; если получился -, то переходим
	inc r18												; увеличиваем r18 на 1
	_jump loop_10th										; перепрыгиваем по метке
		
loop_10th_finish:
	add r16, r17										; добавляем к r16 r17
	swap r16
	
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	lsl r16												; сдвиг влево
	rol r18												; сдвиг влево
	WRITE_REG OneWireTemperature + 1, r18				; сохраняем значение температуры после запятой в память

OneWireTemperatureConversation_act_finish:
	
ret

TempTable: .db $00, $06, $0c, $13, $19, $1f, $26, $2c, $32, $38, $3f, $45, $4b, $51, $58, $5e
	// $00 ; .00
	// $06 ; .06
	// $0c ; .13
	// $13 ; .19
	// $19 ; .25
	// $1f ; .31
	// $26 ; .38
	// $2c ; .44
	// $32 ; .50
	// $38 ; .56
	// $3f ; .63
	// $45 ; .69
	// $4b ; .75
	// $51 ; .81
	// $58 ; .88
	// $5e ; .94
		