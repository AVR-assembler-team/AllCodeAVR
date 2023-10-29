/*
* Использует регистр r25
*/

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
