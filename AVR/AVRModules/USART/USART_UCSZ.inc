.macro CharacterSize
	READ_REG UCSRC, r25
	READ_REG UCSRB, r24
	.if @0 == 6
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, UCSZ0
		CLRRB r25, UCSZ1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r24, UCSZ2
	.elif @0 == 7
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, UCSZ0
		SETRB r25, UCSZ1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r24, UCSZ2
	.elif @0 == 8
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, UCSZ0
		SETRB r25, UCSZ1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r24, UCSZ2
	.elif @0 == 9
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, UCSZ0
		SETRB r25, UCSZ1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r24, UCSZ2
	.endif
	WRITE_REG UCSRB, r24
.endm
.macro CharacterSizeURSEL0
	READ_REG UCSR0C, r25
	READ_REG UCSR0B, r24
	.if @0 == 6
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, UCSZ00
		CLRRB r25, UCSZ01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r24, UCSZ02
	.elif @0 == 7
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, UCSZ00
		SETRB r25, UCSZ01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r24, UCSZ02
	.elif @0 == 8
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, UCSZ00
		SETRB r25, UCSZ01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r24, UCSZ02
	.elif @0 == 9
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, UCSZ00
		SETRB r25, UCSZ01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r24, UCSZ02
	.endif
	WRITE_REG UCSR0B, r24
.endm
.macro CharacterSizeURSEL1
	READ_REG UCSR1C, r25
	READ_REG UCSR1B, r24
	.if @0 == 6
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r25, UCSZ10
		CLRRB r25, UCSZ11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r24, UCSZ12
	.elif @0 == 7
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r25, UCSZ10
		SETRB r25, UCSZ11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r24, UCSZ12
	.elif @0 == 8
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r25, UCSZ10
		SETRB r25, UCSZ11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r24, UCSZ12
	.elif @0 == 9
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r25, UCSZ10
		SETRB r25, UCSZ11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r24, UCSZ12
	.endif
	WRITE_REG UCSR1B, r24
.endm
.macro CharacterSize0
	READ_REG UCSR0C, r25
	READ_REG UCSR0B, r24
	.if @0 == 6
		SETRB r25, UCSZ00
		CLRRB r25, UCSZ01
		CLRRB r24, UCSZ02
	.elif @0 == 7
		CLRRB r25, UCSZ00
		SETRB r25, UCSZ01
		CLRRB r24, UCSZ02
	.elif @0 == 8
		SETRB r25, UCSZ00
		SETRB r25, UCSZ01
		CLRRB r24, UCSZ02
	.elif @0 == 9
		SETRB r25, UCSZ00
		SETRB r25, UCSZ01
		SETRB r24, UCSZ02
	.endif
	WRITE_REG UCSR0C, r25
	WRITE_REG UCSR0B, r24
.endm
.macro CharacterSize1
	READ_REG UCSR1C, r25
	READ_REG UCSR1B, r24
	.if @0 == 6
		SETRB r25, UCSZ10
		CLRRB r25, UCSZ11
		CLRRB r24, UCSZ12
	.elif @0 == 7
		CLRRB r25, UCSZ10
		SETRB r25, UCSZ11
		CLRRB r24, UCSZ12
	.elif @0 == 8
		SETRB r25, UCSZ10
		SETRB r25, UCSZ11
		CLRRB r24, UCSZ12
	.elif @0 == 9
		SETRB r25, UCSZ10
		SETRB r25, UCSZ11
		SETRB r24, UCSZ12
	.endif
	WRITE_REG UCSR1C, r25
	WRITE_REG UCSR1B, r24
.endm
.macro CharacterSize2
	READ_REG UCSR2C, r25
	READ_REG UCSR2B, r24
	.if @0 == 6
		SETRB r25, UCSZ20
		CLRRB r25, UCSZ21
		CLRRB r24, UCSZ22
	.elif @0 == 7
		CLRRB r25, UCSZ20
		SETRB r25, UCSZ21
		CLRRB r24, UCSZ22
	.elif @0 == 8
		SETRB r25, UCSZ20
		SETRB r25, UCSZ21
		CLRRB r24, UCSZ22
	.elif @0 == 9
		SETRB r25, UCSZ20
		SETRB r25, UCSZ21
		SETRB r24, UCSZ22
	.endif
	WRITE_REG UCSR2C, r25
	WRITE_REG UCSR2B, r24
.endm
.macro CharacterSize3
	READ_REG UCSR3C, r25
	READ_REG UCSR3B, r24
	.if @0 == 6
		SETRB r25, UCSZ30
		CLRRB r25, UCSZ31
		CLRRB r24, UCSZ32
	.elif @0 == 7
		CLRRB r25, UCSZ30
		SETRB r25, UCSZ31
		CLRRB r24, UCSZ32
	.elif @0 == 8
		SETRB r25, UCSZ30
		SETRB r25, UCSZ31
		CLRRB r24, UCSZ32
	.elif @0 == 9
		SETRB r25, UCSZ30
		SETRB r25, UCSZ31
		SETRB r24, UCSZ32
	.endif
	WRITE_REG UCSR3C, r25
	WRITE_REG UCSR3B, r24
.endm

.macro USARTCharacterSize

	push r25
	push r24

	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
			CharacterSize @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0
			CharacterSize0 @1
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0
			CharacterSize0 @1
		.elif @0 == 1
			CharacterSize1 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0
			CharacterSizeURSEL0 @1
		.elif @0 == 1
			CharacterSizeURSEL1 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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

	pop r24
	pop r25

.endm
