.macro Enable_INT_Interrupt
	.if @0 == INT0
		.if @1 == LowLevel
			CLRB EICRA, ISC00
			CLRB EICRA, ISC01
		.elif @1 == AnyEdge
			SETB EICRA, ISC00
			CLRB EICRA, ISC01
		.elif @1 == FallingEdge
			CLRB EICRA, ISC00
			SETB EICRA, ISC01
		.elif @1 == RisingEdge
			SETB EICRA, ISC00
			SETB EICRA, ISC01
		.endif 
	.endif
	SETB EIMSK, @0
.endm
//---------------------------------------------
.macro Disable_INT_Interrupt
	CLRB EIMSK, @0
	.if @0 == INT0
		CLRB EICRA, ISC00
		CLRB EICRA, ISC01
	.endif
.endm
//---------------------------------------------------
.macro Enable_PCINT
	.if @0 == 0
		SETB PCMSK0, PCINT0
		SETB EIMSK, PCIE0
	.elif @0 == 1
		SETB PCMSK0, PCINT1
		SETB EIMSK, PCIE0
	.elif @0 == 2
		SETB PCMSK0, PCINT2
		SETB EIMSK, PCIE0
	.elif @0 == 3
		SETB PCMSK0, PCINT3
		SETB EIMSK, PCIE0
	.elif @0 == 4
		SETB PCMSK0, PCINT4
		SETB EIMSK, PCIE0
	.elif @0 == 5
		SETB PCMSK0, PCINT5
		SETB EIMSK, PCIE0
	.elif @0 == 6
		SETB PCMSK0, PCINT6
		SETB EIMSK, PCIE0
	.elif @0 == 7
		SETB PCMSK0, PCINT7
		SETB EIMSK, PCIE0
	.elif @0 == 8
		SETB PCMSK1, PCINT8
		SETB EIMSK, PCIE1
	.elif @0 == 9
		SETB PCMSK1, PCINT9
		SETB EIMSK, PCIE1
	.elif @0 == 10
		SETB PCMSK1, PCINT10
		SETB EIMSK, PCIE1
	.elif @0 == 11
		SETB PCMSK1, PCINT11
		SETB EIMSK, PCIE1
	.elif @0 == 12
		SETB PCMSK1, PCINT12
		SETB EIMSK, PCIE1
	.elif @0 == 13
		SETB PCMSK1, PCINT13
		SETB EIMSK, PCIE1
	.elif @0 == 14
		SETB PCMSK1, PCINT14
		SETB EIMSK, PCIE1
	.elif @0 == 15
		SETB PCMSK1, PCINT15
		SETB EIMSK, PCIE1
	.else
		.error "PCINT pin not supported."
	.endif
.endm
//---------------------------------------------------
.macro Disable_PCIE
	push r20
	push r21
	clr r21

	.if @0 == PCIE0
		READ_REG PCMSK0, r20
		CLRRB r20, @1
		cpse r20, r21
		rjmp PCMSK0_
		CLRB EIMSK, PCIE0
		PCMSK0_:
	.elif @0 == PCIE1
		READ_REG PCMSK1, r20
		CLRRB r20, @1
		cpse r20, r21
		rjmp PCMSK1_
		CLRB EIMSK, PCIE1
		PCMSK1_:
	.endif

	pop r21
	pop r20
.endm
.macro Disable_PCINT
	.if @0 == 0
		Disable_PCIE PCIE0, PCINT0
		CLRB PCMSK0, PCINT0
	.elif @0 == 1
		Disable_PCIE PCIE0, PCINT1
		CLRB PCMSK0, PCINT1
	.elif @0 == 2
		Disable_PCIE PCIE0, PCINT2
		CLRB PCMSK0, PCINT2
	.elif @0 == 3
		Disable_PCIE PCIE0, PCINT3
		CLRB PCMSK0, PCINT3
	.elif @0 == 4
		Disable_PCIE PCIE0, PCINT4
		CLRB PCMSK0, PCINT4
	.elif @0 == 5
		Disable_PCIE PCIE0, PCINT5
		CLRB PCMSK0, PCINT5
	.elif @0 == 6
		Disable_PCIE PCIE0, PCINT6
		CLRB PCMSK0, PCINT6
	.elif @0 == 7
		Disable_PCIE PCIE0, PCINT7
		CLRB PCMSK0, PCINT7
	.elif @0 == 8
		Disable_PCIE PCIE1, PCINT8
		CLRB PCMSK1, PCINT8
	.elif @0 == 9
		Disable_PCIE PCIE1, PCINT9
		CLRB PCMSK1, PCINT9
	.elif @0 == 10
		Disable_PCIE PCIE1, PCINT10
		CLRB PCMSK1, PCINT10
	.elif @0 == 11
		Disable_PCIE PCIE1, PCINT11
		CLRB PCMSK1, PCINT11
	.elif @0 == 12
		Disable_PCIE PCIE1, PCINT12
		CLRB PCMSK1, PCINT12
	.elif @0 == 13
		Disable_PCIE PCIE1, PCINT13
		CLRB PCMSK1, PCINT13
	.elif @0 == 14
		Disable_PCIE PCIE1, PCINT14
		CLRB PCMSK1, PCINT14
	.elif @0 == 15
		Disable_PCIE PCIE1, PCINT15
		CLRB PCMSK1, PCINT15
	.else
		.error "PCINT pin not supported."
	.endif
.endm

.macro SetINT
	
.endm
