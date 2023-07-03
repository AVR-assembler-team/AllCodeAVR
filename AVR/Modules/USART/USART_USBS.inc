.macro StopBits
	.if @0 == one
		SETB UCSRC, URSEL
		CLRB UCSRC, USBS
		CLRB UCSRC, URSEL
	.elif @0 == two
		SETB UCSRC, URSEL
		SETB UCSRC, USBS
		CLRB UCSRC, URSEL
	.endif
.endm 
.macro StopBitsURSEL0
	.if @0 == one
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, USBS0
		CLRB UCSR0C, URSEL0
	.elif @0 == two
		SETB UCSR0C, URSEL0
		SETB UCSR0C, USBS0
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro StopBitsURSEL1
	.if @0 == one
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, USBS1
		CLRB UCSR1C, URSEL1
	.elif @0 == two
		SETB UCSR1C, URSEL1
		SETB UCSR1C, USBS1
		CLRB UCSR1C, URSEL1
	.endif
.endm 
.macro StopBits0
	.if @0 == one
		CLRB UCSR0C, USBS0
	.elif @0 == two
		SETB UCSR0C, USBS0
	.endif
.endm
.macro StopBits1
	.if @0 == one
		CLRB UCSR1C, USBS1
	.elif @0 == two
		SETB UCSR1C, USBS1
	.endif
.endm
.macro StopBits2
	.if @0 == one
		CLRB UCSR2C, USBS2
	.elif @0 == two
		SETB UCSR2C, USBS2
	.endif
.endm
.macro StopBits3
	.if @0 == one
		CLRB UCSR3C, USBS3
	.elif @0 == two
		SETB UCSR3C, USBS3
	.endif
.endm

.macro USARTStopBits
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
			StopBits @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0
			StopBits0 @1
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0
			StopBits0 @1
		.elif @0 == 1
			StopBits1 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0
			StopBitsURSEL0 @1
		.elif @0 == 1
			StopBitsURSEL1 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == 0
			StopBits0 @1
		.elif @0 == 1
			StopBits1 @1
		.elif @0 == 2
			StopBits2 @1
		.elif @0 == 3
			StopBits3 @1
		.endif
	.endif
.endm