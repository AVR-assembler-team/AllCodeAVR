
.macro HD44780U_Init
	//clr r25
	//#ifdef HD44780U_8_Wires
	//#elif defined HD44780U_4_Wires
	//	SETRB r25, Connection_bit_1
	//#elif defined HD44780U_TWSI
	//	SETRB r25, Connection_bit_0
	//	SETRB r25, Connection_bit_1
	//#endif
	//WRITE_REG HD44780U_flags, r25

	_call HD44780U_Function_set
	_call HD44780U_Display_on_off_control
	_call HD44780U_Entry_mode_set
	_call HD44780U_Cursor_Display_shift

	_call HD44780U_Initialization
.endm
