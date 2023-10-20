.macro CountersCompareOutputModeCounter4
	.if @0 == CompareMatchOutput
		.error "Compare Output Mode is not supporting by counter 5 of this controller!"
	.elif @0 == CompareMatchOutputA
		.if @1 == 0
			CLRB TCCR4A, COM4A0 
			CLRB TCCR4A, COM4A1
		.elif @1 == 1
			SETB TCCR4A, COM4A0
			CLRB TCCR4A, COM4A1
		.elif @1 == 2
			CLRB TCCR4A, COM4A0
			SETB TCCR4A, COM4A1
		.elif @1 == 3
			SETB TCCR4A, COM4A0
			SETB TCCR4A, COM4A1
		.endif
	.elif @0 == CompareMatchOutputB
		.if @1 == 0
			CLRB TCCR4A, COM4B0 
			CLRB TCCR4A, COM4B1
		.elif @1 == 1
			SETB TCCR4A, COM4B0
			CLRB TCCR4A, COM4B1
		.elif @1 == 2
			CLRB TCCR4A, COM4B0
			SETB TCCR4A, COM4B1
		.elif @1 == 3
			SETB TCCR4A, COM4B0
			SETB TCCR4A, COM4B1
		.endif
	.elif @0 == CompareMatchOutputC
		.if @1 == 0
			CLRB TCCR4A, COM4C0 
			CLRB TCCR4A, COM4C1
		.elif @1 == 1
			SETB TCCR4A, COM4C0
			CLRB TCCR4A, COM4C1
		.elif @1 == 2
			CLRB TCCR4A, COM4C0
			SETB TCCR4A, COM4C1
		.elif @1 == 3
			SETB TCCR4A, COM4C0
			SETB TCCR4A, COM4C1
		.endif
	.endif
.endm
