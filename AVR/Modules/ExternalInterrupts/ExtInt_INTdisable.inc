
.macro ExtInterINTDisable
	.if ctlr == 8
		.if @0 == INT0
			CLRB GICR, INT0
		.endif
		.if @0 == INT1
			CLRB GICR, INT1
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
			CLRB GICR, INT0
		.endif
		.if @0 == INT1
			CLRB GICR, INT1
		.endif
		.if @0 == INT2
			CLRB GICR, INT2
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
			CLRB EIMSK, INT0
		.endif
		.if @0 == INT1
			CLRB EIMSK, INT1
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
			CLRB EIMSK, INT0
		.endif
		.if @0 == INT1
			CLRB EIMSK, INT1
		.endif
		.if @0 == INT2
			CLRB EIMSK, INT2
		.endif
		.if @0 == INT3
			CLRB EIMSK, INT3
		.endif
		.if @0 == INT4
			CLRB EIMSK, INT4
		.endif
		.if @0 == INT5
			CLRB EIMSK, INT5
		.endif
		.if @0 == INT6
			CLRB EIMSK, INT6
		.endif
		.if @0 == INT7
			CLRB EIMSK, INT7
		.endif
	.elif ctlr == 162
		.if @0 == INT0
			CLRB GICR, INT0
		.endif
		.if @0 == INT1
			CLRB GICR, INT1
		.endif
		.if @0 == INT2
			CLRB GICR, INT2
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
			CLRB EIMSK, INT0
		.endif
		.if @0 == INT1
			CLRB EIMSK, INT1
		.endif
		.if @0 == INT2
			CLRB EIMSK, INT2
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
			CLRB EIMSK, INT0
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
