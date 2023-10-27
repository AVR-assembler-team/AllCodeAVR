/*
* Данный макрос используется для установки курсора в нужное положение на дисплее
*/
.macro HD44780U_Set_Cursor

	ldi	r24, @0						; записываем @0 в r24
	ldi	r25, @1						; записываем @1 в r25

	_call HD44780U_SetCursor_act	; переходим

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_SetCursor_act:

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
		WRITE_REG HD44780U_Address_DDRAM, r24	; записываем адрес курсора в HD44780U_Address_DDRAM

	#ifdef HD44780U_TWSI
		push r25
		TWSI_START								; отсылаем START (рестартуем для записи)
		TWSI_SLA HD44780U_SLA_, 'W'
		pop r25
	#endif

	_call HD44780U_Send_instruction				; отсылаем инструкцию
	
	#ifdef HD44780U_TWSI
		TWSI_STOP								; отсылаем START (рестартуем для записи)
	#endif
ret
