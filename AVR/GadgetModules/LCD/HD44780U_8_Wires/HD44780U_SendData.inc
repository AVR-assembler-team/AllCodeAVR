/*
* �������� ������ �������
* ��������� ���� ��������� - ������� � ������� ��� ��������
* ���������� ������� r25
*/
HD44780U_Send_data:
	sbi HD44780U_RS_PORT, HD44780U_RS_bit	; ������������� �� �������
	_call HD44780U_Command
	HD44780U_Delay_20mks					; �������� 20 ���
	HD44780U_Delay_20mks					; �������� 20 ���
ret