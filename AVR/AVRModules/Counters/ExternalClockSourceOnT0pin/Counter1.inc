.macro CountersExternalClockSourceOnT0pinCounter1
	.if @0 == FallingEdge
		CLRB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.elif @0 == RisingEdge
		SETB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.endif
.endm
