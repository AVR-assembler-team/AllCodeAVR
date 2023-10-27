/*
* Устанавливает/очищает биты инкремента/дикремента адреса курсора или
* дисплея в конфигурационный байт дисплея
*/

//.macro HD44780U_Entry_mode_set
HD44780U_Entry_mode_set:
	ldi r25, HD44780U_LCD_Entry_Mode_Set
	#ifdef HD44780U_ID_Increment
		SETRB r25, HD44780U_Bit_I.D
	#endif
	#ifdef HD44780U_Display_Shift
		SETRB r25, HD44780U_Bit_Shift_Display
	#endif
	WRITE_REG HD44780U_Entry_Mode_Set_byte, r25
ret //.endm
