/*
*	@0 - претделитель	(Prescaller8 как пример)
*/
.macro ClockSelectCounter1
	.if @0 == ClockSelect0
		CLRB TCCR1B, CS10
		CLRB TCCR1B, CS11
		CLRB TCCR1B, CS12
	.elif @0 == ClockSelect1
		SETB TCCR1B, CS10
		CLRB TCCR1B, CS11
		CLRB TCCR1B, CS12
	.elif @0 == ClockSelect2
		CLRB TCCR1B, CS10
		SETB TCCR1B, CS11
		CLRB TCCR1B, CS12
	.elif @0 == ClockSelect3
		.error "Prescaller 32 is not supporting by counter 1 of this controller!"
	.elif @0 == ClockSelect4
		CLRB TCCR1B, CS10
		CLRB TCCR1B, CS11
		SETB TCCR1B, CS12
	.elif @0 == ClockSelect5
		.error "Prescaller 128 is not supporting by counter 1 of this controller!"
	.elif @0 == ClockSelect6
		CLRB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.elif @0 == ClockSelect7
		SETB TCCR1B, CS10
		SETB TCCR1B, CS11
		SETB TCCR1B, CS12
	.endif
.endm
