/*
* Для проверки присутствия девайса на шине 1Wire 
* На выходе состояние будет записано во флаг присутствия
*/

.macro OneWire_InitializationSequence
	_call OneWire_InitializationSequence_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWire_InitializationSequence_act:
	cli											; выключаем прерывания
	SETB OneWire_DDR, OneWire_bit				; ножку на выход
	CLRB OneWire_PORT, OneWire_bit				; роняем ногу на 0
	OneWire_DelayH								; задержка А
	CLRB OneWire_DDR, OneWire_bit				; ножку на вход
	OneWire_DelayI								; задержка Е
	
	sbic OneWire_PIN, OneWire_bit				; проверяем ножку на -
	_jump OneWireDeviceNotDetect				; переходим если на ноге + (устройств нет)

OneWireDeviceDetect:	
	CLRB OneWireFlags, OneWireDeviceNotDetected	; очищаем флаг отсутствия на шине
	_jump OneWireInitializationSequenceFinish	; переходим

OneWireDeviceNotDetect:							; метка, когда устройство не обнаружено
	SETB OneWireFlags, OneWireDeviceNotDetected	; поднимаем флаг отсутствия на шине
	_call DeviceNotDetected						; вызывается функция когда устройства не обнаружены

OneWireInitializationSequenceFinish:			; метка
	OneWire_DelayJ								; задержка J
	sei											; запускаем прерывания
ret
