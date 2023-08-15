/*
* ���������� ���� � ���
*/

.macro PCF8574_Write
	push r18
	push r19
	ldi r18, @0
	mov r19, @1
	_call PCF8574_Write_act
	pop r19
	pop r18
.endm

PCF8574_Write_act:

	TWSI_START										; �������� ������
	TWSI_SLA r18, 'W'								; ���������� ����� � ����� ������
	
	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoPCF8574WriteLabels							; ���� ������, �� ���������

	WRITE_REG TWDR, r19								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoPCF8574WriteLabels							; ���� ������, �� ���������

	TWSI_STOP
	_jump PCF8574_Write_end

	gotoPCF8574WriteLabels:
		TWSI_STOP
		_call PCF8574_NoAck

	PCF8574_Write_end:

ret