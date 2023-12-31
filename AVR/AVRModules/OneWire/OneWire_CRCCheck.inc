/*
* ������� ��������� �������� - ����� ���� ��� �������� 
* - ���� ��� ������ ROM Code �� �������� ����� ���������� ���� � ���� ���� (�������� 8)
* - ���� ��� ������ Scretch Pad - ���������� ���� � ��� (�������� 9)
* ����� ��������� ����� ����� (� zh:zl) ��������� �� ��������� �� ������ ��� ��������
* ������ ��� �������� ���������� � 0-�� �����
*/

.macro OneWireCRCCheck
	push r16									; ���������� r16 � STACK
	push r17									; ���������� r17 � STACK
	push r18									; ���������� r18 � STACK
	push r19									; ���������� r19 � STACK
	push r20									; ���������� r20 � STACK
	push r21									; ���������� r21 � STACK
	push r22									; ���������� r22 � STACK
	
	ldi r19, @0									; ���������� ���������� ���� ��� ������
	ldi r20, @0									; ���������� ���������� ���� ��� ������
	
	sbiw zh:zl, @0								; �������� 8 �� �����
	_call OneWireCRCCheck_act
	
	pop r22										; ����������� r22 �� STACK
	pop r21										; ����������� r21 �� STACK
	pop r20										; ����������� r20 �� STACK
	pop r19										; ����������� r19 �� STACK	
	pop r18										; ����������� r18 �� STACK	
	pop r17										; ����������� r17 �� STACK	
	pop r16										; ����������� r16 �� STACK
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireCRCCheck_act:
	
	READ_REG OneWireFlags, r16					; �������� ������� ������ � r16
	sbrc r16, OneWireDeviceNotDetected			; ��������� ���� ����������� �� ����
		_jump OneWireCRCCheck_act_finish		; �������������
	
	CLRB OneWireFlags, OneWireROMCodeCRCInvalid	; ������� ���� ������ ������ � �������� ������
	ld r16, z+									; �������� ������ ���� � ������� r16
	ldi r17, OneWireCRC_polynom					; ���������� ������������ ������� ��� ���������� CRC
	dec r19										; ��������� ���������� ��������� ��� ��������

OneWireCRCCheckBegin:							; �����
	ld r18, z+									; �������� ���� � ������� r18
	_call OneWireCRCCheckCalc					; ���������
	dec r19										; ��������� ���������� ��������� ��� ��������
	brne OneWireCRCCheckBegin					; ���� �� ����� 0, �� ��������� �� �����
	cpi r16, 0									; ���������� � 0
	breq OneWireCRCCheckCorrect					; ���� ����� �� ��������
	brne OneWireCRCCheckNotCorrect				; ���� �� ����� �� ���������
	
OneWireCRCCheckCorrect:							; �����
	_jump OneWireCRCCheck_act_finish			; �������������
	
OneWireCRCCheckNotCorrect:
	mov r16, r20								; ���������� ���������� ���� � ������� ������ ��� ��������	
	clr r17										; ������� ������� r17
	sbiw zh:zl, $08								; �������� 8 �� �����

OneWireDataClean:
	st z+, r17									; ������� ���� � ������
	dec r16										; ��������� ���������� ���������� ���� � ������� ������ ��� ��������	
	brne OneWireDataClean						; ���������, ���� ����� �� �����������
	SETB OneWireFlags, OneWireROMCodeCRCInvalid	; ������������� ���� ������ ������ � �������� ������
	cpi r20, 8
	brne OneWire_ScretchpadCRC
	_call ROMCodeCRCError
	_jump OneWireCRCCheck_act_finish

OneWire_ScretchpadCRC:
	_call ScretchpadCRCError

OneWireCRCCheck_act_finish:								

ret
//----------------------------------------------------------
OneWireCRCCheckCalc:

	cli											; ��������� ����������	
			
	ldi r21, $08								; ���������� ���������� �������

OneWireCRCCheckAct:
	dec r21						; ��������� ���������� �������
	brlt OneWireCRCCheckEnd		; ���� ������ 0, �� ���������
	ror r18						; �������� ���� ������ ����� �
	ror r16						; �������� ���� ������ ����� �
	READ_REG SREG, r22			; �������� SREG � R22
	sbrs r22, 0					; ��������� ��������� ����� �
	_jump OneWireCRCCheckAct	; ��������� ���� ���� ������
	eor r16, r17				; ��������� ����������� ��� ���� ���������
	_jump OneWireCRCCheckAct	; ���������

OneWireCRCCheckEnd:

	sei							; �������� ����������
ret
