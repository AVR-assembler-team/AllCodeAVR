/*
* Устанавливает/очищает бит выбора сдвига курсора иди экрана в конфигурационный байт дисплея
*/
.macro HD44780U_Cursor_Display_shift
	ldi r25, HD44780U_Cursor_or_Display_Shift
	#ifdef HD44780U_Display_Shift
		SETRB r16, HD44780U_Bit_S.C
	#endif
	#ifdef HD44780U_Shift_to_the_Right
		SETRB r16, HD44780U_Bit_R.L
	#endif
	WRITE_REG HD44780U_Cursor_or_Display_Shift_byte, r16
.endm

