/*
* Данный макрос используется для вывода на дисплей символа
* из таблицы ASCII, заключенный в одиночные апострофы
*/					
.macro HD44780U_Write_Symbol

	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	ldi r25, @0
	_call HD44780U_Send_data				; отсылаем данные
	_call HD44780U_Address_DDRAM_Increment	; проверяем на окончание строки

	pop r24
	pop r25

.endm
