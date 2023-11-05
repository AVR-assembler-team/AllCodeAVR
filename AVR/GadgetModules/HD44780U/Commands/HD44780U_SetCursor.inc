/*
* ������ ������ ������������ ��� ��������� ������� � ������ ��������� �� �������
*/

.macro HD44780U_Set_Cursor
	
	push r25
	push r24

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

	_call HD44780U_SetCursor_act				; ���������

	pop r24
	pop r25

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_SetCursor_act:
#if defined HD44780U_LCD_Size_4x20 || HD44780U_LCD_2x16
	cpi		r24, 1								; ���������� r24 � 1
	breq	FirstRow							; ��������� ���� �����
												
	cpi		r24, 2								; ���������� r24 � 2
	breq	SecondRow							; ��������� ���� �����
												
	cpi		r24, 3								; ���������� r24 � 3
	breq	ThirdRow							; ��������� ���� �����
												
	cpi		r24, 4								; ���������� r24 � 4
	breq	FourthRow							; ��������� ���� �����

FirstRow:
	ldi		r24, 128 - 1					; ���������� 127 � r24
	add		r25, r24						; ��������� r25 � r24
	rjmp	end								; �������������
												
SecondRow:									
	ldi		r24, 192 - 1					; ���������� 191 � r24
	add		r25, r24						; ��������� r25 � r24
	rjmp	end								; �������������

ThirdRow:
	ldi		r24, 128 + $14 - 1				; ���������� 147 � r24
	add		r25, r24						; ��������� r25 � r24
	rjmp	end								; �������������

FourthRow:
	ldi		r24, 192 + $14 - 1				; ���������� 211 � r24
	add		r25, r24						; ��������� r25 � r24

end:
	mov r24, r25							; �������� r25 � r24
	subi r24, $80							; �������� 128 �� r24

#else
#endif

	WRITE_REG HD44780U_Address_DDRAM, r24	; ���������� ����� ������� � HD44780U_Address_DDRAM

	_call HD44780U_Send_instruction				; �������� ����������
	
ret