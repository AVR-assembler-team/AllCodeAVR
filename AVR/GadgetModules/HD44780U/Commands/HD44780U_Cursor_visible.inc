/*
* ������ ������ �������� ��� ��������� ����������� �������
*/
.macro HD44780U_Cursor_visible

	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	lds r25, HD44780U_Display_On_Off_Control_byte

	.if @0 == On
		SETRB r25, HD44780U_Bit_C						; ������������� � r25 HD44780U_Bit_C
	.elif @0 == Off
		CLRRB r25, HD44780U_Bit_C						; ������������� � r25 HD44780U_Bit_C
	.endif

	WRITE_REG HD44780U_Display_On_Off_Control_byte, r25 ; ���������� ��������� �������� � ������

	_call HD44780U_Send_instruction						; ���������� ����������

	pop r24
	pop r25

.endm