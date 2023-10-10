/*
*	@0 - претделитель	(Prescaller8 как пример)
*/

.macro TimersPrescallerCounter5
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1280 || ctrl == 2560 || ctrl == 2561
		.if @0 == Prescaller1
			SETB TCCR5B, CS50
			CLRB TCCR5B, CS51
			CLRB TCCR5B, CS52
		.elif @0 == Prescaller8
			CLRB TCCR5B, CS50
			SETB TCCR5B, CS51
			CLRB TCCR5B, CS52
		.elif @0 == Prescaller32
			.error "Prescaller 32 is not supporting by counter 5 of this controller!"
		.elif @0 == Prescaller64
			CLRB TCCR5B, CS50
			CLRB TCCR5B, CS51
			SETB TCCR5B, CS52
		.elif @0 == Prescaller128
			.error "Prescaller 128 is not supporting by counter 5 of this controller!"
		.elif @0 == Prescaller256
			CLRB TCCR5B, CS50
			SETB TCCR5B, CS51
			SETB TCCR5B, CS52
		.elif @0 == Prescaller1024
			SETB TCCR5B, CS50
			SETB TCCR5B, CS51
			SETB TCCR5B, CS52
		.endif
	.else
		.error "Counter 4 is not supporting by this controller!"
	.endif
.endm
