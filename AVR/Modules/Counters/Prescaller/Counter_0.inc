/*
*	@1 - претделитель	(Prescaller8 как пример)
*/
.macro CountersPrescallerCounter0
	.if ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		.if @0 == Prescaller1
			SETB TCCR0A, CS00
			CLRB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0A, CS00
			SETB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller32
			.error "Prescaller 32 is not supporting by counter 0 of this controller!"
		.elif @0 == Prescaller64
			SETB TCCR0A, CS00
			SETB TCCR0A, CS01
			CLRB TCCR0A, CS02
		.elif @0 == Prescaller128
			.error "Prescaller 128 is not supporting by counter 0 of this controller!"
		.elif @0 == Prescaller256
			CLRB TCCR0A, CS00
			CLRB TCCR0A, CS01
			SETB TCCR0A, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0A, CS00
			CLRB TCCR0A, CS01
			SETB TCCR0A, CS02
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
		.elif @0 == Prescaller32
			.error "Prescaller 32 is not supporting by counter 0 of this controller!"
		.elif @0 == Prescaller64
			SETB TCCR0B, CS00
			SETB TCCR0B, CS01
			CLRB TCCR0B, CS02
		.elif @0 == Prescaller128
			.error "Prescaller 128 is not supporting by counter 0 of this controller!"
		.elif @0 == Prescaller256
			CLRB TCCR0B, CS00
			CLRB TCCR0B, CS01
			SETB TCCR0B, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0B, CS00
			CLRB TCCR0B, CS01
			SETB TCCR0B, CS02
		.endif
	.elif ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
		.if @0 == Prescaller1
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller8
			CLRB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller32
			.if ctrl == 64 || ctrl == 128
				SETB TCCR0, CS00
				SETB TCCR0, CS01
				CLRB TCCR0, CS02
			.else
				.error "Prescaller 32 is not supporting by counter 0 of this controller!"
			.endif
		.elif @0 == Prescaller64
			SETB TCCR0, CS00
			SETB TCCR0, CS01
			CLRB TCCR0, CS02
		.elif @0 == Prescaller128
			.if ctrl == 64 || ctrl == 128
				SETB TCCR0, CS00
				CLRB TCCR0, CS01
				SETB TCCR0, CS02
			.else
				.error "Prescaller 128 is not supporting by counter 0 of this controller!"
			.endif
		.elif @0 == Prescaller256
			CLRB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.elif @0 == Prescaller1024
			SETB TCCR0, CS00
			CLRB TCCR0, CS01
			SETB TCCR0, CS02
		.endif
	.endif
.endm
