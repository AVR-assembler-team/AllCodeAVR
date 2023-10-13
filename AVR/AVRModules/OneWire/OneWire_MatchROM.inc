.macro OneWire_MatchROM
	push zh								; вталкиваем zh в STACK
	push zl								; вталкиваем zl в STACK

	ldi zh, high(@0)					; записываем старший байт адреса области памяти
	ldi zl, low(@0)						; записываем младший байт адреса области памяти
	_call OneWire_MatchROM_act
	pop zl								; выталкиваем zl из STACK
	pop zh								; выталкиваем zh из STACK
.endm
OneWire_MatchROM_act:
	OneWire_InitializationSequence				; инициализация процесса
	
	push r16									; r16  в STACK
	READ_REG OneWireFlags, r16					; копируем регистр SREG в r16
	sbrc r16, OneWireDeviceNotDetected			; проверяем флат отсутствия
		_jump OneWire_MatchROM_End				; перепрыгиваем

	OneWireSendCommand OneWireMachROMCommand	; отправка команды

	OneWireSendROMCode

OneWire_MatchROM_End:
	pop r16										; r16 из STACK
ret
