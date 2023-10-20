.macro PCF8575Read
	push r18
	push r19
	ldi r18, @0
	_call PCF8575Read_act
	WRITE_REG @1, r18					; ���������� � ������
	WRITE_REG @2, r19					; ���������� � ������
	pop r19
	pop r18

.endm

 PCF8575Read_act:

	TWSI_START									; �������� ������
	TWSI_SLA r18, 'R'							; ���������� ����� � ����� ������ 

	READ_REG TWSI_Flags, r18					; ��������� ������� ������
	sbrc r18, No_ACK							; ��������� ��� 
	_jump gotoPCF8575ReadLabels						; ���� ������, �� ���������

	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r18							; ������ ������ � TWDR
	
	
	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r19							; ������ ������ � TWDR
	

	TWSI_Byte_Transmit							; ������ �� ��������� �����
	
	TWSI_STOP
	_jump PCF8575Read_end

	gotoPCF8575ReadLabels:
		_call PCF8575_NoAck
		clr r18
		clr r19

	PCF8575Read_end:
 ret
