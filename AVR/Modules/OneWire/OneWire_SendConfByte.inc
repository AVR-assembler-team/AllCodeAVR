/*
* Отсылает 3 байта девайсу, главный байт configuration
* Принимает один аргумент равный 9, 10, 11 или 12 - количество бит для вычисления температуры
*/
.macro OneWireSendConfByte
	
	push r17						; вталкиваем r17 в STACK

	.if @0 == 9
		ldi r17, $1f				; записываем в r17
	.elif @0 == 10
		ldi r17, $3f				; записываем в r17
	.elif @0 == 11
		ldi r17, $5f				; записываем в r17
	.else
		ldi r17, $7f				; записываем в r17
	.endif
	_call OneWireSendConfByte_act	; переходим
	
	pop r17							; выталкиваем r17 из STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendConfByte_act:

	push r16									; вталкиваем r16 в STACK

	READ_REG OneWireFlags, r16					; копируем регистр флагов
	sbrc r16, OneWireDeviceNotDetected			; проверяем флат присутствия на шине
		_jump OneWireSendConfByte_act_finish	; перепрыгиваем
	ldi r16, $ff								; записываем $ff в r16
	OneWireSendByte	r16							; использует r16, r17
	OneWireSendByte	r16							; использует r16, r17
	mov r16, r17								; копируем r18 в r16
	OneWireSendByte	r16							; использует r16, r17

OneWireSendConfByte_act_finish:
	pop r16										; выталкиваем r16 из STACK
	
ret
