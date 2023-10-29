/*
* AVR Modules
*/

.include "Main/Includes.inc"
///////////////////////////////////////////////////////////////////////
Reset:
.include "Reset.inc"

Proga:
// Читайте README файл
// Ваша программа
	
rjmp Proga

Button0:
	READ_REG PINB, r16
	sbrc r16, 2
		_jump CommandCreateAndS
		_jump CommandCreateAnd
ret

CommandCreateAndS:
	ldi r16, $40
	//HD44780U_Write_Register r16
	HD44780U_LCD_LED Off
	//HD44780U_Write_Symbol 'a'
	//HD44780U_Set_Cursor 1, 3
ret
CommandCreateAnd:
	//HD44780U_LCD_Clear
	HD44780U_LCD_LED On
ret

