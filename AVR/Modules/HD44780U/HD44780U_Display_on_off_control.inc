/*
* Устанавливает/очищает биты включения/выключения дисплея, курсора 
* и мигания курсора в конфигурационный байт дисплея
*/

.macro HD44780U_Display_on_off_control
	ldi r16, HD44780U_LCD_On_Off_Control
	#ifdef HD44780U_Display_On
		SETRB r16, HD44780U_Bit_D
	#endif
	#ifdef HD44780U_Cursor_On
		SETRB r16, HD44780U_Bit_C
	#endif
	#ifdef HD44780U_Cursor_Blinking_On
		SETRB r16, HD44780U_Bit_B
	#endif
	sts HD44780U_Display_On_Off_Control_byte, r16
.endm 
