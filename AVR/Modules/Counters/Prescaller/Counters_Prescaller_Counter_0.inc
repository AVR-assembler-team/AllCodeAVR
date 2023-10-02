.macro TimersPrescallerCounter0
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
		.if @0 == Prescaller1
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller64
			SETB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller256
			CLRB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.else
			.error "Prescaller for Counter0 is not availabale"
		.endif
	.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		.if @0 == Prescaller1
			SETB TCCR0A, CS00
			CLRB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0A, CS00
			SETB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller64
			SETB TCCR0A, CS00
			SETB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller256
			CLRB TCCR0A, CS00
			CLRB TCCR0A, CS01
			SETB TCCR0A, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0A, CS00
			CLRB TCCR0A, CS01
			SETB TCCR0A, CS02
		.else
			.error "Prescaller for Counter0 is not availabale"
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
		.if @0 == Prescaller1
			SETB TCCR0B, CS00
			CLRB TCCR0B, CS01
			CLRB TCCR0B, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0B, CS00
			SETB TCCR0B, CS01
			CLRB TCCR0B, CS02
		.elif @0 == Prescaller64
			SETB TCCR0B, CS00
			SETB TCCR0B, CS01
			CLRB TCCR0B, CS02
		.elif @0 == Prescaller256
			CLRB TCCR0B, CS00
			CLRB TCCR0B, CS01
			SETB TCCR0B, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0B, CS00
			CLRB TCCR0B, CS01
			SETB TCCR0B, CS02
		.else
			.error "Prescaller for Counter0 is not availabale"
		.endif
	.elif ctrl == 64 || ctrl == 128
		.if @0 == Prescaller1
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller32
			SETB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller64
			CLRB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.elif @0 == Prescaller128
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.elif @0 == Prescaller256
			CLRB TCCR0, CS00
			SETB TCCR0, CS01
			SETB TCCR0, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0, CS00
			SETB TCCR0, CS01
			SETB TCCR0, CS02
		.else
			.error "Prescaller for Counter0 is not availabale"
		.endif
	.endif
.endm
