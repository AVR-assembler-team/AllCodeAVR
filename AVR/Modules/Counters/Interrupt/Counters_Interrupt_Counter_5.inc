.macro CountersInterruptCounter5
	.if @0 == CaptureEvent
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK5, ICIE5
			.elif @1 == disabled
				CLRB TIMSK5, ICIE5
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == Overflow
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK5, TOIE5
			.elif @1 == disabled
				CLRB TIMSK5, TOIE5
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatch
		.error "Compare Match is not supporting by counter 5 of this controller!"
	.elif @0 == CompareMatchA
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK5, OCIE5A
			.elif @1 == disabled
				CLRB TIMSK5, OCIE5A
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchB
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK5, OCIE5B
			.elif @1 == disabled
				CLRB TIMSK5, OCIE5B
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchC
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK5, OCIE5C
			.elif @1 == disabled
				CLRB TIMSK5, OCIE5C
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.endif
.endm
