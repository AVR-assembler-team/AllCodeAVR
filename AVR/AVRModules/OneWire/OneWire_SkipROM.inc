.macro OneWire_SkipROM
	_call OneWire_SkipROM_act
.endm
OneWire_SkipROM_act:
	OneWire_InitializationSequence				; ������������� ��������

	push r16									; r16  � STACK
	READ_REG OneWireFlags, r16					; �������� ������� SREG � r16
	sbrc r16, OneWireDeviceNotDetected			; ��������� ���� ����������
		_jump OneWire_SkipROM_End				; �������������

	OneWireSendCommand OneWireSkipROMCommand	; �������� �������

OneWire_SkipROM_End:
	pop r16										; r16 �� STACK
ret
