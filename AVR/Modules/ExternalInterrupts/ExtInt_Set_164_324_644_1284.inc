.macro Enable_INT_Interrupt
	.if @0 == INT0
		.if @1 == LowLevel
			CLRB EICRA, ISC00
			CLRB EICRA, ISC01
		.elif @1 == LowLevel
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
	.elif @0 == INT1
		.if @1 == LowLevel
			CLRB EICRA, ISC10
			CLRB EICRA, ISC11
		.elif @1 == LowLevel
			CLRB EICRA, ISC10
			CLRB EICRA, ISC11
		.elif @1 == AnyEdge
			SETB EICRA, ISC10
			CLRB EICRA, ISC11
		.elif @1 == FallingEdge
			CLRB EICRA, ISC10
			SETB EICRA, ISC11
		.elif @1 == RisingEdge
			SETB EICRA, ISC10
			SETB EICRA, ISC11
		.endif 
	.elif @0 == INT2
		.if @1 == LowLevel
			CLRB EICRA, ISC20
			CLRB EICRA, ISC21
		.elif @1 == LowLevel
			CLRB EICRA, ISC20
			CLRB EICRA, ISC21
		.elif @1 == AnyEdge
			SETB EICRA, ISC20
			CLRB EICRA, ISC21
		.elif @1 == FallingEdge
			CLRB EICRA, ISC20
			SETB EICRA, ISC21
		.elif @1 == RisingEdge
			SETB EICRA, ISC20
			SETB EICRA, ISC21
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
	.elif @0 == INT1
		CLRB EICRA, ISC10
		CLRB EICRA, ISC11
	.elif @0 == INT2
		CLRB EICRA, ISC20
		CLRB EICRA, ISC21
	.endif
