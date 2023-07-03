/*
* Передаем модулю TWSI что мы хотим, читать или записывать
* Принимает два аргумента
* @0 - Адрес модуля TWSI
* @1 - 'W'-запись / 'R'-чтение
*/
.macro TWSI_SLA
	push r16
	.if @1 == 'W'
		ldi	r16, @0
	.elif @1 == 'R'
		ldi	r16, @0
		sbr	r16, 1
	.endif
		
	_call TWSI_Sending_byte_act

	.if @1 == 'W'
		TWSI_Status MT_SLA_W_ACK					; Проверяем получен ли ответ
	.elif @1 == 'R'
		TWSI_Status MT_SLA_R_ACK					; Проверяем получен ли ответ
	.endif
	pop r16
.endm
