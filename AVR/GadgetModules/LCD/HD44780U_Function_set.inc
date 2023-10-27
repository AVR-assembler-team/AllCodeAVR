/*
* Устанавливает/очищает биты количества проводов подключения дисплея,
* количество строк дисплея и размера символов в конфигурационный байт дисплея
*/

//.macro HD44780U_Function_set
HD44780U_Function_set:
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
ret //.endm 
