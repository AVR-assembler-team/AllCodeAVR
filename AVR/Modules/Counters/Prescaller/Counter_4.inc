/*
*	@0 - претделитель	(Prescaller8 как пример)
*/
.macro CountersPrescallerCounter4
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1280 || ctrl == 2560 || ctrl == 2561
		.if @0 == Prescaller1
			SETB TCCR4B, CS40
			CLRB TCCR4B, CS41
			CLRB TCCR4B, CS42
		.elif @0 == Prescaller8
			CLRB TCCR4B, CS40
			SETB TCCR4B, CS41
			CLRB TCCR4B, CS42
		.elif @0 == Prescaller32
			.error "Prescaller 32 is not supporting by counter 4 of this controller!"
		.elif @0 == Prescaller64
			CLRB TCCR4B, CS40
			CLRB TCCR4B, CS41
			SETB TCCR4B, CS42
		.elif @0 == Prescaller128
			.error "Prescaller 128 is not supporting by counter 4 of this controller!"
		.elif @0 == Prescaller256
			CLRB TCCR4B, CS40
			SETB TCCR4B, CS41
			SETB TCCR4B, CS42
		.elif @0 == Prescaller1024
			SETB TCCR4B, CS40
			SETB TCCR4B, CS41
			SETB TCCR4B, CS42
		.endif
	.else
		.error "Counter 4 is not supporting by this controller!"
	.endif
.endm
