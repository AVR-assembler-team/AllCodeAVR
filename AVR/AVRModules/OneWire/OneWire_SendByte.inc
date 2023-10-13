/*
* Отсылает один байт девайсу
* Принимает один аргумент - регистр для отправки
*/
.macro OneWireSendByte
	
	push r16							; вталкиваем r16 в STACK

	mov r16, @0							; копируем @0 в r16
	_call OneWireSendByte_act	; переходим
	
	pop r16								; выталкиваем r16 из STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSendByte_act:

	push r17									; вталкиваем r17 в STACK

	READ_REG OneWireFlags, r17					; копируем регистр флагов в r16
	sbrc r17, OneWireDeviceNotDetected			; проверяем флат присутствия на шине
		_jump OneWireSendByte_act_finish	; перепрыгиваем
	ldi r17, $08								; записываем 8 в r17

SendBiteLoop:
	sbrc r16, 0
		OneWireWriteBit 1						; отсылаем высокий сигнал в шину
	sbrs r16, 0
		OneWireWriteBit 0						; отсылаем низкий сигнал в шину
	lsr r16										; сдвигаем байт вправо
	dec r17										; уменьшаем r17 на 1
	brne SendBiteLoop							; если r17 не равен 0, то переходим

OneWireSendByte_act_finish:
	pop r17										; выталкиваем r17 из STACK

ret 
