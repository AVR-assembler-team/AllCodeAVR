/*
*	@0 - претделитель	(Prescaller8 как пример)
*/

.macro TimersPrescallerCounter3
	.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == Prescaller1
			SETB TCCR3B, CS30
			CLRB TCCR3B, CS31
			CLRB TCCR3B, CS32
		.elif @0 == Prescaller8
			CLRB TCCR3B, CS30
			SETB TCCR3B, CS31
			CLRB TCCR3B, CS32
		.elif @0 == Prescaller32
			.error "Prescaller 32 is not supporting by counter 3 of this controller!"
		.elif @0 == Prescaller64
			CLRB TCCR3B, CS30
			CLRB TCCR3B, CS31
			SETB TCCR3B, CS32
		.elif @0 == Prescaller128
			.error "Prescaller 128 is not supporting by counter 3 of this controller!"
		.elif @0 == Prescaller256
			CLRB TCCR3B, CS30
			SETB TCCR3B, CS31
			SETB TCCR3B, CS32
		.elif @0 == Prescaller1024
			SETB TCCR3B, CS30
			SETB TCCR3B, CS31
			SETB TCCR3B, CS32
		.endif
	.else
		.error "Counter 3 in not supported by this controller!"
	.endif
.endm
