/*
* ������ ������ ������������ ��� ������ �� ������� �������
* �� ������� ASCII, ����������� � ��������� ���������
*/					
.macro HD44780U_Write_Symbol

	push r25

	ldi r25, @0
	_call HD44780U_Send_data				; �������� ������
	_call HD44780U_Address_DDRAM_Increment	; ��������� �� ��������� ������

	pop r25

.endm