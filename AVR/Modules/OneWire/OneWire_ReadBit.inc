/*
* Чтение одного бита из девайса и запись его во флаг T
*/

.macro OneWireReadBit
	_call OneWireReadBit_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireReadBit_act:
	cli								; выключаем прерывания
	SETB OneWire_DDR, OneWire_bit	; ножку на выход
	CLRB OneWire_PORT, OneWire_bit	; роняем ногу на 0
	OneWire_DelayA					; задержка А
	CLRB OneWire_DDR, OneWire_bit	; ножку на вход
	OneWire_DelayE					; задержка Е
	sbis OneWire_PIN, OneWire_bit	; проверяем ножку на +
	clt								; обнуляем флаг T
	sbic OneWire_PIN, OneWire_bit	; проверяем ножку на -
	set								; устанавливаем флаг T
	OneWire_DelayF					; задержка F
	sei								; запускаем прерывания
ret
