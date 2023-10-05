.macro CountersInterruptCounter4
	.if @0 == CaptureEvent
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK4, ICIE4
			.elif @1 == disabled
				CLRB TIMSK4, ICIE4
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == Overflow
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK4, TOIE4
			.elif @1 == disabled
				CLRB TIMSK4, TOIE4
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatch
		.error "Compare Match is not supporting by counter 4 of this controller!"
	.elif @0 == CompareMatchA
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK4, OCIE4A
			.elif @1 == disabled
				CLRB TIMSK4, OCIE4A
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchB
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK4, OCIE4B
			.elif @1 == disabled
				CLRB TIMSK4, OCIE4B
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchC
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK4, OCIE4C
			.elif @1 == disabled
				CLRB TIMSK4, OCIE4C
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.endif
.endm
