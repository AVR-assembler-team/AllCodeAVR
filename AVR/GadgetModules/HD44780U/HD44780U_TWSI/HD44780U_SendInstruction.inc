/*
* Отправка инструкций дисплею
* Использует регистр r23, r24, r25
*/
HD44780U_Send_instruction:
	push r25
	TWSI_START								; r25 отсылаем START (рестартуем для записи)
	TWSI_SLA HD44780U_SLA_, 'W'				; r23, r24, r25
	pop r25
	_call HD44780U_Send_instr_byte_high		; r25 переходим по метке
	_call HD44780U_Send_instr_byte_low		; r25 переходим по метке
	TWSI_STOP								; r25 отсылаем START (рестартуем для записи)
ret											; выход из подпрограммы
