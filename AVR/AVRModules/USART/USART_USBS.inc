.macro StopBits
	READ_REG UCSRC, r25
	.if @0 == One
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, USBS
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.elif @0 == Two
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, USBS
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.endif
.endm 
.macro StopBitsURSEL0
	READ_REG UCSR0C, r25
	.if @0 == One
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, USBS0
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.elif @0 == Two
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, USBS0
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro StopBitsURSEL1
	READ_REG UCSR1C, r25
	.if @0 == One
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r25, USBS1
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.elif @0 == Two
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r25, USBS1
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.endif
.endm 
.macro StopBits0
	READ_REG UCSR0C, r25
	.if @0 == One
		CLRRB r25, USBS0
	.elif @0 == Two
		SETRB r25, USBS0
	.endif
	WRITE_REG UCSR0C, r25
.endm
.macro StopBits1
	READ_REG UCSR1C, r25
	.if @0 == One
		CLRRB r25, USBS1
	.elif @0 == Two
		SETRB r25, USBS1
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro StopBits2
	READ_REG UCSR2C, r25
	.if @0 == One
		CLRRB r25, USBS2
	.elif @0 == Two
		SETRB r25, USBS2
	.endif
	WRITE_REG UCSR2C, r25
.endm
.macro StopBits3
	READ_REG UCSR3C, r25
	.if @0 == One
		CLRRB r25, USBS3
	.elif @0 == Two
		SETRB r25, USBS3
	.endif
	WRITE_REG UCSR3C, r25
.endm

.macro USARTStopBits

	push r25

	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
			StopBits @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0
			StopBits0 @1
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0
			StopBits0 @1
		.elif @0 == 1
			StopBits1 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0
			StopBitsURSEL0 @1
		.elif @0 == 1
			StopBitsURSEL1 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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

	pop r25

.endm