/*
* �������� 3 ����� �������, ������� ���� configuration
* ��������� ���� �������� ������ 9, 10, 11 ��� 12 - ���������� ��� ��� ���������� �����������
*/
.macro OneWireSendConfByte
	
	push r17						; ���������� r17 � STACK

	.if @0 == 9
		ldi r17, $1f				; ���������� � r17
	.elif @0 == 10
		ldi r17, $3f				; ���������� � r17
	.elif @0 == 11
		ldi r17, $5f				; ���������� � r17
	.else
		ldi r17, $7f				; ���������� � r17
	.endif
	_call OneWireSendConfByte_act	; ���������
	
	pop r17							; ����������� r17 �� STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendConfByte_act:

	push r16									; ���������� r16 � STACK

	READ_REG OneWireFlags, r16					; �������� ������� ������
	sbrc r16, OneWireDeviceNotDetected			; ��������� ���� ����������� �� ����
		_jump OneWireSendConfByte_act_finish	; �������������
	ldi r16, $ff								; ���������� $ff � r16
	OneWireSendByte	r16							; ���������� r16, r17
	OneWireSendByte	r16							; ���������� r16, r17
	mov r16, r17								; �������� r18 � r16
	OneWireSendByte	r16							; ���������� r16, r17

OneWireSendConfByte_act_finish:
	pop r16										; ����������� r16 �� STACK
	
ret
