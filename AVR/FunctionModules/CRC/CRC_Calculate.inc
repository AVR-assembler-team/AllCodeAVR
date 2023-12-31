/*
 * @0 - ����� ������ ������ � RAM �����������
 * @1 - �������
 * @2 - ���������� ���� ��� �������� CRC
 * @3 - ������� ������
 */ 

 .macro CRCCalculate
	push zh
	push zl
	push r16
	push r17
	push r18
	push r19
	push r21
	push r22

	ldi zh, high(@0)
	ldi zl, low(@0)
	ldi r16, @1
	ldi r17, @2

	_call CRCCalculate_act

	WRITE_REG CRC_byte, r18

	pop r22
	pop r21
	pop r19
	pop r18
	pop r17
	pop r16
	pop zl
	pop zh
 .endm

 CRCCalculate_act:
	ld r18, z+						; �������� ������ ���� � ������� r18
	dec r17							; ��������� ���������� ��������� ��� ��������
	CRCCalculateBegin:
		ld r19, z+					; �������� ���� � ������� r19
		_call CRCCalc
		dec r17						; ��������� ���������� ��������� ��� ��������
		brne CRCCalculateBegin	; ���� �� ����� 0, �� ��������� �� �����
		clr r19
		_call CRCCalc
 ret

CRCCalc:
	cli											; ��������� ����������	
			
	ldi r21, $08								; ���������� ���������� �������

CRCCalc_act:
	dec r21						; ��������� ���������� �������
	brlt CRCCalc_end		; ���� ������ 0, �� ���������
	ror r19						; �������� ���� ������ ����� �
	ror r18						; �������� ���� ������ ����� �
	READ_REG SREG, r22			; �������� SREG � R22
	sbrs r22, 0					; ��������� ��������� ����� �
	_jump CRCCalc_act	; ��������� ���� ���� ������
	eor r18, r16				; ��������� ����������� ��� ���� ���������
	_jump CRCCalc_act	; ���������

	CRCCalc_end:

	sei							; �������� ����������
ret