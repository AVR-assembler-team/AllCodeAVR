/*
 * @0 - адрес начала строки в RAM контроллера
 * @1 - полином
 * @2 - количество байт для создания CRC
 * @3 - регистр ответа
 */ 

 .macro CRCCalculate
	push zh
	push zl
	push r16
	push r17
	push r18
	push r19
	push r21
	push r22

	ldi zh, high(@0)
	ldi zl, low(@0)
	ldi r16, @1
	ldi r17, @2

	_call CRCCalculate_act

	WRITE_REG CRC_byte, r18

	pop r22
	pop r21
	pop r19
	pop r18
	pop r17
	pop r16
	pop zl
	pop zh
 .endm

 CRCCalculate_act:
	ld r18, z+						; копируем первый байт в регистр r18
	dec r17							; уменьшаем количество регистров для проверки
	CRCCalculateBegin:
		ld r19, z+					; копируем байт в регистр r19
		_call CRCCalc
		dec r17						; уменьшаем количество регистров для проверки
		brne CRCCalculateBegin	; если не равно 0, то переходим по метке
		clr r19
		_call CRCCalc
 ret

CRCCalc:
	cli											; выключаем прерывания	
			
	ldi r21, $08								; количество повторений сдвигов

CRCCalc_act:
	dec r21						; уменьшаем количество сдвигов
	brlt CRCCalc_end		; если меньше 0, то переходим
	ror r19						; сдвигаем байт вправо через С
	ror r18						; сдвигаем байт вправо через С
	READ_REG SREG, r22			; копируем SREG в R22
	sbrs r22, 0					; проверяем состояние флага С
	_jump CRCCalc_act	; переходим если флаг опущен
	eor r18, r16				; побитовое исключающее ИЛИ двух регистров
	_jump CRCCalc_act	; переходим

	CRCCalc_end:

	sei							; включаем прерывания
ret