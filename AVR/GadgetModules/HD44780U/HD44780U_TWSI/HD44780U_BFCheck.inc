/*
* ƒанный макрос провер€ет флаг зан€тости диспле€
*/
HD44780U_BF_Check:									; подпрограмма провер€ет флаг зан€тости

	push r25

	ldi		r25, 0xFA								; держим подсветку LCD и RW на +5, ≈ и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
	WRITE_REG TWDR, r25								; ¬талкиваем в дата регистр

	TWSI_Byte_Transmit								; ќтправл€ем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ѕровер€ем получен ли ответ

	TWSI_STOP

	TWSI_START 										; отсылаем START (рестартуем дл€ чтени€)

	TWSI_SLA HD44780U_SLA_, 'R'

HD44780U_BF_Check_act_1:

	READ_REG TWDR, r25								; читаем байт из I2C в r25
	sbrc	r25, 7									; если седьмой бит равен 0, то пропускаем след строку
		_jump	HD44780U_BF_Check_act_1				; переходим по метке
		
	TWSI_STOP										; больше не принимаем байты
	TWSI_START										; отсылаем START (рестартуем дл€ записи)

	TWSI_SLA HD44780U_SLA_, 'W'

	ldi		r25, 0x08								; оставл€ем только подсветку LCD
	WRITE_REG TWDR, r25								; вталкиваем в дата регистр
	TWSI_Byte_Transmit								; отправл€ем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; провер€ем получен ли ответ

	pop r25

ret													; выход из подпрограммы
