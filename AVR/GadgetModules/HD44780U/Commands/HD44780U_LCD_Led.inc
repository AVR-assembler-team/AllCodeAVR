/*
* ƒанный макрос используетс€ дл€ управлени€ работой подсветки диспле€
*/

.macro HD44780U_LCD_LED

	#if defined HD44780U_8_Wires || HD44780U_4_Wires

		.if @0 == On
			SETB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.elif @0 == Off
			CLRB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.endif

	#elif defined HD44780U_TWSI

		push r25

		TWSI_START										; отсылаем START (рестартуем дл€ записи)
		TWSI_SLA HD44780U_SLA_, 'W'						; 
	
		.if @0 == On
			ldi r25, (1<<HD44780U_LCD_LIGHT)			; устанавливаем в r25 бит HD44780U_LCD_LIGHT в 1
		.elif @0 == Off
			clr r25										; очищаем r25
		.endif
		
		WRITE_REG TWDR, r25								; ¬талкиваем в дата регистр
		TWSI_Byte_Transmit								; ќтправл€ем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ѕровер€ем получен ли ответ

		TWSI_STOP										; 

		pop r25

	#endif


.endm
