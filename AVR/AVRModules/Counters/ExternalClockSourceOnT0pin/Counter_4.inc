.macro CountersExternalClockSourceOnT0pinCounter4
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == FallingEdge
			CLRB TCCR4B, CS40
			SETB TCCR4B, CS41
			SETB TCCR4B, CS42
		.elif @0 == RisingEdge
			SETB TCCR4B, CS40
			SETB TCCR4B, CS41
			SETB TCCR4B, CS42
		.endif
	.else
		.error "Counter 4 is not supporting by this controller!"
	.endif
.endm
