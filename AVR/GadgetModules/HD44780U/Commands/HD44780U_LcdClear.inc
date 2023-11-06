/*
* Данный макрос используется для очистки дисплея (каретка вернется в положение 1, 1)
*/

.macro HD44780U_LCD_Clear
	
	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @0
	#endif

	ldi	r25, 0x01					; записываем 1 в r25
	_call HD44780U_Send_instruction	; отсылаем инструкцию

	pop r24
	pop r25

.endm
