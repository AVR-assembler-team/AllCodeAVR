.macro Enable_INT_Interrupt
	.if @0 == INT0
		.if @1 == AnyEdge
			SETB MCUCR, ISC00
			CLRB MCUCR, ISC01
		.elif @1 == FallingEdge
			CLRB MCUCR, ISC00
			SETB MCUCR, ISC01
		.elif @1 == RisingEdge
			SETB MCUCR, ISC00
			SETB MCUCR, ISC01
		.endif 
	.elif @0 == INT1
		.if @1 == AnyEdge
			SETB MCUCR, ISC10
			CLRB MCUCR, ISC11
		.elif @1 == FallingEdge
			CLRB MCUCR, ISC10
			SETB MCUCR, ISC11
		.elif @1 == RisingEdge
			SETB MCUCR, ISC10
			SETB MCUCR, ISC11
		.endif 
	.elif @0 == INT2
		.if @1 == AnyEdge
			.error "Edge not supported!"
		.elif @1 == FallingEdge
			CLRB MCUCSR, ISC2
		.elif @1 == RisingEdge
			SETB MCUCSR, ISC2
		.endif 
	.endif
	SETB GICR, @0
.endm
//---------------------------------------------
.macro Disable_INT_Interrupt
	CLRB GICR, @0
	.if @0 == INT0
		CLRB MCUCR, ISC00
		CLRB MCUCR, ISC01
	.elif @0 == INT1
		CLRB MCUCR, ISC10
		CLRB MCUCR, ISC11
	.elif @0 == INT2
		CLRB MCUCSR, ISC2
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
