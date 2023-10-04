.macro CountersInterruptCounter1
	.if @0 == CompareMatch
		.error "Compare Match is not supporting by counter 1 of this controller!"
	.elif @0 == Overflow
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, TOIE1
			.elif @1 == disabled
				CLRB TIMSK, TOIE1
			.endif
		.else
			.if @1 == enabled
				SETB TIMSK1, TOIE1
			.elif @1 == disabled
				CLRB TIMSK1, TOIE1
			.endif
		.endif
	.elif @0 == CaptureEvent
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, TICIE1
			.elif @1 == disabled
				CLRB TIMSK, TICIE1
			.endif
		.else
			.if @1 == enabled
				SETB TIMSK1, ICIE1
			.elif @1 == disabled
				CLRB TIMSK1, ICIE1
			.endif
		.endif
	.elif @0 == CompareMatchA
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, OCIE1A
			.elif @1 == disabled
				CLRB TIMSK, OCIE1A
			.endif
		.else
			.if @1 == enabled
				SETB TIMSK1, OCIE1A
			.elif @1 == disabled
				CLRB TIMSK1, OCIE1A
			.endif
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == enabled
				SETB TIMSK, OCIE1B
			.elif @1 == disabled
				CLRB TIMSK, OCIE1B
			.endif
		.else
			.if @1 == enabled
				SETB TIMSK1, OCIE1B
			.elif @1 == disabled
				CLRB TIMSK1, OCIE1B
			.endif
		.endif
	.elif @0 == CompareMatchC
		.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK1, OCIE1C
			.elif @1 == disabled
				CLRB TIMSK1, OCIE1C
			.endif
		.else
			.error "Compare Match C is not supporting by counter 1 of this controller!"
		.endif
	.endif
.endm
