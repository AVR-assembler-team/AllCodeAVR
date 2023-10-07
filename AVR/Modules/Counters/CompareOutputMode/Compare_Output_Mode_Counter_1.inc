.macro CompareOutputModeCounter1
	.if @0 == CompareMatchOutput
		.error "Compare Output Mode is not supporting by counter 1 of this controller!"
	.elif @0 == CompareMatchOutputA
		.if @1 == 0
			CLRB TCCR1A, COM1A0 
			CLRB TCCR1A, COM1A1
		.elif @1 == 1
			SETB TCCR1A, COM1A0
			CLRB TCCR1A, COM1A1
		.elif @1 == 2
			CLRB TCCR1A, COM1A0
			SETB TCCR1A, COM1A1
		.elif @1 == 3
			SETB TCCR1A, COM1A0
			SETB TCCR1A, COM1A1
		.endif
	.elif @0 == CompareMatchOutputB
		.if @1 == 0
			CLRB TCCR1A, COM1B0 
			CLRB TCCR1A, COM1B1
		.elif @1 == 1
			SETB TCCR1A, COM1B0
			CLRB TCCR1A, COM1B1
		.elif @1 == 2
			CLRB TCCR1A, COM1B0
			SETB TCCR1A, COM1B1
		.elif @1 == 3
			SETB TCCR1A, COM1B0
			SETB TCCR1A, COM1B1
		.endif
	.elif @0 == CompareMatchOutputC
		.if ctrl == 64 || ctrl == 128 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == 0
				CLRB TCCR1A, COM1C0 
				CLRB TCCR1A, COM1C1
			.elif @1 == 1
				SETB TCCR1A, COM1C0
				CLRB TCCR1A, COM1C1
			.elif @1 == 2
				CLRB TCCR1A, COM1C0
				SETB TCCR1A, COM1C1
			.elif @1 == 3
				SETB TCCR1A, COM1C0
				SETB TCCR1A, COM1C1
			.endif
		.else
			.error "Compare Match Output C is not supporting by counter 0 of this controller!"
		.endif
	.endif
.endm
