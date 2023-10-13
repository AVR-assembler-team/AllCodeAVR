.macro CountersCompareOutputModeCounter5
	.if @0 == CompareMatchOutput
		.error "Compare Output Mode is not supporting by counter 5 of this controller!"
	.elif @0 == CompareMatchOutputA
		.if @1 == 0
			CLRB TCCR5A, COM5A0 
			CLRB TCCR5A, COM5A1
		.elif @1 == 1
			SETB TCCR5A, COM5A0
			CLRB TCCR5A, COM5A1
		.elif @1 == 2
			CLRB TCCR5A, COM5A0
			SETB TCCR5A, COM5A1
		.elif @1 == 3
			SETB TCCR5A, COM5A0
			SETB TCCR5A, COM5A1
		.endif
	.elif @0 == CompareMatchOutputB
		.if @1 == 0
			CLRB TCCR5A, COM5B0
			CLRB TCCR5A, COM5B1
		.elif @1 == 1
			SETB TCCR5A, COM5B0
			CLRB TCCR5A, COM5B1
		.elif @1 == 2
			CLRB TCCR5A, COM5B0
			SETB TCCR5A, COM5B1
		.elif @1 == 3
			SETB TCCR5A, COM5B0
			SETB TCCR5A, COM5B1
		.endif
	.elif @0 == CompareMatchOutputC
		.if @1 == 0
			CLRB TCCR5A, COM5C0 
			CLRB TCCR5A, COM5C1
		.elif @1 == 1
			SETB TCCR5A, COM5C0
			CLRB TCCR5A, COM5C1
		.elif @1 == 2
			CLRB TCCR5A, COM5C0
			SETB TCCR5A, COM5C1
		.elif @1 == 3
			SETB TCCR5A, COM5C0
			SETB TCCR5A, COM5C1
		.endif
	.endif
.endm
