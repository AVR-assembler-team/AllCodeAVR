/*
* Данный макрос проверяет флаг занятости дисплея
*/
.macro HD44780U_BF_Check
	_call HD44780U_BF_Check_act	; переходим
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires
	HD44780U_BF_Check_act:								; проверка состояния флага занятости
		
		// Ноги на вход
		CLRB HD44780U_D0_DDR, HD44780U_D0_bit
		CLRB HD44780U_D1_DDR, HD44780U_D1_bit
		CLRB HD44780U_D2_DDR, HD44780U_D2_bit
		CLRB HD44780U_D3_DDR, HD44780U_D3_bit
		CLRB HD44780U_D4_DDR, HD44780U_D4_bit
		CLRB HD44780U_D5_DDR, HD44780U_D5_bit
		CLRB HD44780U_D6_DDR, HD44780U_D6_bit
		CLRB HD44780U_D7_DDR, HD44780U_D7_bit

		cbi HD44780U_RS_PORT, HD44780U_RS_bit			; уставливаем на инструкции
		sbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на + (чтение)

	HD44780U_Read_bit:
		sbi	HD44780U_E_PORT, HD44780U_E_bit				; начинаем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; проверяем состояние бита для D7
			rjmp HD44780U_Busy_Flag_End					; если флага нет, то переходим

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		rjmp HD44780U_Read_bit							; если поднять бит для D7 то возвращаемся к чтению

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на землю (запись)
		
		// Ноги на выход
		SETB HD44780U_D0_DDR, HD44780U_D0_bit
		SETB HD44780U_D1_DDR, HD44780U_D1_bit
		SETB HD44780U_D2_DDR, HD44780U_D2_bit
		SETB HD44780U_D3_DDR, HD44780U_D3_bit
		SETB HD44780U_D4_DDR, HD44780U_D4_bit
		SETB HD44780U_D5_DDR, HD44780U_D5_bit
		SETB HD44780U_D6_DDR, HD44780U_D6_bit
		SETB HD44780U_D7_DDR, HD44780U_D7_bit

	ret													; выход из подпрограммы
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_BF_Check_act:
		
		// Ноги на вход
		CLRB HD44780U_D4_DDR, HD44780U_D4_bit
		CLRB HD44780U_D5_DDR, HD44780U_D5_bit
		CLRB HD44780U_D6_DDR, HD44780U_D6_bit
		CLRB HD44780U_D7_DDR, HD44780U_D7_bit

		cbi HD44780U_RS_PORT, HD44780U_RS_bit			; уставливаем на инструкции
		sbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на + (чтение)

	HD44780U_Read_bit:
		sbi	HD44780U_E_PORT, HD44780U_E_bit				; начинаем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; проверяем состояние бита для D7
			rjmp HD44780U_Busy_Flag_End					; если флага нет, то переходим

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		rjmp HD44780U_Read_bit							; если поднять бит для D7 то возвращаемся к чтению

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на землю (запись)
		
		// Ноги на выход
		SETB HD44780U_D4_DDR, HD44780U_D4_bit
		SETB HD44780U_D5_DDR, HD44780U_D5_bit
		SETB HD44780U_D6_DDR, HD44780U_D6_bit
		SETB HD44780U_D7_DDR, HD44780U_D7_bit

		HD44780U_Delay_4_1ms							; задержка 4,1 мс

	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_BF_Check_act:								; подпрограмма проверяет флаг занятости
	
		push r16										; вталкиваем r16 в STACK
		push r17										; вталкиваем r17 в STACK

		ldi		r16, 0x0A								; держим подсветку LCD на +5 и поднимаем RW на +5
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
							
		ldi		r16, 0xFE								; держим подсветку LCD и RW на +5, Е и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

		HD44780U_Delay_5mks								; задержка
		
		TWSI_STOP										; больше не принимаем байты
		TWSI_START 										; отсылаем START (рестартуем для чтения)
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'R'

		TWSI_Byte_Transmit								; больше не принимаем байты
		READ_REG TWDR, r17								; читаем байт из I2C в r17

		TWSI_START										; отсылаем START (рестартуем для записи)
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'W'

		ldi		r16, 0x0A								; держим подсветку LCD на +5 и поднимаем RW на +5
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		ldi		r16, 0xFE								; держим подсветку LCD и RW на +5, Е и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		HD44780U_Delay_5mks								; задержка

		ldi		r16, 0x0A								; держим подсветку LCD на +5 и RW на +5, остальное на 0
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		ldi		r16, 0x08								; оставляем только подсветку LCD
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		sbrc	r17, 7									; если седьмой бит равен 0, то пропускаем след строку
			rjmp	HD44780U_BF_Check_act				; переходим по метке

		pop r17											; выталкиваем r17 из STACK
		pop r16											; выталкиваем r16 из STACK
	ret													; выход из подпрограммы
#endif

