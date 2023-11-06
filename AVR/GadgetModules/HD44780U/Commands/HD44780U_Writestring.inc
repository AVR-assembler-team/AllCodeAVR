/*
* Данный макрос используется для вывода на дисплей строки из програмной памяти
* Не забываем данные регистра привести в соответствие с ASCII
*/
.macro HD44780U_Write_cseg_String
	
	push zh
	push zl
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	ldi	zh, high(@0*2)						; записываем старший байт адреса @0 в zh
	ldi	zl, low(@0*2)						; записываем младший байт адреса @0 в zl

	_call HD44780U_Write_cseg_String_act	; переходим

	pop r24
	pop zl
	pop zh

.endm
//------------------------------------------------------------------------------------
.macro HD44780U_Write_dseg_String
	
	push zh
	push zl
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif
	
	ldi	zh, high(@0)						; записываем старший байт адреса @0 в zh
	ldi	zl, low(@0)							; записываем младший байт адреса @0 в zl

	_call HD44780U_Write_dseg_String_act	; переходим

	pop r24
	pop zl
	pop zh

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_Write_cseg_String_act:

	push r22
	push r25

	lpm	r22, z+									; загружаем байт из z с пост-инкрементом в r22

	Typing_cseg_String:
		lpm	r25, z+								; загружаем байт из z с пост-инкрементом в r25
		_call HD44780U_Send_data				; r23, r24, r25 отсылаем данные
		_call HD44780U_Address_DDRAM_Increment	; r23, r24, r25  проверяем на окончание строки
		dec	r22									; уменьшаем r22 на 1
		brne Typing_cseg_String					; если не равно 0, то переходим

	pop r25
	pop r22

ret												; выход из подпрограммы
//------------------------------------------------------------------------------------
HD44780U_Write_dseg_String_act:

	push r22
	push r25

	ld	r22, z+									; загружаем байт из z с пост-инкрементом в r22

	Typing_dseg_String:
		ld	r25, z+								; загружаем байт из z с пост-инкрементом в r25
		_call HD44780U_Send_data				; r23, r24, r25 отсылаем данные
		_call HD44780U_Address_DDRAM_Increment	; r23, r24, r25 проверяем на окончание строки
		dec	r22									; уменьшаем r22 на 1
		brne Typing_dseg_String					; если не равно 0, то переходим

	pop r25
	pop r22

ret												; выход из подпрограммы
