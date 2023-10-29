/*
* ������ ������ ��������� ���� ��������� �������
* ���������� ������� r25
*/
HD44780U_BF_Check:								; ������������ ��������� ���� ���������
	
	push r25										; ���������� r16 � STACK
	push r24										; ���������� r17 � STACK

	ldi		r25, 0xFA								; ������ ��������� LCD � RW �� +5, � � ���� DB4-DB7 ��������� �� +5 (���������� ������ �� LCD)
	WRITE_REG TWDR, r25								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	TWSI_STOP

	TWSI_START 										; �������� START (���������� ��� ������)

	TWSI_SLA HD44780U_SLA_, 'R'

HD44780U_BF_Check_act_1:

	READ_REG TWDR, r24								; ������ ���� �� I2C � r17
	sbrc	r24, 7									; ���� ������� ��� ����� 0, �� ���������� ���� ������
		_jump	HD44780U_BF_Check_act_1				; ��������� �� �����
		
	TWSI_STOP										; ������ �� ��������� �����
	TWSI_START										; �������� START (���������� ��� ������)

	TWSI_SLA HD44780U_SLA_, 'W'

	ldi		r25, 0x08								; ��������� ������ ��������� LCD
	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����


	pop r24											; ����������� r17 �� STACK
	pop r25											; ����������� r16 �� STACK
ret													; ����� �� ������������