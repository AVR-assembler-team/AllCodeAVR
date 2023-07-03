/*
* Отсылает 64 бит из адреса @0 девайсу
* Использует r16, r17, r18
*/
.macro OneWireSendROMCode
	
	push r16						; вталкиваем r16 в STACK
	push r17						; вталкиваем r17 в STACK
	
	_call OneWireSendROMCode_act	; переходим

	pop r17							; выталкиваем r17 из STACK
	pop r16							; выталкиваем r16 из STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendROMCode_act:
	
	READ_REG OneWireFlags, r16				; копируем регистр флагов в r16
	sbrc r16, OneWireDeviceNotDetected		; проверяем флат присутствия на шине
		_jump OneWireSendROMCode_act_finish	; переходим
	ldi r17, $08							; записываем количество передаваемых байт

	OneWireSendROMCodeLoop:
		ld	r16, z+							; читаем первый байт в r16
		OneWireSendByte	r16					; Использует r16, r17
		dec r17								; уменьшаем количество байт для отправки
		brne OneWireSendROMCodeLoop			; если не 0, то переходим

	OneWireSendROMCode_act_finish:

ret
