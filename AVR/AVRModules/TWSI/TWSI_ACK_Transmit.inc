/*
* ������ ����� �� ������ I2C
* ��������� ���� �������� - ������� � ������� ���������� ������ ������������ TWDR
*/
.macro TWSI_ACK_Transmit
	push r16
	ldi		r16, (1<<TWINT) | (1<<TWEN)	| (1<<TWEA)	; ��������� ������ ��� �������� ������ � TWDR
	WRITE_REG TWCR, r16						; ���������� �� ����
	TWSI_TWINT_Flag
	pop r16
.endm						; ����� �� ������������