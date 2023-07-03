/*
* ƒанный макрос провер€ет флаг зан€тости диспле€
*/
.macro HD44780U_BF_Check
	_call HD44780U_BF_Check_act	; переходим
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires
	HD44780U_BF_Check_act:								; проверка состо€ни€ флага зан€тости
		
		// Ќоги на вход
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
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; провер€ем состо€ние бита дл€ D7
			rjmp HD44780U_Busy_Flag_End					; если флага нет, то переходим

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		rjmp HD44780U_Read_bit							; если подн€ть бит дл€ D7 то возвращаемс€ к чтению

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на землю (запись)
		
		// Ќоги на выход
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
		
		// Ќоги на вход
		CLRB HD44780U_D4_DDR, HD44780U_D4_bit
		CLRB HD44780U_D5_DDR, HD44780U_D5_bit
		CLRB HD44780U_D6_DDR, HD44780U_D6_bit
		CLRB HD44780U_D7_DDR, HD44780U_D7_bit

		cbi HD44780U_RS_PORT, HD44780U_RS_bit			; уставливаем на инструкции
		sbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на + (чтение)

	HD44780U_Read_bit:
		sbi	HD44780U_E_PORT, HD44780U_E_bit				; начинаем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; провер€ем состо€ние бита дл€ D7
			rjmp HD44780U_Busy_Flag_End					; если флага нет, то переходим

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		HD44780U_Delay_5mks								; задержка 5 мкс
		rjmp HD44780U_Read_bit							; если подн€ть бит дл€ D7 то возвращаемс€ к чтению

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на землю (запись)
		
		// Ќоги на выход
		SETB HD44780U_D4_DDR, HD44780U_D4_bit
		SETB HD44780U_D5_DDR, HD44780U_D5_bit
		SETB HD44780U_D6_DDR, HD44780U_D6_bit
		SETB HD44780U_D7_DDR, HD44780U_D7_bit

		HD44780U_Delay_4_1ms							; задержка 4,1 мс

	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_BF_Check_act:								; подпрограмма провер€ет флаг зан€тости
	
		push r16										; вталкиваем r16 в STACK
		push r17										; вталкиваем r17 в STACK

		ldi		r16, 0x0A								; держим подсветку LCD на +5 и поднимаем RW на +5
		TWSI_Sending_byte r16							; отсылаем байт								
		ldi		r16, 0xFE								; держим подсветку LCD и RW на +5, ≈ и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
		TWSI_Sending_byte r16							; отсылаем байт	
		HD44780U_Delay_5mks								; задержка
		TWSI_START TWSI_Address, 'R'				; отсылаем START (рестартуем дл€ чтени€)
		TWSI_Reading_byte r17							; читаем байт из I2C в r17
		TWSI_NACK										; больше не принимаем байты
		TWSI_START TWSI_Address, 'W'				; отсылаем START (рестартуем дл€ записи)
		ldi		r16, 0x0A								; держим подсветку LCD на +5 и поднимаем RW на +5
		TWSI_Sending_byte r16							; отсылаем байт	
		ldi		r16, 0xFE								; держим подсветку LCD и RW на +5, ≈ и биты DB4-DB7 поднимаем на +5 (производим чтение из LCD)
		TWSI_Sending_byte r16							; отсылаем байт	
		HD44780U_Delay_5mks								; задержка
		ldi		r16, 0x0A								; держим подсветку LCD на +5 и RW на +5, остальное на 0
		TWSI_Sending_byte r16							; отсылаем байт
		ldi		r16, 0x08								; оставл€ем только подсветку LCD
		TWSI_Sending_byte r16							; отсылаем байт
		sbrc	r17, 7									; если седьмой бит равен 0, то пропускаем след строку
			rjmp	HD44780U_BF_Check_act				; переходим по метке

		pop r17											; выталкиваем r17 из STACK
		pop r16											; выталкиваем r16 из STACK
	ret													; выход из подпрограммы
#endif

