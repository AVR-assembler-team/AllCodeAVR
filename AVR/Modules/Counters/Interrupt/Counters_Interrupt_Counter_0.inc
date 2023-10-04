.macro CountersInterruptCounter0
	.if @0 == CaptureEvent
		.error "Capture Event is not supporting by counter 0 of this controller!"
	.elif @0 == Overflow
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, TOIE0
			.elif @1 == disabled
				CLRB TIMSK, TOIE0
			.endif
		.else
			.if @1 == enabled
				SETB TIMSK0, TOIE0
			.elif @1 == disabled
				CLRB TIMSK0, TOIE0
			.endif
		.endif
	.elif @0 == CompareMatch
		.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, OCIE0
			.elif @1 == disabled
				CLRB TIMSK, OCIE0
			.endif
		.else
			.error "Compare Match is not supporting by counter 0 of this controller!"
		.endif
	.elif @0 == CompareMatchA
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.error "Compare Match A is not supporting by counter 0 of this controller!"
		.else
			.if @1 == enabled
				SETB TIMSK0, OCIE0A
			.elif @1 == disabled
				CLRB TIMSK0, OCIE0A
			.endif
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == enabled
				SETB TIMSK0, OCIE0B
			.elif @1 == disabled
				CLRB TIMSK0, OCIE0B
			.endif
		.else
			.error "Compare Match B is not supporting by counter 0 of this controller!"
		.endif
	.elif @0 == CompareMatchC
		.error "Compare Match C is not supporting by counter 0 of this controller!"
	.endif
.endm
