.macro INTSet
	.if @0 == LowLevel
		CLRB @3, @4
		CLRB @3, @5
	.elif @0 == AnyEdge
		SETB @3, @4
		CLRB @3, @5
	.elif @0 == FallingEdge
		CLRB @3, @4
		SETB @3, @5
	.elif @0 == RisingEdge
		SETB @3, @4
		SETB @3, @5
	.endif
	SETB @1, @2
.endm

.macro ExtInterINTEnable
	.if ctlr == 8
		.if @0 == INT0
			INTSet @1, GICR, INT0, MCUCR, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, GICR, INT1, MCUCR, ISC10, ISC11
		.endif
		.if @0 == INT2
			.error "INT2 not axist!"
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.elif ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == INT0
			INTSet @1, GICR, INT0, MCUCR, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, GICR, INT1, MCUCR, ISC10, ISC11
		.endif
		.if @0 == INT2
			SETB GICR, INT2
			.if @1 == LowLevel
				.error "INT2 Sense Control not available!"
			.elif @1 == AnyEdge
				.error "INT2 Sense Control not available!"
			.elif @1 == FallingEdge
				CLRB MCUCSR, ISC2
			.elif @1 == RisingEdge
				SETB MCUCSR, ISC2
			.endif
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 168 || ctlr == 328
		.if @0 == INT0
			INTSet @1, EIMSK, INT0, EICRA, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, EIMSK, INT1, EICRA, ISC10, ISC11
		.endif
		.if @0 == INT2
			.error "INT2 not axist!"
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == INT0
			INTSet @1, EIMSK, INT0, EICRA, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, EIMSK, INT1, EICRA, ISC10, ISC11
		.endif
		.if @0 == INT2
			INTSet @1, EIMSK, INT2, EICRA, ISC20, ISC21
		.endif
		.if @0 == INT3
			INTSet @1, EIMSK, INT3, EICRA, ISC30, ISC31
		.endif
		.if @0 == INT4
			INTSet @1, EIMSK, INT4, EICRB, ISC40, ISC41
		.endif
		.if @0 == INT5
			INTSet @1, EIMSK, INT5, EICRB, ISC50, ISC51
		.endif
		.if @0 == INT6
			INTSet @1, EIMSK, INT6, EICRB, ISC60, ISC61
		.endif
		.if @0 == INT7
			INTSet @1, EIMSK, INT7, EICRB, ISC70, ISC71
		.endif
	.elif ctlr == 162
		.if @0 == INT0
			INTSet @1, GICR, INT0, MCUCR, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, GICR, INT1, MCUCR, ISC10, ISC11
		.endif
		.if @0 == INT2
			SETB GICR, INT2
			.if @1 == LowLevel
				.error "INT2 Sense Control not available!"
			.elif @1 == AnyEdge
				.error "INT2 Sense Control not available!"
			.elif @1 == FallingEdge
				CLRB EMCUCR, ISC2
			.elif @1 == RisingEdge
				SETB EMCUCR, ISC2
			.else
				.error "INT2 Sense Control not recognized!"
			.endif
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.elif ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == INT0
			INTSet @1, EIMSK, INT0, EICRA, ISC00, ISC01
		.endif
		.if @0 == INT1
			INTSet @1, EIMSK, INT1, EICRA, ISC10, ISC11
		.endif
		.if @0 == INT2
			INTSet @1, EIMSK, INT2, EICRA, ISC20, ISC21
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.elif ctlr == 165 || ctlr == 169 || ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450 || ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
		.if @0 == INT0
			INTSet @1, EIMSK, INT0, EICRA, ISC00, ISC01
		.endif
		.if @0 == INT1
			.error "INT1 not axist!"
		.endif
		.if @0 == INT2
			.error "INT2 not axist!"
		.endif
		.if @0 == INT3
			.error "INT3 not axist!"
		.endif
		.if @0 == INT4
			.error "INT4 not axist!"
		.endif
		.if @0 == INT5
			.error "INT5 not axist!"
		.endif
		.if @0 == INT6
			.error "INT6 not axist!"
		.endif
		.if @0 == INT7
			.error "INT7 not axist!"
		.endif
	.endif
.endm
