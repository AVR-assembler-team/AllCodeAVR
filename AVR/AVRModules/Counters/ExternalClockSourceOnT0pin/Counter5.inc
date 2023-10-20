.macro CountersExternalClockSourceOnT0pinCounter5
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == FallingEdge
			CLRB TCCR5B, CS50
			SETB TCCR5B, CS51
			SETB TCCR5B, CS52
		.elif @0 == RisingEdge
			SETB TCCR5B, CS50
			SETB TCCR5B, CS51
			SETB TCCR5B, CS52
		.endif
	.else
		.error "Counter 5 is not supporting by this controller!"
	.endif
.endm
