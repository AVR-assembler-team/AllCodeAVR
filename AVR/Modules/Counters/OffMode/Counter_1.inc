.macro CountersOffModeCounter1
	CLRB TCCR1B, CS10
	CLRB TCCR1B, CS11
	CLRB TCCR1B, CS12
.endm
