/*
* �������� 64 ��� �� ������ @0 �������
* ���������� r16, r17, r18
*/
.macro OneWireSendROMCode
	
	push r16						; ���������� r16 � STACK
	push r17						; ���������� r17 � STACK
	
	_call OneWireSendROMCode_act	; ���������

	pop r17							; ����������� r17 �� STACK
	pop r16							; ����������� r16 �� STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendROMCode_act:
	
	READ_REG OneWireFlags, r16				; �������� ������� ������ � r16
	sbrc r16, OneWireDeviceNotDetected		; ��������� ���� ����������� �� ����
		_jump OneWireSendROMCode_act_finish	; ���������
	ldi r17, $08							; ���������� ���������� ������������ ����

	OneWireSendROMCodeLoop:
		ld	r16, z+							; ������ ������ ���� � r16
		OneWireSendByte	r16					; ���������� r16, r17
		dec r17								; ��������� ���������� ���� ��� ��������
		brne OneWireSendROMCodeLoop			; ���� �� 0, �� ���������

	OneWireSendROMCode_act_finish:

ret