/*
* �������� ������ TWSI ����� ����, ������ ��� ����������
* ��������� ��� ���������
* @0 - ����� ���� TWSI
* @1 - 'W'-������ / 'R'-������

* ����� �������� � �������� ������ (TWSI_Flags) ����� ����������� ��������������� 
* ��������� ���� (Address_No_ACK)
* 0 - ��� ������
* 1 - ������ ���
*/
.macro TWSI_SLA
	push r16

	.if @1 == 'W'
		mov	r16, @0
	.elif @1 == 'R'
		mov	r16, @0
		sbr	r16, 1
	.endif
		
	WRITE_REG TWDR, r16						; ���������� � ���� �������
	TWSI_Byte_Transmit

	.if @1 == 'W'
		TWSI_ACK_Check MT_SLA_W_ACK, MT_SLA_W_NOT_ACK					; ��������� ������� �� �����
	.elif @1 == 'R'
		TWSI_ACK_Check MT_SLA_R_ACK, MT_SLA_R_NOT_ACK					; ��������� ������� �� �����
	.endif

	pop r16
.endm