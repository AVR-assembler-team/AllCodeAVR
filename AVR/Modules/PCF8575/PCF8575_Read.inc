.macro PCF8575_Read
	push r18
	ldi r18, @0
	_call PCF8575_Read_act
	pop r18

.endm

 PCF8575_Read_act:

	TWSI_START									; �������� ������
	TWSI_SLA r18, 'R'							; ���������� ����� � ����� ������ 

	READ_REG TWSI_Flags, r18					; ��������� ������� ������
	sbrc r18, No_ACK							; ��������� ��� 
	_jump gotoReadLabels						; ���� ������, �� ���������

	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r18							; ������ ������ � TWDR
	WRITE_REG PCF8575_Data, r18					; ���������� � ������
	
	TWSI_ACK_Transmit							; ���������� ACK

	READ_REG TWDR, r18							; ������ ������ � TWDR
	WRITE_REG PCF8575_Data + 1, r18				; ���������� � ������
	
	TWSI_STOP
	_jump PCF8575_Read_end

	gotoReadLabels:
		_call PCF8575_NoAck

	PCF8575_Read_end:
 ret
