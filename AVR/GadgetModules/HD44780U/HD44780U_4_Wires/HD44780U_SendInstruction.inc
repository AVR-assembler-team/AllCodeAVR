/*
* �������� ���������� �������
*/

HD44780U_Send_instruction:
	cbi HD44780U_RS_PORT, HD44780U_RS_bit						; ������������� �� ����������
	_call HD44780U_Command1										; r25
	HD44780U_Delay_5mks											; �������� 5 ���

	_call HD44780U_Command2										; r25
	HD44780U_Delay_20mks										; �������� 20 ���
	HD44780U_Delay_20mks										; �������� 20 ���
ret																; ����� �� ������������
