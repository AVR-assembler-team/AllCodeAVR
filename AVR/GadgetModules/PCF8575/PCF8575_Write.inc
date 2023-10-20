/*
* ���������� 2 ����� � ���
*/

.macro PCF8575Write
	push r18
	push r19
	push r20
	ldi r18, @0
	mov r19, @1
	mov r20, @2
	_call PCF8575Write_act
	pop r20
	pop r19
	pop r18
.endm

PCF8575Write_act:


	TWSI_START										; �������� ������
	TWSI_SLA r18, 'W'								; ���������� ����� � ����� ������
	
	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoPCF8575WriteLabels							; ���� ������, �� ���������

	WRITE_REG TWDR, r19								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoPCF8575WriteLabels							; ���� ������, �� ���������

	WRITE_REG TWDR, r20								; ���������� � ���� �������

	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

	READ_REG TWSI_Flags, r18						; ��������� ������� ������
	sbrc r18, No_ACK								; ��������� ��� 
	_jump gotoPCF8575WriteLabels							; ���� ������, �� ���������
	
	TWSI_STOP
	_jump PCF8575Write_end

	gotoPCF8575WriteLabels:
		TWSI_STOP
		_call PCF8575_NoAck

	PCF8575Write_end:

ret