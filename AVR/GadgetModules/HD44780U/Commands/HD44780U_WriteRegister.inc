/*
* Данный макрос используется для вывода на дисплей символа из регистра.
* Не забываем данные регистра привести в соответствие с ASCII
*/
.macro HD44780U_Write_Register

	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif
	
	mov r25, @0
	_call HD44780U_Send_data				; отсылаем данные
	_call HD44780U_Address_DDRAM_Increment	; проверяем на окончание строки
	
	pop r24
	pop r25

.endm
