/*
* ������ ������ ��������� ���� ��������� �������
*/
HD44780U_BF_Check:									; ������������ ��������� ���� ���������

	push r25

	ldi		r25, 0xFA								; ������ ��������� LCD � RW �� +5, � � ���� DB4-DB7 ��������� �� +5 (���������� ������ �� LCD)
	WRITE_REG TWDR, r25								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	TWSI_STOP

	TWSI_START 										; �������� START (���������� ��� ������)

	TWSI_SLA r24, 'R'

HD44780U_BF_Check_act_1:

	READ_REG TWDR, r25								; ������ ���� �� I2C � r25
	sbrc	r25, 7									; ���� ������� ��� ����� 0, �� ���������� ���� ������
		_jump	HD44780U_BF_Check_act_1				; ��������� �� �����
		
	TWSI_STOP										; ������ �� ��������� �����
	TWSI_START										; �������� START (���������� ��� ������)

	TWSI_SLA r24, 'W'

	ldi		r25, 0x08								; ��������� ������ ��������� LCD
	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	pop r25

ret													; ����� �� ������������
