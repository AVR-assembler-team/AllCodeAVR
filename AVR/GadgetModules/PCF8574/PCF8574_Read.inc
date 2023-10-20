.macro PCF8574_Read
	push r18
	ldi r18, @0
	_call PCF8574_Read_act
	WRITE_REG @1, r18					; ���������� � ������
	pop r18

.endm

 PCF8574_Read_act:

	TWSI_START									; �������� ������
	TWSI_SLA r18, 'R'							; ���������� ����� � ����� ������ 

	READ_REG TWSI_Flags, r18					; ��������� ������� ������
	sbrc r18, No_ACK							; ��������� ��� 
	_jump gotoPCF8574ReadLabels						; ���� ������, �� ���������

	TWSI_Byte_Transmit							; ������ �� ��������� �����

	READ_REG TWDR, r18							; ������ ������ � TWDR
	
	TWSI_ACK_Transmit							; ���������� ACK
		
	TWSI_STOP
	_jump PCF8574_Read_end

	gotoPCF8574ReadLabels:
		_call PCF8574_NoAck
		clr r18

	PCF8574_Read_end:
 ret
