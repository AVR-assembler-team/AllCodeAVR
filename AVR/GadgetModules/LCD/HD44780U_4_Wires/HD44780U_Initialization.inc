/*
* Использует регистр r25
*/
HD44780U_Initialization:

	// устанавливаем все биты рабочего регистра на выход
	READ_REG HD44780U_D4_DDR, r25
	SETRB r25, HD44780U_D4_bit
	WRITE_REG HD44780U_D4_DDR, r25
	
	READ_REG HD44780U_D5_DDR, r25
	SETRB r25, HD44780U_D5_bit
	WRITE_REG HD44780U_D5_DDR, r25
	
	READ_REG HD44780U_D6_DDR, r25
	SETRB r25, HD44780U_D6_bit
	WRITE_REG HD44780U_D6_DDR, r25
	
	READ_REG HD44780U_D7_DDR, r25
	SETRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25
	
	READ_REG HD44780U_RS_DDR, r25
	SETRB r25, HD44780U_RS_bit
	WRITE_REG HD44780U_RS_DDR, r25
	
	READ_REG HD44780U_RW_DDR, r25
	SETRB r25, HD44780U_RW_bit
	WRITE_REG HD44780U_RW_DDR, r25
	
	READ_REG HD44780U_E_DDR, r25
	SETRB r25, HD44780U_E_bit
	WRITE_REG HD44780U_E_DDR, r25
												  
	HD44780U_Delay_15ms								; ждем более 15 мс
	ldi	r25, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			;устанавливаем на инструкции
	_call HD44780U_Command1

	HD44780U_Delay_4_1ms							; ждем более 4,1 мс
	ldi	r25, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			;устанавливаем на инструкции
	_call HD44780U_Command1

	HD44780U_Delay_100mks							; ждем более 100мкс
	ldi	r25, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			;устанавливаем на инструкции
	_call HD44780U_Command1

	_call HD44780U_BF_Check								; проверяем состояние флага занятости
												  
	ldi	r25, HD44780U_LCD_Function_Set				; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			;устанавливаем на инструкции
	_call HD44780U_Command1

	_call HD44780U_BF_Check								; проверяем состояние флага занятости
																	  
	READ_REG HD44780U_Function_Set_byte, r25				; Читаем Function Set в r16
	_call HD44780U_Send_instruction					; скармливаем инструкцию
		
	READ_REG HD44780U_Display_On_Off_Control_byte, r25	; Читаем Display On/Off Control в r16
	_call HD44780U_Send_instruction					; скармливаем инструкцию
																	  
	ldi r25, HD44780U_LCDClear						; настраиваем инструкцию Display clear
	_call HD44780U_Send_instruction					; скармливаем инструкцию
																	  
	READ_REG HD44780U_Entry_Mode_Set_byte, r25			; Читаем Entry Mode Set в r16
	_call HD44780U_Send_instruction					; скармливаем инструкцию
	HD44780U_Delay_15ms								; ждем более 15 мс

	READ_REG HD44780U_Cursor_or_display_shift, r25		; Читаем Cursor or display shift в r16
	_call HD44780U_Send_instruction					; скармливаем инструкцию
ret
