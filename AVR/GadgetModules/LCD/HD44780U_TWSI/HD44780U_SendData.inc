/*
* Отправка данных дисплею
* Принимает один аргуммент - регистр с данными для отправки
*/

	HD44780U_Send_data:
		push r25
		TWSI_START								; отсылаем START (рестартуем для записи)
		TWSI_SLA HD44780U_SLA_, 'W'
		pop r25
		_call HD44780U_Send_data_byte_high	; переходим по метке
		_call HD44780U_Send_data_byte_low		; переходим по метке
		TWSI_STOP								; отсылаем START (рестартуем для записи)
	ret									; выход из подпрограммы
	;----------------------------------------------------------------
	HD44780U_Send_data_byte_high:
		push	r25						; записываем в стек
		andi	r25, $f0				; обнуляем первые 4 бита
		push	r25						; записываем в стек
		
		SETRB r25, HD44780U_LCD_RS
		SETRB r25, HD44780U_LCD_E
		SETRB r25, HD44780U_LCD_LIGHT

		WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r25										; извлекаем из стека
		
		SETRB r25, HD44780U_LCD_RS
		SETRB r25, HD44780U_LCD_LIGHT
		
		WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r25						; извлекаем из стека
	ret									; выход из подпрограммы
	;----------------------------------------------------------------
	HD44780U_Send_data_byte_low:
		swap	r25						; меняем тетрады местами
		andi	r25, $f0				; обнуляем первые 4 бита
		push	r25						; помещаем в стек
		
		SETRB r25, HD44780U_LCD_RS
		SETRB r25, HD44780U_LCD_E
		SETRB r25, HD44780U_LCD_LIGHT

		WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r25										; извлекаем из стека r16
		
		SETRB r25, HD44780U_LCD_RS
		SETRB r25, HD44780U_LCD_LIGHT
		WRITE_REG TWDR, r25								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
	ret													; выход из подпрограммы	

