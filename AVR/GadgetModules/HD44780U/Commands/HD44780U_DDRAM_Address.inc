/*
* ������ ������ ��������� ����������� ��� ��������� �������� ������ ���������
* ������� ����� ������ ������� �� �������
*/
.macro HD44780U_DDRAM_Address	

	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	lds r25, HD44780U_Entry_Mode_Set_byte

	.if @0 == HD44780U_ID_Increment
		SETRB r25, HD44780U_Bit_I.D						; ������������� � r25 HD44780U_Bit_I.D
	.elif @0 == HD44780U_ID_Decrement
		CLRRB r25, HD44780U_Bit_I.D						; ������������� � r25 HD44780U_Bit_I.D
	.endif

	WRITE_REG HD44780U_Entry_Mode_Set_byte, r25			; ���������� ��������� �������� � ������

	_call HD44780U_Send_instruction						; ���������� ����������

	pop r24
	pop r25

.endm
