.macro OneWire_ReadROM
	_call OneWire_ReadROM_act
.endm

OneWire_ReadROM_act:
	OneWire_InitializationSequence				; ������������� ��������

	push r16									; r16  � STACK
	READ_REG OneWireFlags, r16					; �������� ������� SREG � r16
	sbrc r16, OneWireDeviceNotDetected			; ��������� ���� ����������
		_jump OneWire_ReadROM_act_End			; �������������

	OneWireSendCommand OneWireReadROMCommand	; �������� �������

	OneWireReadBytes OneWireROMCode, 8			; ������ ROM code ����������

OneWire_ReadROM_act_End:
	pop r16										; r16 �� STACK
ret
