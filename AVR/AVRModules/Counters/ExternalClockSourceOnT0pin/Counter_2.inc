.macro CountersExternalClockSourceOnT0pinCounter2
	.if ctrl == 64 || ctrl == 128
		.if @0 == FallingEdge
			CLRB TCCR2, CS20
			SETB TCCR2, CS21
			SETB TCCR2, CS22
		.elif @0 == RisingEdge
			SETB TCCR2, CS20
			SETB TCCR2, CS21
			SETB TCCR2, CS22
		.endif
	.elif ctrl == 8515
		.error "Counter 2 is not supporting by this controller!"
	.else
		.error "External Clock Source on T0 pin is not supporting by counter 0 of this controller!"
	.endif
.endm
