/*
* Данные макрос переключает между сдвигом курсора и дисплея
* Использует регистр r23, r24, r25
*/
.macro HD44780U_Shift	
	lds r25, HD44780U_Entry_Mode_Set_byte

	.if @0 == HD44780U_Display
		SETRB r25, HD44780U_Bit_Shift_Display	; устанавливаем в r25 HD44780U_Bit_Shift_Display
	.elif @0 == HD44780U_Cursor
		CLRRB r25, HD44780U_Bit_Shift_Display	; устанавливаем в r25 HD44780U_Bit_Shift_Display
	.endif

	WRITE_REG HD44780U_Entry_Mode_Set_byte, r25

	_call HD44780U_Send_instruction				; r23, r24, r25 отсылаем инструкцию
.endm