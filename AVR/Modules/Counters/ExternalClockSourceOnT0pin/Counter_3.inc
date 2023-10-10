.macro CountersExternalClockSourceOnT0pinCounter3
	.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
		.if @0 == FallingEdge
			CLRB TCCR3B, CS30
			SETB TCCR3B, CS31
			SETB TCCR3B, CS32
		.elif @0 == RisingEdge
			SETB TCCR3B, CS30
			SETB TCCR3B, CS31
			SETB TCCR3B, CS32
		.endif
	.else
		.error "Counter 3 is not supporting by this controller!"
	.endif
.endm
