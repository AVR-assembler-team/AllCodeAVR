/*
*	@0 - претделитель	(Prescaller8 как пример)
*/

.macro TimersPrescallerCounter2
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
		.if @0 == Prescaller1
			SETB TCCR2, CS20
			CLRB TCCR2, CS21
			CLRB TCCR2, CS22
		.elif @0 == Prescaller8
			CLRB TCCR2, CS20
			SETB TCCR2, CS21
			CLRB TCCR2, CS22
		.elif @0 == Prescaller32
			.if ctrl == 64 || ctrl == 128
				.error "Prescaller 32 is not supporting by counter 2 of this controller!"
			.else
				SETB TCCR2, CS20
				SETB TCCR2, CS21
				CLRB TCCR2, CS22
			.endif
		.elif @0 == Prescaller64
			CLRB TCCR2, CS20
			CLRB TCCR2, CS21
			SETB TCCR2, CS22
		.elif @0 == Prescaller128
			.if ctrl == 64 || ctrl == 128
				.error "Prescaller 128 is not supporting by counter 2 of this controller!"
			.else
				SETB TCCR2, CS20
				CLRB TCCR2, CS21
				SETB TCCR2, CS22
			.endif
		.elif @0 == Prescaller256
			CLRB TCCR2, CS20
			SETB TCCR2, CS21
			SETB TCCR2, CS22
		.elif @0 == Prescaller1024
			SETB TCCR2, CS20
			SETB TCCR2, CS21
			SETB TCCR2, CS22
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == Prescaller1
			SETB TCCR2B, CS20
			CLRB TCCR2B, CS21
			CLRB TCCR2B, CS22
		.elif @0 == Prescaller8
			CLRB TCCR2B, CS20
			SETB TCCR2B, CS21
			CLRB TCCR2B, CS22
		.elif @0 == Prescaller32
			SETB TCCR2B, CS20
			SETB TCCR2B, CS21
			CLRB TCCR2B, CS22
		.elif @0 == Prescaller64
			CLRB TCCR2B, CS20
			CLRB TCCR2B, CS21
			SETB TCCR2B, CS22
		.elif @0 == Prescaller128
			SETB TCCR2B, CS20
			CLRB TCCR2B, CS21
			SETB TCCR2B, CS22
		.elif @0 == Prescaller256
			CLRB TCCR2B, CS20
			SETB TCCR2B, CS21
			SETB TCCR2B, CS22
		.elif @0 == Prescaller1024
			SETB TCCR2B, CS20
			SETB TCCR2B, CS21
			SETB TCCR2B, CS22
		.endif
	.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		.if @0 == Prescaller1
			SETB TCCR2A, CS20
			CLRB TCCR2A, CS21
			CLRB TCCR2A, CS22
		.elif @0 == Prescaller8
			CLRB TCCR2A, CS20
			SETB TCCR2A, CS21
			CLRB TCCR2A, CS22
		.elif @0 == Prescaller32
			SETB TCCR2A, CS20
			SETB TCCR2A, CS21
			CLRB TCCR2A, CS22
		.elif @0 == Prescaller64
			CLRB TCCR2A, CS20
			CLRB TCCR2A, CS21
			SETB TCCR2A, CS22
		.elif @0 == Prescaller128
			SETB TCCR2A, CS20
			CLRB TCCR2A, CS21
			SETB TCCR2A, CS22
		.elif @0 == Prescaller256
			CLRB TCCR2A, CS20
			SETB TCCR2A, CS21
			SETB TCCR2A, CS22
		.elif @0 == Prescaller1024
			SETB TCCR2A, CS20
			SETB TCCR2A, CS21
			SETB TCCR2A, CS22
		.endif
	.else
		.error "Counter 2 is not supporting by your controller!"
	.endif
.endm
