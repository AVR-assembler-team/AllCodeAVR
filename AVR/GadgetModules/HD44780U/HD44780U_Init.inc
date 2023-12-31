
.macro HD44780U_Init
	
	push r25
	push r24
	
	// ��������� ����� Function Set
	ldi r25, HD44780U_LCD_Function_Set
	#ifdef HD44780U_8_Wires
		SETRB r25, HD44780U_Bit_DL
	#endif
	#if defined HD44780U_LCD_Size_4x20 || HD44780U_LCD_2x16
		SETRB r25, HD44780U_Bit_N
	#endif
	#ifdef Character_Front_5x10
		SETRB r25, HD44780U_Bit_F
	#endif
	WRITE_REG HD44780U_Function_Set_byte, r25
	
	// ��������� ����� Display On/Off Control
	ldi r25, HD44780U_LCD_On_Off_Control
	#ifdef HD44780U_Display_On
		SETRB r25, HD44780U_Bit_D
	#endif
	#ifdef HD44780U_Cursor_On
		SETRB r25, HD44780U_Bit_C
	#endif
	#ifdef HD44780U_Cursor_Blinking_On
		SETRB r25, HD44780U_Bit_B
	#endif
	WRITE_REG HD44780U_Display_On_Off_Control_byte, r25
	
	// ��������� ����� Entry Mode Set
	ldi r25, HD44780U_LCD_Entry_Mode_Set
	#ifdef HD44780U_ID_Increment
		SETRB r25, HD44780U_Bit_I.D
	#endif
	#ifdef HD44780U_Display_Shift
		SETRB r25, HD44780U_Bit_Shift_Display
	#endif
	WRITE_REG HD44780U_Entry_Mode_Set_byte, r25
	
	// ��������� ����� Cursor or Display Shift
	ldi r25, HD44780U_Cursor_or_Display_Shift
	#ifdef HD44780U_Display_Shift
		SETRB r25, HD44780U_Bit_S.C
	#endif
	#ifdef HD44780U_Shift_to_the_Right
		SETRB r25, HD44780U_Bit_R.L
	#endif
	WRITE_REG HD44780U_Cursor_or_Display_Shift_byte, r25


	#ifdef HD44780U_TWSI
		ldi r24, @0
	#endif

	// ������ ������������� �������
	_call HD44780U_Initialization

	pop r24
	pop r25
	
.endm
