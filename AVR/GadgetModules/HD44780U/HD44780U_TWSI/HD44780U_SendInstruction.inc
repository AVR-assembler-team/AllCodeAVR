/*
* Отправка инструкций дисплею
* Использует регистр r23, r24, r25
*/
HD44780U_Send_instruction:

	push r25

	TWSI_START								; отсылаем START (рестартуем для записи)
	TWSI_SLA HD44780U_SLA_, 'W'
	_call HD44780U_Send_instr_byte_high		; переходим по метке
	_call HD44780U_Send_instr_byte_low		; переходим по метке
	TWSI_STOP								; отсылаем START (рестартуем для записи)

	pop r25

ret											; выход из подпрограммы
