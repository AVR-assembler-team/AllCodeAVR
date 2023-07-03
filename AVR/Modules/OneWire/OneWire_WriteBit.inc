/*
* Посылка одного бита девайсу
*/
.macro OneWireWriteBit
	.if @0 == 1
		_call OneWireWriteBit1_act
	.elif @0 == 0
		_call OneWireWriteBit0_act
	.endif
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireWriteBit1_act:
	cli
	SETB OneWire_DDR, OneWire_bit
	CLRB OneWire_PORT, OneWire_bit 
	OneWire_DelayA
	CLRB OneWire_DDR, OneWire_bit
	OneWire_DelayB
	sei
ret
;----------------------------
OneWireWriteBit0_act:
	cli
	SETB OneWire_DDR, OneWire_bit
	CLRB OneWire_PORT, OneWire_bit 
	OneWire_DelayC
	CLRB OneWire_DDR, OneWire_bit
	OneWire_DelayD
	sei
ret
