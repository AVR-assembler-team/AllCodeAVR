/*
* ���������� 2 ����� � ���
*/

.macro PCF8575Write
	
	push r24
	ldi r24, @0

	TWSI_START										; �������� ������
	TWSI_SLA r24, 'W'								; ���������� ����� � ����� ������

	_call PCF8575Write_act

	pop r24

.endm

PCF8575Write_act:
	
	push r25

	READ_REG TWSI_Flags, r25						; ��������� ������� ������
	sbrc r25, No_ACK								; ��������� ��� 
	_jump gotoPCF8575WriteLabels					; ���� ������, �� ���������
	
	READ_REG PCF8575Bytes, r25
	WRITE_REG TWDR, r25								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r25						; ��������� ������� ������
	sbrc r25, No_ACK								; ��������� ��� 
	_jump gotoPCF8575WriteLabels							; ���� ������, �� ���������
	
	READ_REG PCF8575Bytes + 1, r25
	WRITE_REG TWDR, r25								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r25						; ��������� ������� ������
	sbrc r25, No_ACK								; ��������� ��� 
		_jump gotoPCF8575WriteLabels				; ���� ������, �� ���������
		_jump PCF8575Write_end

gotoPCF8575WriteLabels:
	_call PCF8575_NoAck

PCF8575Write_end:
	TWSI_STOP

	pop r25

ret
