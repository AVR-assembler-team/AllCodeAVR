/*
* ������ ������ ��������� ���� ��������� �������
*/

HD44780U_BF_Check:							; �������� ��������� ����� ���������

	CLRB HD44780U_D7_DDR, HD44780U_D7_bit

	cbi HD44780U_RS_PORT, HD44780U_RS_bit	; ����������� �� ����������
	sbi HD44780U_RW_PORT, HD44780U_RW_bit	; ������������ RW �� + (������)

HD44780U_Read_bit:
	sbi	HD44780U_E_PORT, HD44780U_E_bit		; �������� ������
	HD44780U_Delay_5mks						; �������� 5 ���
	sbis HD44780U_D7_PIN, HD44780U_D7_bit	; ��������� ��������� ���� ��� D7
		_jump HD44780U_Busy_Flag_End		; ���� ����� ���, �� ���������

HD44780U_Busy_Flag_Again:
	cbi	HD44780U_E_PORT, HD44780U_E_bit		; ����������� ������
	HD44780U_Delay_5mks						; �������� 5 ���
	_jump HD44780U_Read_bit					; ���� ������� ��� ��� D7 �� ������������ � ������

HD44780U_Busy_Flag_End:
	cbi	HD44780U_E_PORT, HD44780U_E_bit		; ����������� ������
	cbi HD44780U_RW_PORT, HD44780U_RW_bit	; ������������ RW �� ����� (������)

	SETB HD44780U_D7_DDR, HD44780U_D7_bit

ret											; ����� �� ������������
