/*
* Данные макрос включает или выключает отображение курсора
* Использует регистр r23, r24, r25
*/
.macro HD44780U_Cursor_visible
	lds r25, HD44780U_Display_On_Off_Control_byte

	.if @0 == On
		SETRB r25, HD44780U_Bit_C						; устанавливаем в r25 HD44780U_Bit_C
	.elif @0 == Off
		CLRRB r25, HD44780U_Bit_C						; устанавливаем в r25 HD44780U_Bit_C
	.endif

	WRITE_REG HD44780U_Display_On_Off_Control_byte, r25

	_call HD44780U_Send_instruction						; r23, r24, r25 отсылаем инструкцию
.endm