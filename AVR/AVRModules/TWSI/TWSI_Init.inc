/*
* ������������� ������ ������ I2C
* ���������� ������� r25
*/
.macro TWSI_init

	push r25

	ldi	r25, ((ATmegaFREQ/FreqSCL)-16)/8	;������ ������� �������� �� I2C, � ������� ����������� ������� TWPS == 0
	WRITE_REG TWBR, r25						;���������� ������ � ������� ��� I2C

	pop r25

.endm

