/*
* �������� ���������� �������
* ���������� ������� r23, r24, r25
*/
HD44780U_Send_instruction:

	push r25

	TWSI_START								; �������� START (���������� ��� ������)
	TWSI_SLA r24, 'W'
	_call HD44780U_Send_instr_byte_high		; ��������� �� �����
	_call HD44780U_Send_instr_byte_low		; ��������� �� �����
	TWSI_STOP								; �������� START (���������� ��� ������)

	pop r25

ret											; ����� �� ������������
