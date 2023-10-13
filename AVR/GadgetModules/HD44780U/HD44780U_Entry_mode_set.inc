/*
* Устанавливает/очищает биты инкремента/дикремента адреса курсора или
* дисплея в конфигурационный байт дисплея
*/

.macro HD44780U_Entry_mode_set
	ldi r16, HD44780U_LCD_Entry_Mode_Set
	#ifdef HD44780U_ID_Increment
		SETRB r16, HD44780U_Bit_I.D
	#endif
	#ifdef HD44780U_Display_Shift
		SETRB r16, HD44780U_Bit_Shift_Display
	#endif
	sts HD44780U_Entry_Mode_Set_byte, r16
.endm