.endm
//---------------------------------------------------
.macro Enable_PCINT
	.if @0 == 0
		SETB PCMSK0, PCINT0
		SETB PCICR, PCIE0
	.elif @0 == 1
		SETB PCMSK0, PCINT1
		SETB PCICR, PCIE0
	.elif @0 == 2
		SETB PCMSK0, PCINT2
		SETB PCICR, PCIE0
	.elif @0 == 3
		SETB PCMSK0, PCINT3
		SETB PCICR, PCIE0
	.elif @0 == 4
		SETB PCMSK0, PCINT4
		SETB PCICR, PCIE0
	.elif @0 == 5
		SETB PCMSK0, PCINT5
		SETB PCICR, PCIE0
	.elif @0 == 6
		SETB PCMSK0, PCINT6
		SETB PCICR, PCIE0
	.elif @0 == 7
		SETB PCMSK0, PCINT7
		SETB PCICR, PCIE0
	.elif @0 == 8
		SETB PCMSK1, PCINT8
		SETB PCICR, PCIE1
	.elif @0 == 9
		SETB PCMSK1, PCINT9
		SETB PCICR, PCIE1
	.elif @0 == 10
		SETB PCMSK1, PCINT10
		SETB PCICR, PCIE1
	.elif @0 == 11
		SETB PCMSK1, PCINT11
		SETB PCICR, PCIE1
	.elif @0 == 12
		SETB PCMSK1, PCINT12
		SETB PCICR, PCIE1
	.elif @0 == 13
		SETB PCMSK1, PCINT13
		SETB PCICR, PCIE1
	.elif @0 == 14
		SETB PCMSK1, PCINT14
		SETB PCICR, PCIE1
	.elif @0 == 15
		SETB PCMSK1, PCINT15
		SETB PCICR, PCIE1
	.elif @0 == 16
		SETB PCMSK2, PCINT16
		SETB PCICR, PCIE2
	.elif @0 == 17
		SETB PCMSK2, PCINT17
		SETB PCICR, PCIE2
	.elif @0 == 18
		SETB PCMSK2, PCINT18
		SETB PCICR, PCIE2
	.elif @0 == 19
		SETB PCMSK2, PCINT19
		SETB PCICR, PCIE2
	.elif @0 == 20
		SETB PCMSK2, PCINT20
		SETB PCICR, PCIE2
	.elif @0 == 21
		SETB PCMSK2, PCINT21
		SETB PCICR, PCIE2
	.elif @0 == 22
		SETB PCMSK2, PCINT22
		SETB PCICR, PCIE2
	.elif @0 == 23
		SETB PCMSK2, PCINT23
		SETB PCICR, PCIE2
	.elif @0 == 24
		SETB PCMSK3, PCINT24
		SETB PCICR, PCIE3
	.elif @0 == 25
		SETB PCMSK3, PCINT25
		SETB PCICR, PCIE3
	.elif @0 == 26
		SETB PCMSK3, PCINT26
		SETB PCICR, PCIE3
	.elif @0 == 27
		SETB PCMSK3, PCINT27
		SETB PCICR, PCIE3
	.elif @0 == 28
		SETB PCMSK3, PCINT28
		SETB PCICR, PCIE3
	.elif @0 == 29
		SETB PCMSK3, PCINT29
		SETB PCICR, PCIE3
	.elif @0 == 30
		SETB PCMSK3, PCINT30
		SETB PCICR, PCIE3
	.elif @0 == 31
		SETB PCMSK3, PCINT31
		SETB PCICR, PCIE3
	.else
		.error "This PCINT pin not supported."
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
		CLRB PCICR, PCIE0
		PCMSK0_:
	.elif @0 == PCIE1
		READ_REG PCMSK1, r20
		CLRRB r20, @1
		cpse r20, r21
		rjmp PCMSK1_
		CLRB PCICR, PCIE1
		PCMSK1_:
	.elif @0 == PCIE2
		READ_REG PCMSK2, r20
		CLRRB r20, @1
		cpse r20, r21
		rjmp PCMSK2_
		CLRB PCICR, PCIE2
		PCMSK2_:
	.elif @0 == PCIE3
		READ_REG PCMSK3, r20
		CLRRB r20, @1
		cpse r20, r21
		rjmp PCMSK3_
		CLRB PCICR, PCIE3
		PCMSK3_:
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
	.elif @0 == 16
		Disable_PCIE PCIE2, PCINT16
		CLRB PCMSK2, PCINT16
	.elif @0 == 17
		Disable_PCIE PCIE2, PCINT17
		CLRB PCMSK2, PCINT17
	.elif @0 == 18
		Disable_PCIE PCIE2, PCINT18
		CLRB PCMSK2, PCINT18
	.elif @0 == 19
		Disable_PCIE PCIE2, PCINT19
		CLRB PCMSK2, PCINT19
	.elif @0 == 20
		Disable_PCIE PCIE2, PCINT20
		CLRB PCMSK2, PCINT20
	.elif @0 == 21
		Disable_PCIE PCIE2, PCINT21
		CLRB PCMSK2, PCINT21
	.elif @0 == 22
		Disable_PCIE PCIE2, PCINT22
		CLRB PCMSK2, PCINT22
	.elif @0 == 23
		Disable_PCIE PCIE2, PCINT23
		CLRB PCMSK2, PCINT23
	.elif @0 == 24
		Disable_PCIE PCIE3, PCINT24
		CLRB PCMSK3, PCINT24
	.elif @0 == 25
		Disable_PCIE PCIE3, PCINT25
		CLRB PCMSK3, PCINT25
	.elif @0 == 26
		Disable_PCIE PCIE3, PCINT26
		CLRB PCMSK3, PCINT26
	.elif @0 == 27
		Disable_PCIE PCIE3, PCINT27
		CLRB PCMSK3, PCINT27
	.elif @0 == 28
		Disable_PCIE PCIE3, PCINT28
		CLRB PCMSK3, PCINT28
	.elif @0 == 29
		Disable_PCIE PCIE3, PCINT29
		CLRB PCMSK3, PCINT29
	.elif @0 == 30
		Disable_PCIE PCIE3, PCINT30
		CLRB PCMSK3, PCINT30
	.elif @0 == 31
		Disable_PCIE PCIE3, PCINT31
		CLRB PCMSK3, PCINT31
	.else
		.error "This PCINT pin not supported."
	.endif
.endm

