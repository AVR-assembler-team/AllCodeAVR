/*
* ��������� ��������� ����� TWINT ������ TWSI
* ���������� ������� r25
*/
.macro TWSI_TWINT_Flag
	_call TWSI_TWINT_Flag_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_TWINT_Flag_act:
	
	push r25

	TWSI_TWINT_Flag_act_1:
		READ_REG TWCR, r25					; ���������� TWCR � R25
		sbrs	r25, TWINT						; ���� ��� TWINT ������, �� ���������� ���� ������
		rjmp	TWSI_TWINT_Flag_act_1					; ������������� �� �����

	pop r25

ret
 