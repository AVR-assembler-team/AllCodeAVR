/*
* ������ ������ ������������ ��� ������ �� ������� �������
* �� ������� ASCII, ����������� � ��������� ���������
*/					
.macro HD44780U_Write_Symbol

	push r25
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	ldi r25, @0
	_call HD44780U_Send_data				; �������� ������
	_call HD44780U_Address_DDRAM_Increment	; ��������� �� ��������� ������

	pop r24
	pop r25

.endm
