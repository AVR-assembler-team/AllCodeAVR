/*
* ��������� ��������� �������� TWI ������ I2C
* ���������� ������� r23, r24, r25
*/
.macro TWSI_ACK_Check

	push r24
	push r23

	ldi r24, @0
	ldi r23, @1
	_call TWSI_ACK_Check_act

	pop r23
	pop r24

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_ACK_Check_act:

	push r25

	TWSI_ACK_Check_act_1:
		READ_REG TWSR, r25					; ������ TWSR
		andi	r25, 0xF8					; �������� ������ ��� ����
		cpse	r25, r24					; ���������� r16 � r17
		rjmp TWSI_Status_act_2				; ���������

		// �������� ����
		CLRB TWSI_Flags, No_ACK

		rjmp TWSI_ACK_Check_act_end			; ���������

		TWSI_Status_act_2:
			cpse	r25, r23				; ���������� r16 � r18
			rjmp	TWSI_ACK_Check_act_1	; ���� �� �����, �� ���������

			// ������������� ����
			SETB TWSI_Flags, No_ACK

	TWSI_ACK_Check_act_end:

	pop r25

ret
