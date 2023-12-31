/*
* �������� ���� ���� �������
* ��������� ���� �������� - ������� ��� ��������
*/
.macro OneWireSendByte
	
	push r16							; ���������� r16 � STACK

	mov r16, @0							; �������� @0 � r16
	_call OneWireSendByte_act	; ���������
	
	pop r16								; ����������� r16 �� STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendByte_act:

	push r17									; ���������� r17 � STACK

	READ_REG OneWireFlags, r17					; �������� ������� ������ � r16
	sbrc r17, OneWireDeviceNotDetected			; ��������� ���� ����������� �� ����
		_jump OneWireSendByte_act_finish	; �������������
	ldi r17, $08								; ���������� 8 � r17

SendBiteLoop:
	sbrc r16, 0
		OneWireWriteBit 1						; �������� ������� ������ � ����
	sbrs r16, 0
		OneWireWriteBit 0						; �������� ������ ������ � ����
	lsr r16										; �������� ���� ������
	dec r17										; ��������� r17 �� 1
	brne SendBiteLoop							; ���� r17 �� ����� 0, �� ���������

OneWireSendByte_act_finish:
	pop r17										; ����������� r17 �� STACK

ret 
