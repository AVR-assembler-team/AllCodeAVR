.macro OneWire_ReadROM
	_call OneWire_ReadROM_act
.endm

OneWire_ReadROM_act:
	OneWire_InitializationSequence				; инициализация процесса

	push r16									; r16  в STACK
	READ_REG OneWireFlags, r16					; копируем регистр SREG в r16
	sbrc r16, OneWireDeviceNotDetected			; проверяем флат отсутствия
		_jump OneWire_ReadROM_act_End			; перепрыгиваем

	OneWireSendCommand OneWireReadROMCommand	; отправка команды

	OneWireReadBytes OneWireROMCode, 8			; читаем ROM code устройства

OneWire_ReadROM_act_End:
	pop r16										; r16 из STACK
ret
