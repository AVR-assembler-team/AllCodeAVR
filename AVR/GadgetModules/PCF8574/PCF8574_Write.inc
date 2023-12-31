/*
* ���������� ���� � ���
*/

.macro PCF8574Write

	push r24
	ldi r24, @0

	TWSI_START										; �������� ������
	TWSI_SLA r24, 'W'								; ���������� ����� � ����� ������

	_call PCF8574_Write_act

	pop r24

.endm

PCF8574_Write_act:
	
	push r25

	READ_REG TWSI_Flags, r25						; ��������� ������� ������
	sbrc r25, No_ACK								; ��������� ��� 
	_jump gotoPCF8574WriteLabels					; ���� ������, �� ���������

	READ_REG PCF8574Bytes, r25
	WRITE_REG TWDR, r25								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r25						; ��������� ������� ������
	sbrc r25, No_ACK								; ��������� ��� 
		_jump gotoPCF8574WriteLabels				; ���� ������, �� ���������
		_jump PCF8574_Write_end

gotoPCF8574WriteLabels:
	_call PCF8574_NoAck

PCF8574_Write_end:
	TWSI_STOP

	pop r25

ret
