.macro ClockPolar
	.if @0 == Zero
		READ_REG UCSRC, r25
		SETRB r25, URSEL
		CLRRB r25, UCPOL
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.elif @0 == One
		READ_REG UCSRC, r25
		SETRB r25, URSEL
		SETRB r25, UCPOL
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.endif
.endm
.macro ClockPolarURSEL0
	.if @0 == Zero
		READ_REG UCSR0C, r25
		SETRB r25, URSEL0
		CLRRB r25, UCPOL0
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.elif @0 == One
		READ_REG UCSR0C, r25
		SETRB r25, URSEL0
		SETRB r25, UCPOL0
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro ClockPolarURSEL1
	.if @0 == Zero
		READ_REG UCSR1C, r25
		SETRB r25, URSEL1
		CLRRB r25, UCPOL1
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.elif @0 == One
		READ_REG UCSR1C, r25
		SETRB r25, URSEL1
		SETRB r25, UCPOL1
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.endif
.endm
.macro ClockPolar0
	.if @0 == Zero
		READ_REG UCSR0C, r25
		CLRRB r25, UCPOL0
		WRITE_REG UCSR0C, r25
	.elif @0 == One
		READ_REG UCSR0C, r25
		SETRB r25, UCPOL0
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro ClockPolar1
	READ_REG UCSR1C, r25
	.if @0 == Zero
		CLRRB r25, UCPOL1
	.elif @0 == One
		SETRB r25, UCPOL1
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro ClockPolar2
	READ_REG UCSR2C, r25
	.if @0 == Zero
		CLRRB r25, UCPOL2
	.elif @0 == One
		SETRB r25, UCPOL2
	.endif
	WRITE_REG UCSR2C, r25
.endm
.macro ClockPolar3
	READ_REG UCSR3C, r25
	.if @0 == Zero
		CLRRB r25, UCPOL3
	.elif @0 == One
		SETRB r25, UCPOL3
	.endif
	WRITE_REG UCSR3C, r25
.endm

.macro USARTClockPolarity
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
			ClockPolar @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0
			ClockPolar0 @1
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0
			ClockPolar0 @1
		.elif @0 == 1
			ClockPolar1 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0
			ClockPolarURSEL0 @1
		.elif @0 == 1
			ClockPolarURSEL1 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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
