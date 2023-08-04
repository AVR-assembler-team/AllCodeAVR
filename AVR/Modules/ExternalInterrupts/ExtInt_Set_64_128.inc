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
	.elif @0 == INT1
		.if @1 == LowLevel
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
	.elif @0 == INT3
		.if @1 == LowLevel
			CLRB EICRA, ISC30
			CLRB EICRA, ISC31
		.elif @1 == AnyEdge
			SETB EICRA, ISC30
			CLRB EICRA, ISC31
		.elif @1 == FallingEdge
			CLRB EICRA, ISC30
			SETB EICRA, ISC31
		.elif @1 == RisingEdge
			SETB EICRA, ISC30
			SETB EICRA, ISC31
		.endif 
	.elif @0 == INT4
		.if @1 == LowLevel
			CLRB EICRB, ISC40
			CLRB EICRB, ISC41
		.elif @1 == AnyEdge
			SETB EICRB, ISC40
			CLRB EICRB, ISC41
		.elif @1 == FallingEdge
			CLRB EICRB, ISC40
			SETB EICRB, ISC41
		.elif @1 == RisingEdge
			SETB EICRB, ISC40
			SETB EICRB, ISC41
		.endif 
	.elif @0 == INT5
		.if @1 == LowLevel
			CLRB EICRB, ISC50
			CLRB EICRB, ISC51
		.elif @1 == AnyEdge
			SETB EICRB, ISC50
			CLRB EICRB, ISC51
		.elif @1 == FallingEdge
			CLRB EICRB, ISC50
			SETB EICRB, ISC51
		.elif @1 == RisingEdge
			SETB EICRB, ISC50
			SETB EICRB, ISC51
		.endif 
	.elif @0 == INT6
		.if @1 == LowLevel
			CLRB EICRB, ISC60
			CLRB EICRB, ISC61
		.elif @1 == AnyEdge
			SETB EICRB, ISC60
			CLRB EICRB, ISC61
		.elif @1 == FallingEdge
			CLRB EICRB, ISC60
			SETB EICRB, ISC61
		.elif @1 == RisingEdge
			SETB EICRB, ISC60
			SETB EICRB, ISC61
		.endif 
	.elif @0 == INT7
		.if @1 == LowLevel
			CLRB EICRB, ISC70
			CLRB EICRB, ISC71
		.elif @1 == AnyEdge
			SETB EICRB, ISC70
			CLRB EICRB, ISC71
		.elif @1 == FallingEdge
			CLRB EICRB, ISC70
			SETB EICRB, ISC71
		.elif @1 == RisingEdge
			SETB EICRB, ISC70
			SETB EICRB, ISC71
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
	.elif @0 == INT3
		CLRB EICRA, ISC30
		CLRB EICRA, ISC31
	.elif @0 == INT4
		CLRB EICRB, ISC40
		CLRB EICRB, ISC41
	.elif @0 == INT5
		CLRB EICRB, ISC50
		CLRB EICRB, ISC51
	.elif @0 == INT6
		CLRB EICRB, ISC60
		CLRB EICRB, ISC61
	.elif @0 == INT7
		CLRB EICRB, ISC70
		CLRB EICRB, ISC71
	.endif
.endm
//---------------------------------------------------
.macro Enable_PCINT
	.error "Any PCINT pins are not supported."
.endm
//---------------------------------------------------
.macro Disable_PCINT
	.error "Any PCINT pins are not supported."
.endm

