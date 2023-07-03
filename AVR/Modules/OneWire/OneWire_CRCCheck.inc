/*
* Команда принимает аргумент - число байт для проверки 
* - если это чтение ROM Code то аргумент равен количеству байт в этом коде (стандарт 8)
* - если это чтение Scretch Pad - количество байт в нем (стандарт 9)
* Также необходим адрес байта (в zh:zl) следущего за последним из строки для проверки
* строка для проверки начинается с 0-го байта
*/

.macro OneWireCRCCheck
	push r16									; вталкиваем r16 в STACK
	push r17									; вталкиваем r17 в STACK
	push r18									; вталкиваем r18 в STACK
	push r19									; вталкиваем r19 в STACK
	push r20									; вталкиваем r20 в STACK
	push r21									; вталкиваем r21 в STACK
	push r22									; вталкиваем r22 в STACK
	
	ldi r19, @0									; записываем количество байт для сверки
	ldi r20, @0									; записываем количество байт для сверки
	
	sbiw zh:zl, @0								; вичитаем 8 из слова
	_call OneWireCRCCheck_act
	
	pop r22										; выталкиваем r22 из STACK
	pop r21										; выталкиваем r21 из STACK
	pop r20										; выталкиваем r20 из STACK
	pop r19										; выталкиваем r19 из STACK	
	pop r18										; выталкиваем r18 из STACK	
	pop r17										; выталкиваем r17 из STACK	
	pop r16										; выталкиваем r16 из STACK
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireCRCCheck_act:
	
	READ_REG OneWireFlags, r16					; копируем регистр флагов в r16
	sbrc r16, OneWireDeviceNotDetected			; проверяем флат присутствия на шине
		_jump OneWireCRCCheck_act_finish		; перепрыгиваем
	
	CLRB OneWireFlags, OneWireROMCodeCRCInvalid	; очищаем флаг ошибки данных в регистре флагов
	ld r16, z+									; копируем первый байт в регистр r16
	ldi r17, OneWireCRC_polynom					; записываем перевернутый зщлином для вычисления CRC
	dec r19										; уменьшаем количество регистров для проверки

OneWireCRCCheckBegin:							; метка
	ld r18, z+									; копируем байт в регистр r18
	_call OneWireCRCCheckCalc					; переходим
	dec r19										; уменьшаем количество регистров для проверки
	brne OneWireCRCCheckBegin					; если не равно 0, то переходим по метке
	cpi r16, 0									; сравниваем с 0
	breq OneWireCRCCheckCorrect					; если равно то переходм
	brne OneWireCRCCheckNotCorrect				; если не равно то переходим
	
OneWireCRCCheckCorrect:							; метка
	_jump OneWireCRCCheck_act_finish			; перепрыгиваем
	
OneWireCRCCheckNotCorrect:
	mov r16, r20								; записываем количество байт в области памяти для стирания	
	clr r17										; очищаем регистр r17
	sbiw zh:zl, $08								; вичитаем 8 из слова

OneWireDataClean:
	st z+, r17									; очищаем байт в памяти
	dec r16										; уменьшаем количество количество байт в области памяти для стирания	
	brne OneWireDataClean						; переходим, если байты не закончились
	SETB OneWireFlags, OneWireROMCodeCRCInvalid	; устанавливаем флаг ошибки данных в регистре флагов
	cpi r20, 8
	brne OneWire_ScretchpadCRC
	_call ROMCodeCRCError
	_jump OneWireCRCCheck_act_finish

OneWire_ScretchpadCRC:
	_call ScretchpadCRCError

OneWireCRCCheck_act_finish:								

ret
//----------------------------------------------------------
OneWireCRCCheckCalc:

	cli											; выключаем прерывания	
			
	ldi r21, $08								; количество повторений сдвигов

OneWireCRCCheckAct:
	dec r21						; уменьшаем количество сдвигов
	brlt OneWireCRCCheckEnd		; если меньше 0, то переходим
	ror r18						; сдвигаем байт вправо через С
	ror r16						; сдвигаем байт вправо через С
	READ_REG SREG, r22			; копируем SREG в R22
	sbrs r22, 0					; проверяем состояние флага С
	_jump OneWireCRCCheckAct	; переходим если флаг опущен
	eor r16, r17				; побитовое исключающее ИЛИ двух регистров
	_jump OneWireCRCCheckAct	; переходим

OneWireCRCCheckEnd:

	sei							; включаем прерывания
ret
