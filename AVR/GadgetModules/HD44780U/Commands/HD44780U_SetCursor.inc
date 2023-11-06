/*
* Данный макрос используется для установки курсора в нужное положение на дисплее
*/

.macro HD44780U_Set_Cursor2

	push r25
	push r23

	#ifdef HD44780U_LCD_Size_4x20
		.if @0 > 0 && @0 <= 4
			.if @1 > 0 && @1 <= 20
				ldi	r23, @0		
				ldi	r25, @1
			.else
				.error "Cursor position is not available!"
			.endif
		.else
			.error "Cursor position is not available!"
		.endif
	#elif defined HD44780U_LCD_2x16
		.if @0 > 0 && @0 <= 2
			.if @1 > 0 && @1 <= 16
				ldi	r23, @0		
				ldi	r25, @1
			.else
				.error "Cursor position is not available!"
			.endif
		.else
			.error "Cursor position is not available!"
		.endif
	#endif

	_call HD44780U_SetCursor_act				; переходим

	pop r23
	pop r25

.endm
//____________________________________________________________________________________
.macro HD44780U_Set_Cursor
	
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @2
	#endif
	
	HD44780U_Set_Cursor2 @0, @1
	
	pop r24

.endm
//____________________________________________________________________________________
HD44780U_SetCursor_act:
#if defined HD44780U_LCD_Size_4x20 || HD44780U_LCD_2x16
	cpi		r23, 1								; сравниваем r24 с 1
	breq	FirstRow							; переходим если равны
												
	cpi		r23, 2								; сравниваем r24 с 2
	breq	SecondRow							; переходим если равны
												
	cpi		r23, 3								; сравниваем r24 с 3
	breq	ThirdRow							; переходим если равны
												
	cpi		r23, 4								; сравниваем r24 с 4
	breq	FourthRow							; переходим если равны

FirstRow:
	ldi		r23, 128 - 1					; записываем 127 в r24
	add		r25, r23						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем
												
SecondRow:									
	ldi		r23, 192 - 1					; записываем 191 в r24
	add		r25, r23						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем

ThirdRow:
	ldi		r23, 128 + $14 - 1				; записываем 147 в r24
	add		r25, r23						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем

FourthRow:
	ldi		r23, 192 + $14 - 1				; записываем 211 в r24
	add		r25, r23						; суммируем r25 и r24

end:
	mov r23, r25							; копируем r25 в r24
	subi r23, $80							; вычитаем 128 из r24

#else
#endif

	WRITE_REG HD44780U_Address_DDRAM, r23	; записываем адрес курсора в HD44780U_Address_DDRAM

	_call HD44780U_Send_instruction				; отсылаем инструкцию
	
ret
