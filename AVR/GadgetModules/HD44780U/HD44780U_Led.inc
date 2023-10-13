/*
* Данный макрос используется для управления работой подсветки дисплея
*/
.macro HD44780U_LCD_LED

	#if defined HD44780U_8_Wires || HD44780U_4_Wires

		.if @0 == On
			SETB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.elif @0 == Off
			CLRB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.endif

	#elif defined HD44780U_TWSI

		push r16									; вталкиваем r16 в STACK

		.if @0 == enabled
			ldi r16, (1<<HD44780U_LCD_LIGHT)		; устанавливаем в r16 бит HD44780U_LCD_LIGHT в 1
			SETB HD44780U_flags, HD44780U_LCD_LIGHT	; устанавливаем в регистре флагов HD44780U_LCD_LIGHT в 1
		.elif @0 == disabled
			clr r16									; очищаем r16
			CLRB HD44780U_flags, HD44780U_LCD_LIGHT	; устанавливаем в регистре флагов HD44780U_LCD_LIGHT в 0
		.endif

		TWSI_Sending_byte r16						; отправляем байт в I2C

		pop r16										; выталкиваем r16 из STACK

	#endif

.endm
