.macro ParityMode
	.if @0 == disabled
		SETB UCSRC, URSEL
		CLRB UCSRC, UPM0
		CLRB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.elif @0 == evenParity
		SETB UCSRC, URSEL
		CLRB UCSRC, UPM0
		SETB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.elif @0 == oddParity
		SETB UCSRC, URSEL
		SETB UCSRC, UPM0
		SETB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.endif
.endm
.macro ParityMode0
	.if @0 == disabled
		CLRB UCSR0C, UPM00
		CLRB UCSR0C, UPM01
	.elif @0 == evenParity
		CLRB UCSR0C, UPM00
		SETB UCSR0C, UPM01
	.elif @0 == oddParity
		SETB UCSR0C, UPM00
		SETB UCSR0C, UPM01
	.endif
.endm
.macro ParityModeURSEL0
	.if @0 == disabled
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UPM00
		CLRB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.elif @0 == evenParity
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UPM00
		SETB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.elif @0 == oddParity
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UPM00
		SETB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro ParityMode1
	.if @0 == disabled
		CLRB UCSR1C, UPM10
		CLRB UCSR1C, UPM11
	.elif @0 == evenParity
		CLRB UCSR1C, UPM10
		SETB UCSR1C, UPM11
	.elif @0 == oddParity
		SETB UCSR1C, UPM10
		SETB UCSR1C, UPM11
	.endif
.endm
.macro ParityModeURSEL1
	.if @0 == disabled
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UPM10
		CLRB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.elif @0 == evenParity
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UPM10
		SETB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.elif @0 == oddParity
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UPM10
		SETB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.endif
.endm
.macro ParityMode2
	.if @0 == disabled
		CLRB UCSR2C, UPM20
		CLRB UCSR2C, UPM21
	.elif @0 == evenParity
		CLRB UCSR2C, UPM20
		SETB UCSR2C, UPM21
	.elif @0 == oddParity
		SETB UCSR2C, UPM20
		SETB UCSR2C, UPM21
	.endif
.endm
	.macro ParityMode3
	.if @0 == disabled
		CLRB UCSR3C, UPM30
		CLRB UCSR3C, UPM31
	.elif @0 == evenParity
		CLRB UCSR3C, UPM30
		SETB UCSR3C, UPM31
	.elif @0 == oddParity
		SETB UCSR3C, UPM30
		SETB UCSR3C, UPM31
	.endif
.endm
    
    
.macro USARTParityMode
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
		ParityMode @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0
		ParityMode0 @1
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0
		ParityMode0 @1
		.elif @0 == 1
		ParityMode1 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0
			ParityModeURSEL0 @1
		.elif @0 == 1
			ParityModeURSEL1 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == 0
		ParityMode0 @1
		.elif @0 == 1
		ParityMode1 @1
		.elif @0 == 2
		ParityMode2 @1
		.elif @0 == 3
		ParityMode3 @1
		.endif
	.endif
.endm
