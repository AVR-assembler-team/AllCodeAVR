/*
* ���������� 2 ����� � ���
*/

.macro PCF8575_Write
	push r18
	ldi r18, @0
	_call PCF8575_Write_act
	pop r18
.endm

PCF8575_Write_act:

	TWSI_START										; �������� ������
	TWSI_SLA r18, 'W'								; ���������� ����� � ����� ������
	
	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoWriteLabels							; ���� ������, �� ���������

	READ_REG PCF8575_Data, r18
	WRITE_REG TWDR, r18								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoWriteLabels							; ���� ������, �� ���������

	READ_REG PCF8575_Data + 1, r18
	WRITE_REG TWDR, r18								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoWriteLabels							; ���� ������, �� ���������
	
	TWSI_STOP
	_jump PCF8575_Write_end

	gotoWriteLabels:
		TWSI_STOP
		_call PCF8575_NoAck

	PCF8575_Write_end:
ret