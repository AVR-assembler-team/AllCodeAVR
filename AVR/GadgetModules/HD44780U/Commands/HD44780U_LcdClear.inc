/*
* ������ ������ ������������ ��� ������� ������� (������� �������� � ��������� 1, 1)
*/

.macro HD44780U_LCD_Clear
	
	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @0
	#endif

	ldi	r25, 0x01					; ���������� 1 � r25
	_call HD44780U_Send_instruction	; �������� ����������

	pop r24
	pop r25

.endm
