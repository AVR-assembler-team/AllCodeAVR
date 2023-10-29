/*
* Данный макрос проверяет флаг занятости дисплея
* Использует регистр r23, r24, r25
*/
HD44780U_BF_Check:									; подпрограмма проверяет флаг занятости

	ldi		r25, 0xFA								; держим подсветку LCD и RW на +5, Е и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр

	TWSI_Byte_Transmit								; r25 Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; r23, r24, r25 Проверяем получен ли ответ

	TWSI_STOP										; r15

	TWSI_START 										; r25 отсылаем START (рестартуем для чтения)

	TWSI_SLA HD44780U_SLA_, 'R'						; r23, r24, r25

HD44780U_BF_Check_act_1:

	READ_REG TWDR, r25								; читаем байт из I2C в r17
	sbrc	r25, 7									; если седьмой бит равен 0, то пропускаем след строку
		_jump	HD44780U_BF_Check_act_1				; переходим по метке
		
	TWSI_STOP										; r25 больше не принимаем байты
	TWSI_START										; r25 отсылаем START (рестартуем для записи)

	TWSI_SLA HD44780U_SLA_, 'W'						; r23, r24, r25

	ldi		r25, 0x08								; оставляем только подсветку LCD
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
	TWSI_Byte_Transmit								; r25 Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; r23, r24, r25 Проверяем получен ли ответ

ret													; выход из подпрограммы
