/*
* ������ ������ ������������ ��� ��������� ������� � ������ ��������� �� �������
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

	_call HD44780U_SetCursor_act				; ���������

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
	cpi		r23, 1								; ���������� r24 � 1
	breq	FirstRow							; ��������� ���� �����
												
	cpi		r23, 2								; ���������� r24 � 2
	breq	SecondRow							; ��������� ���� �����
												
	cpi		r23, 3								; ���������� r24 � 3
	breq	ThirdRow							; ��������� ���� �����
												
	cpi		r23, 4								; ���������� r24 � 4
	breq	FourthRow							; ��������� ���� �����

FirstRow:
	ldi		r23, 128 - 1					; ���������� 127 � r24
	add		r25, r23						; ��������� r25 � r24
	rjmp	end								; �������������
												
SecondRow:									
	ldi		r23, 192 - 1					; ���������� 191 � r24
	add		r25, r23						; ��������� r25 � r24
	rjmp	end								; �������������

ThirdRow:
	ldi		r23, 128 + $14 - 1				; ���������� 147 � r24
	add		r25, r23						; ��������� r25 � r24
	rjmp	end								; �������������

FourthRow:
	ldi		r23, 192 + $14 - 1				; ���������� 211 � r24
	add		r25, r23						; ��������� r25 � r24

end:
	mov r23, r25							; �������� r25 � r24
	subi r23, $80							; �������� 128 �� r24

#else
#endif

	WRITE_REG HD44780U_Address_DDRAM, r23	; ���������� ����� ������� � HD44780U_Address_DDRAM

	_call HD44780U_Send_instruction				; �������� ����������
	
ret
