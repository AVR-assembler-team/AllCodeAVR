.macro OneWire_AlarmSearch
	_call OneWire_AlarmSearch_act
.endm
OneWire_AlarmSearch_act:

	OneWire_InitializationSequence					; ������������� ��������		

	push r16										; r16  � STACK
	READ_REG OneWireFlags, r16						; �������� ������� SREG � r16
	sbrc r16, OneWireDeviceNotDetected				; ��������� ���� ����������
		_jump OneWire_AlarmSearch_act_End			; �������������

	OneWireROMSearching OneWireAlarmSearchCommand	; ��������� ����� ROM
	
OneWire_AlarmSearch_act_End:
	pop r16
ret
