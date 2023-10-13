/*
* Настройка конфигурационных файлов при инициализации дисплея
*/

.macro HD44780U_Set_byte1	;устанавливаем биты в инструкции в соответствии с настройками
	.if HD44780U_Lines == 1				
		CLRRB r16, HD44780U_Bit_N
	.elif HD44780U_Lines == 2
		SETRB r16, HD44780U_Bit_N
	.endif
	.if HD44780U_Symbols == 8
		CLRRB r16, HD44780U_Bit_F
	.elif HD44780U_Symbols == 10
		SETRB r16, HD44780U_Bit_F
	.endif
.endm
;-------------------------------------
.macro HD44780U_Set_byte2	;устанавливаем биты в инструкции в соответствии с настройками
	.if HD44780U_Display_On == HD44780U_D_On		
		SETRB r16, HD44780U_Bit_D
	.elif HD44780U_Display_On == HD44780U_D_Off
		CLRRB r16, HD44780U_Bit_D
	.endif
	.if HD44780U_Cursor_Vis == HD44780U_C_On
		SETRB r16, HD44780U_Bit_C
	.elif HD44780U_Cursor_Vis == HD44780U_C_Off
		CLRRB r16, HD44780U_Bit_C
	.endif
	.if HD44780U_Cursor_Blink == HD44780U_B_On
		SETRB r16, HD44780U_Bit_B
	.elif HD44780U_Cursor_Blink == HD44780U_B_Off
		CLRRB r16, HD44780U_Bit_B
	.endif
.endm
;-------------------------------------
.macro HD44780U_Set_byte3	;устанавливаем биты в инструкции в соответствии с настройками
	.if HD44780U_DDRAM == HD44780U_ID_Increment			
		SETRB r16, HD44780U_Bit_I.D
	.elif HD44780U_DDRAM == HD44780U_ID_Decrement
		CLRRB r16, HD44780U_Bit_I.D
	.endif
	.if HD44780U_Display_or_Cursor == HD44780U_Display
		SETRB r16, HD44780U_Bit_Shift_Display
	.elif HD44780U_Display_or_Cursor == HD44780U_Cursor
		CLRRB r16, HD44780U_Bit_Shift_Display
	.endif
.endm
