.macro PCF8575Read
	
	push r24
	ldi r24, @0

	TWSI_START									; �������� ������
	TWSI_SLA r24, 'R'							; ���������� ����� � ����� ������ 

	_call PCF8575Read_act

	pop r24

.endm

 PCF8575Read_act:

	push r25

	READ_REG TWSI_Flags, r25					; ��������� ������� ������
	sbrc r25, No_ACK							; ��������� ��� 
	_jump gotoPCF8575ReadLabels					; ���� ������, �� ���������

	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r25							; ������ ������ � TWDR
	WRITE_REG PCF8575Bytes, r25
	
	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r25							; ������ ������ � TWDR
	WRITE_REG PCF8575Bytes + 1, r25

	TWSI_Byte_Transmit							; ������ �� ��������� �����
	
	_jump PCF8575Read_end

gotoPCF8575ReadLabels:
	_call PCF8575_NoAck
	clr r25
	WRITE_REG PCF8575Bytes, r25
	WRITE_REG PCF8575Bytes + 1, r25

	PCF8575Read_end:
	TWSI_STOP

	pop r25

 ret

