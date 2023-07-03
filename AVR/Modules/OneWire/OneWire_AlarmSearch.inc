.macro OneWire_AlarmSearch
	_call OneWire_AlarmSearch_act
.endm
OneWire_AlarmSearch_act:

	OneWire_InitializationSequence					; инициализация процесса		

	push r16										; r16  в STACK
	READ_REG OneWireFlags, r16						; копируем регистр SREG в r16
	sbrc r16, OneWireDeviceNotDetected				; проверяем флат отсутствия
		_jump OneWire_AlarmSearch_act_End			; перепрыгиваем

	OneWireROMSearching OneWireAlarmSearchCommand	; запускаем поиск ROM
	
OneWire_AlarmSearch_act_End:
	pop r16
ret
