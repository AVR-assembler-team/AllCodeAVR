/*
*	@0 - претделитель	(Prescaller8 как пример)
*/

.macro TimersPrescallerCounter1
	.if @0 == Prescaller1
		SETB TCCR1B, CS10
		CLRB TCCR1B, CS11
		CLRB TCCR1B, CS12
	.elif @0 == Prescaller8
		CLRB TCCR1B, CS10
		SETB TCCR1B, CS11
		CLRB TCCR1B, CS12
	.elif @0 == Prescaller32
		.error "Prescaller 32 is not supporting by counter 1 of this controller!"
	.elif @0 == Prescaller64
		CLRB TCCR1B, CS10
		CLRB TCCR1B, CS11
		SETB TCCR1B, CS12
	.elif @0 == Prescaller128
		.error "Prescaller 128 is not supporting by counter 1 of this controller!"
	.elif @0 == Prescaller256
		CLRB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.elif @0 == Prescaller1024
		SETB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.endif
.endm
