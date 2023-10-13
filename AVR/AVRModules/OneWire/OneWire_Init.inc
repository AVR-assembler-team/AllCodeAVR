/*
* Устанавливает/очищает флаг внешнего питания
*/

.macro OneWire_init
	#ifdef ExternalPowerSupply
		SETB OneWireFlags, OneWireExternalPower			; устанавливаем флаг внешнего питания
	#else
		CLRB OneWireFlags, OneWireExternalPower			; очищаем флаг внешнего питания
	#endif
.endm

