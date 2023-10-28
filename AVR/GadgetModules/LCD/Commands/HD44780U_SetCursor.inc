/*
* ƒанный макрос используетс€ дл€ установки курсора в нужное положение на дисплее
* »спользует регистр r24, r25
*/
.macro HD44780U_Set_Cursor
	
	#ifdef HD44780U_LCD_Size_4x20
		.if @0 > 0 && @0 <= 4
			.if @1 > 0 && @1 <= 20
				ldi	r24, @0		
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
				ldi	r24, @0		
				ldi	r25, @1
			.else
				.error "Cursor position is not available!"
			.endif
		.else
			.error "Cursor position is not available!"
		.endif
	#endif

	_call HD44780U_SetCursor_act				; переходим

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_SetCursor_act:
#if defined HD44780U_LCD_Size_4x20 || HD44780U_LCD_2x16
	cpi		r24, 1								; сравниваем r24 с 1
	breq	FirstRow							; переходим если равны
												
	cpi		r24, 2								; сравниваем r24 с 2
	breq	SecondRow							; переходим если равны
												
	cpi		r24, 3								; сравниваем r24 с 3
	breq	ThirdRow							; переходим если равны
												
	cpi		r24, 4								; сравниваем r24 с 4
	breq	FourthRow							; переходим если равны

FirstRow:
	ldi		r24, 128 - 1					; записываем 127 в r24
	add		r25, r24						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем
												
SecondRow:									
	ldi		r24, 192 - 1					; записываем 191 в r24
	add		r25, r24						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем

ThirdRow:
	ldi		r24, 128 + $14 - 1				; записываем 147 в r24
	add		r25, r24						; суммируем r25 и r24
	rjmp	end								; перепрыгиваем

FourthRow:
	ldi		r24, 192 + $14 - 1				; записываем 211 в r24
	add		r25, r24						; суммируем r25 и r24

end:
	mov r24, r25							; копируем r25 в r24
	subi r24, $80							; вычитаем 128 из r24

#else
#endif

	WRITE_REG HD44780U_Address_DDRAM, r24	; записываем адрес курсора в HD44780U_Address_DDRAM

	_call HD44780U_Send_instruction				; отсылаем инструкцию
	
ret
