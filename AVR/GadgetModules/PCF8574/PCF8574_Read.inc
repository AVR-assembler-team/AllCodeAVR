.macro PCF8574Read
	
	push r24
	ldi r24, @0

	TWSI_START									; �������� ������
	TWSI_SLA r24, 'R'							; ���������� ����� � ����� ������ 

	_call PCF8574_Read_act

	pop r24

.endm

 PCF8574_Read_act:

	push r25

	READ_REG TWSI_Flags, r25					; ��������� ������� ������
	sbrc r25, No_ACK							; ��������� ��� 
	_jump gotoPCF8574ReadLabels					; ���� ������, �� ���������

	TWSI_Byte_Transmit							; ������ �� ��������� �����

	READ_REG TWDR, r25							; ������ ������ � TWDR
	WRITE_REG PCF8574Bytes, r25
	
	TWSI_ACK_Transmit							; ���������� ACK
		
	_jump PCF8574_Read_end

	gotoPCF8574ReadLabels:
		_call PCF8574_NoAck
		clr r25
		WRITE_REG PCF8574Bytes, r25

	PCF8574_Read_end:
	TWSI_STOP

	pop r25

 ret

