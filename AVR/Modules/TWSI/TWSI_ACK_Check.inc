/*
* ��������� ��������� �������� TWI ������ I2C
*/
.macro TWSI_ACK_Check
	push r17
	push r18
	ldi r17, @0
	ldi r18, @1
	_call TWSI_ACK_Check_act
	pop r18
	pop r17
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_ACK_Check_act:
	push r16
	TWSI_ACK_Check_act_1:
		READ_REG TWSR, r16					; ������ TWSR
		andi	r16, 0xF8					; �������� ������ ��� ����
		cpse	r16, r17					; ���������� r16 � r17
		rjmp TWSI_Status_act_2				; ���������
		CLRB TWSI_Flags, No_ACK				; �������� ����
		rjmp TWSI_ACK_Check_act_end			; ���������

		TWSI_Status_act_2:
			cpse	r16, r18				; ���������� r16 � r18
			rjmp	TWSI_ACK_Check_act_1	; ���� �� �����, �� ���������
			SETB TWSI_Flags, No_ACK			; ������������� ����
	TWSI_ACK_Check_act_end:
	pop r16
ret