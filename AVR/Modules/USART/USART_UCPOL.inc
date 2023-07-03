.macro ClockPolar
	.if @0 == zero
		SETB UCSRC, URSEL
		CLRB UCSRC, UCPOL
		CLRB UCSRC, URSEL
	.elif @0 == one
		SETB UCSRC, URSEL
		SETB UCSRC, UCPOL
		CLRB UCSRC, URSEL
	.endif
.endm
.macro ClockPolarURSEL0
	.if @0 == zero
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UCPOL0
		CLRB UCSR0C, URSEL0
	.elif @0 == one
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UCPOL0
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro ClockPolarURSEL1
	.if @0 == zero
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UCPOL1
		CLRB UCSR1C, URSEL1
	.elif @0 == one
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UCPOL1
		CLRB UCSR1C, URSEL1
	.endif
.endm
.macro ClockPolar0
	.if @0 == zero
		CLRB UCSR0C, UCPOL0
	.elif @0 == one
		SETB UCSR0C, UCPOL0
	.endif
.endm
.macro ClockPolar1
	.if @0 == zero
		CLRB UCSR1C, UCPOL1
	.elif @0 == one
		SETB UCSR1C, UCPOL1
	.endif
.endm
.macro ClockPolar2
	.if @0 == zero
		CLRB UCSR2C, UCPOL2
	.elif @0 == one
		SETB UCSR2C, UCPOL2
	.endif
.endm
.macro ClockPolar3
	.if @0 == zero
		CLRB UCSR3C, UCPOL3
	.elif @0 == one
		SETB UCSR3C, UCPOL3
	.endif
.endm

.macro USARTClockPolarity
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
			ClockPolar @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0
			ClockPolar0 @1
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0
			ClockPolar0 @1
		.elif @0 == 1
			ClockPolar1 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0
			ClockPolarURSEL0 @1
		.elif @0 == 1
			ClockPolarURSEL1 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == 0
			ClockPolar0 @1
		.elif @0 == 1
			ClockPolar1 @1
		.elif @0 == 2
			ClockPolar2 @1
		.elif @0 == 3
			ClockPolar3 @1
		.endif
	.endif
.endm