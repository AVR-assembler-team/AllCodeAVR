.macro OneWire_MatchROM
	push zh								; ���������� zh � STACK
	push zl								; ���������� zl � STACK

	ldi zh, high(@0)					; ���������� ������� ���� ������ ������� ������
	ldi zl, low(@0)						; ���������� ������� ���� ������ ������� ������
	_call OneWire_MatchROM_act
	pop zl								; ����������� zl �� STACK
	pop zh								; ����������� zh �� STACK
.endm
OneWire_MatchROM_act:
	OneWire_InitializationSequence				; ������������� ��������
	
	push r16									; r16  � STACK
	READ_REG OneWireFlags, r16					; �������� ������� SREG � r16
	sbrc r16, OneWireDeviceNotDetected			; ��������� ���� ����������
		_jump OneWire_MatchROM_End				; �������������

	OneWireSendCommand OneWireMachROMCommand	; �������� �������

	OneWireSendROMCode

OneWire_MatchROM_End:
	pop r16										; r16 �� STACK
ret
