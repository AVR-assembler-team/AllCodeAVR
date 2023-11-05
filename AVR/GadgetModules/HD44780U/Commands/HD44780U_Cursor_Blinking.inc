/*
* ������ ������ �������� ��� ��������� ������� �������
*/
.macro HD44780U_Cursor_Blinking
	
	push r25
	
	lds r25, HD44780U_Display_On_Off_Control_byte

	.if @0 == On
		SETRB r25, HD44780U_Bit_B						; ������������� � r25 HD44780U_Bit_B
	.elif @0 == Off
		CLRRB r25, HD44780U_Bit_B						; ������������� � r25 HD44780U_Bit_B
	.endif

	WRITE_REG HD44780U_Display_On_Off_Control_byte, r25	; ���������� ��������� �������� � ������

	_call HD44780U_Send_instruction						; ���������� ����������

	pop r25

.endm