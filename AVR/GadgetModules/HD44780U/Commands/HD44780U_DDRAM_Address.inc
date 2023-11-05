/*
* ������ ������ ��������� ����������� ��� ��������� �������� ������ ���������
* ������� ����� ������ ������� �� �������
* ���������� ������� r23, r24, r25
*/
.macro HD44780U_DDRAM_Address	

	push r25

	lds r25, HD44780U_Entry_Mode_Set_byte

	.if @0 == HD44780U_ID_Increment
		SETRB r25, HD44780U_Bit_I.D						; ������������� � r25 HD44780U_Bit_I.D
	.elif @0 == HD44780U_ID_Decrement
		CLRRB r25, HD44780U_Bit_I.D						; ������������� � r25 HD44780U_Bit_I.D
	.endif

	WRITE_REG HD44780U_Entry_Mode_Set_byte, r25			; ���������� ��������� �������� � ������

	_call HD44780U_Send_instruction						; ���������� ����������

	pop r25

.endm