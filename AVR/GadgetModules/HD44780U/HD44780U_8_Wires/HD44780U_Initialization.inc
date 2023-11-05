
HD44780U_Initialization:

	push r25

	// устанавливаем все биты рабочего регистра на выход
	SETB HD44780U_D0_DDR, HD44780U_D0_bit
	SETB HD44780U_D1_DDR, HD44780U_D1_bit
	SETB HD44780U_D2_DDR, HD44780U_D2_bit
	SETB HD44780U_D3_DDR, HD44780U_D3_bit
	SETB HD44780U_D4_DDR, HD44780U_D4_bit
	SETB HD44780U_D5_DDR, HD44780U_D5_bit
	SETB HD44780U_D6_DDR, HD44780U_D6_bit
	SETB HD44780U_D7_DDR, HD44780U_D7_bit
	SETB HD44780U_RS_DDR, HD44780U_RS_bit
	SETB HD44780U_RW_DDR, HD44780U_RW_bit
	SETB HD44780U_E_DDR, HD44780U_E_bit
	
	HD44780U_Delay_15ms									; ждем более 15 мс
	ldi	r25, $30										; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; устанавливаем на инструкции
	_call HD44780U_Command								; r25 HD44780U_SendInstruction.inc
	
	HD44780U_Delay_4_1ms								; ждем более 4,1 мс
	ldi	r25, $30										; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; устанавливаем на инструкции
	_call HD44780U_Command								; r25 HD44780U_SendInstruction.inc
	
	HD44780U_Delay_100mks								; ждем более 100мкс
	ldi	r25, $30										; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; устанавливаем на инструкции
	_call HD44780U_Command								; r25 HD44780U_SendInstruction.inc

	_call HD44780U_BF_Check								; r25 проверяем состояние флага занятости

	READ_REG HD44780U_Function_Set_byte, r25			; Читаем Function Set в r16
	_call HD44780U_Send_instruction						; r25 скармливаем инструкцию

	READ_REG HD44780U_Display_On_Off_Control_byte, r25	; Читаем Display On/Off Control в r16
	_call HD44780U_Send_instruction						; r25 скармливаем инструкцию
												  
	ldi r25, HD44780U_LCDClear							; настраиваем инструкцию Display clear
	_call HD44780U_Send_instruction						; r25 скармливаем инструкцию

	READ_REG HD44780U_Entry_Mode_Set_byte, r25			; Читаем Entry Mode Set в r16
	_call HD44780U_Send_instruction						; r25 скармливаем инструкцию

	READ_REG HD44780U_Cursor_or_display_shift, r25		; Читаем Cursor or display shift в r16
	_call HD44780U_Send_instruction						; r25 скармливаем инструкцию

	pop r25

ret
