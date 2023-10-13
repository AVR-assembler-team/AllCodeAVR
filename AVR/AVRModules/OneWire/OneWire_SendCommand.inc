/*
* Для отправки команды команды девайсу
* Принимает один аргумент
*/
.macro OneWireSendCommand
	
	push r16						; вталкиваем r16 в STACK

	ldi	r16, @0						; записываем @0 в r16
	_call OneWireSendCommand_act	; переходим
	
	pop r16							; выталкиваем r16 из STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendCommand_act:
	push r17
	READ_REG OneWireFlags, r17				; копируем регистр SREG в r17
	sbrc r17, OneWireDeviceNotDetected		; проверяем флат отсутствия
		_jump OneWireSendCommand_act_finish
	OneWireSendByte	r16						; Использует r16 и r17

OneWireSendCommand_act_finish:
	pop r17
ret
