.macro CharacterSize
	.if @0 == 6
		SETB UCSRC, URSEL
		SETB UCSRC, UCSZ0
		CLRB UCSRC, UCSZ1
		CLRB UCSRC, URSEL
		CLRB UCSRB, UCSZ2
	.elif @0 == 7
		SETB UCSRC, URSEL
		CLRB UCSRC, UCSZ0
		SETB UCSRC, UCSZ1
		CLRB UCSRC, URSEL
		CLRB UCSRB, UCSZ2
	.elif @0 == 8
		SETB UCSRC, URSEL
		SETB UCSRC, UCSZ0
		SETB UCSRC, UCSZ1
		CLRB UCSRC, URSEL
		CLRB UCSRB, UCSZ2
	.elif @0 == 9
		SETB UCSRC, URSEL
		SETB UCSRC, UCSZ0
		SETB UCSRC, UCSZ1
		CLRB UCSRC, URSEL
		SETB UCSRB, UCSZ2
	.endif
.endm
.macro CharacterSizeURSEL0
	.if @0 == 6
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UCSZ00
		CLRB UCSR0C, UCSZ01
		CLRB UCSR0C, URSEL0
		CLRB UCSR0B, UCSZ02
	.elif @0 == 7
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		CLRB UCSR0C, URSEL0
		CLRB UCSR0B, UCSZ02
	.elif @0 == 8
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		CLRB UCSR0C, URSEL0
		CLRB UCSR0B, UCSZ02
	.elif @0 == 9
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		CLRB UCSR0C, URSEL0
		SETB UCSR0B, UCSZ02
	.endif
.endm
.macro CharacterSizeURSEL1
	.if @0 == 6
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UCSZ10
		CLRB UCSR1C, UCSZ11
		CLRB UCSR1C, URSEL1
		CLRB UCSR1B, UCSZ12
	.elif @0 == 7
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		CLRB UCSR1C, URSEL1
		CLRB UCSR1B, UCSZ12
	.elif @0 == 8
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		CLRB UCSR1C, URSEL1
		CLRB UCSR1B, UCSZ12
	.elif @0 == 9
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		CLRB UCSR1C, URSEL1
		SETB UCSR1B, UCSZ12
	.endif
.endm
.macro CharacterSize0
	.if @0 == 6
		SETB UCSR0C, UCSZ00
		CLRB UCSR0C, UCSZ01
		CLRB UCSR0B, UCSZ02
	.elif @0 == 7
		CLRB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		CLRB UCSR0B, UCSZ02
	.elif @0 == 8
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		CLRB UCSR0B, UCSZ02
	.elif @0 == 9
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR0B, UCSZ02
	.endif
.endm
.macro CharacterSize1
	.if @0 == 6
		SETB UCSR1C, UCSZ10
		CLRB UCSR1C, UCSZ11
		CLRB UCSR1B, UCSZ12
	.elif @0 == 7
		CLRB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		CLRB UCSR1B, UCSZ12
	.elif @0 == 8
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		CLRB UCSR1B, UCSZ12
	.elif @0 == 9
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		SETB UCSR1B, UCSZ12
	.endif
.endm
.macro CharacterSize2
	.if @0 == 6
		SETB UCSR2C, UCSZ20
		CLRB UCSR2C, UCSZ21
		CLRB UCSR2B, UCSZ22
	.elif @0 == 7
		CLRB UCSR2C, UCSZ20
		SETB UCSR2C, UCSZ21
		CLRB UCSR2B, UCSZ22
	.elif @0 == 8
		SETB UCSR2C, UCSZ20
		SETB UCSR2C, UCSZ21
		CLRB UCSR2B, UCSZ22
	.elif @0 == 9
		SETB UCSR2C, UCSZ20
		SETB UCSR2C, UCSZ21
		SETB UCSR2B, UCSZ22
	.endif
.endm
.macro CharacterSize3
	.if @0 == 6
		SETB UCSR3C, UCSZ30
		CLRB UCSR3C, UCSZ31
		CLRB UCSR3B, UCSZ32
	.elif @0 == 7
		CLRB UCSR3C, UCSZ30
		SETB UCSR3C, UCSZ31
		CLRB UCSR3B, UCSZ32
	.elif @0 == 8
		SETB UCSR3C, UCSZ30
		SETB UCSR3C, UCSZ31
		CLRB UCSR3B, UCSZ32
	.elif @0 == 9
		SETB UCSR3C, UCSZ30
		SETB UCSR3C, UCSZ31
		SETB UCSR3B, UCSZ32
	.endif
.endm



.macro USARTCharacterSize
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
			CharacterSize @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0
			CharacterSize0 @1
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0
			CharacterSize0 @1
		.elif @0 == 1
			CharacterSize1 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0
			CharacterSizeURSEL0 @1
		.elif @0 == 1
			CharacterSizeURSEL1 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == 0
			CharacterSize0 @1
		.elif @0 == 1
			CharacterSize1 @1
		.elif @0 == 2
			CharacterSize2 @1
		.elif @0 == 3
			CharacterSize3 @1
		.endif
	.endif
.endm