/*
* �������� ������ TWSI ����� ����, ������ ��� ����������
* ��������� ��� ���������
* @0 - ����� ���� TWSI
* @1 - 'W'-������ / 'R'-������

* ����� �������� � �������� ������ (TWSI_Flags) ����� ����������� ��������������� 
* ��������� ���� (Address_No_ACK)
* 0 - ��� ������
* 1 - ������ ���
*
* ���������� ������� r23, r24, r25
*/
.macro TWSI_SLA
	
	push r25

	.if @1 == 'W'
		mov	r25, @0
	.elif @1 == 'R'
		mov	r25, @0
		sbr	r25, 1
	.endif
		
	WRITE_REG TWDR, r25						; ���������� � ���� �������
	TWSI_Byte_Transmit						; r25

	.if @1 == 'W'
		TWSI_ACK_Check MT_SLA_W_ACK, MT_SLA_W_NOT_ACK	; r23, r24, r25					; ��������� ������� �� �����
	.elif @1 == 'R'
		TWSI_ACK_Check MT_SLA_R_ACK, MT_SLA_R_NOT_ACK	; r23, r24, r25					; ��������� ������� �� �����
	.endif

	pop r25

.endm
