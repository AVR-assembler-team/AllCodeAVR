/*
* Данный макрос проверяет флаг занятости дисплея
* Использует регистр r25
*/
HD44780U_BF_Check:								; подпрограмма проверяет флаг занятости
	
	push r25										; вталкиваем r16 в STACK
	push r24										; вталкиваем r17 в STACK

	ldi		r25, 0xFA								; держим подсветку LCD и RW на +5, Е и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр

	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	TWSI_STOP

	TWSI_START 										; отсылаем START (рестартуем для чтения)

	TWSI_SLA HD44780U_SLA_, 'R'

HD44780U_BF_Check_act_1:

	READ_REG TWDR, r24								; читаем байт из I2C в r17
	sbrc	r24, 7									; если седьмой бит равен 0, то пропускаем след строку
		_jump	HD44780U_BF_Check_act_1				; переходим по метке
		
	TWSI_STOP										; больше не принимаем байты
	TWSI_START										; отсылаем START (рестартуем для записи)

	TWSI_SLA HD44780U_SLA_, 'W'

	ldi		r25, 0x08								; оставляем только подсветку LCD
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ


	pop r24											; выталкиваем r17 из STACK
	pop r25											; выталкиваем r16 из STACK
ret													; выход из подпрограммы
