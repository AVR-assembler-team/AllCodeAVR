/*
* ������ ����� �� ������ I2C
* ��������� ���� �������� - ������� � ������� ���������� ������ ������������ TWDR
*/
.macro TWSI_ACK_Transmit
	ldi		r16, (1<<TWINT) | (1<<TWEN)	| (1<<TWEA)	; ��������� ������ ��� �������� ������ � TWDR
	WRITE_REG TWCR, r16						; ���������� �� ����
	TWSI_TWINT_Flag
.endm						; ����� �� ������������