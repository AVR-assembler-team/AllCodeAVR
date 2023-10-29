/*
* ������ ������ ��������� ���� ��������� �������
* ���������� ������� r25
*/

HD44780U_BF_Check:

	READ_REG HD44780U_D7_DDR, r25
	CLRRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25

	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ����������� �� ����������
	sbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� + (������)

HD44780U_Read_bit:
	sbi	HD44780U_E_PORT, HD44780U_E_bit				; �������� ������
	HD44780U_Delay_5mks								; �������� 5 ���
	sbis HD44780U_D7_PIN, HD44780U_D7_bit			; ��������� ��������� ���� ��� D7
		_jump HD44780U_Busy_Flag_End					; ���� ����� ���, �� ���������

HD44780U_Busy_Flag_Again:
	cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
	HD44780U_Delay_5mks								; �������� 5 ���
	_jump HD44780U_Read_bit							; ���� ������� ��� ��� D7 �� ������������ � ������

HD44780U_Busy_Flag_End:
	cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
	cbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� ����� (������)
		
	READ_REG HD44780U_D7_DDR, r25
	SETRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25

	HD44780U_Delay_4_1ms							; �������� 4,1 ��

ret