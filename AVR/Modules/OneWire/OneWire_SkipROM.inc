.macro OneWire_SkipROM
	_call OneWire_SkipROM_act
.endm
OneWire_SkipROM_act:
	OneWire_InitializationSequence				; инициализация процесса

	push r16									; r16  в STACK
	READ_REG OneWireFlags, r16					; копируем регистр SREG в r16
	sbrc r16, OneWireDeviceNotDetected			; проверяем флат отсутствия
		_jump OneWire_SkipROM_End				; перепрыгиваем

	OneWireSendCommand OneWireSkipROMCommand	; отправка команды

OneWire_SkipROM_End:
	pop r16										; r16 из STACK
ret
