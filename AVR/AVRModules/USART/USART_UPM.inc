.macro ParityMode
	READ_REG UCSRC, r25
	.if @0 == Disable
		SETRB r25, UREL
		WRITE_REG UCSRC, r25
		CLRRB r25, UPM0
		CLRRB r25, UPM1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.elif @0 == EvenParity
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, UPM0
		SETRB r25, UPM1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.elif @0 == OddParity
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, UPM0
		SETRB r25, UPM1
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.endif
.endm
.macro ParityMode0
	READ_REG UCSR0C, r25
	.if @0 == Disable
		CLRRB r25, UPM00
		CLRRB r25, UPM01
	.elif @0 == EvenParity
		CLRRB r25, UPM00
		SETRB r25, UPM01
	.elif @0 == OddParity
		SETRB r25, UPM00
		SETRB r25, UPM01
	.endif
	WRITE_REG UCSR0C, r25
.endm
.macro ParityModeURSEL0
	READ_REG UCSR0C, r25
	.if @0 == Disable
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, UPM00
		CLRRB r25, UPM01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.elif @0 == EvenParity
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, UPM00
		SETRB r25, UPM01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.elif @0 == OddParity
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, UPM00
		SETRB r25, UPM01
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro ParityMode1
	READ_REG UCSR1C, r25
	.if @0 == Disable
		CLRRB r25, UPM10
		CLRRB r25, UPM11
	.elif @0 == EvenParity
		CLRRB r25, UPM10
		SETRB r25, UPM11
	.elif @0 == OddParity
		SETRB r25, UPM10
		SETRB r25, UPM11
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro ParityModeURSEL1
	READ_REG UCSR1C, r25
	.if @0 == Disable
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r25, UPM10
		CLRRB r25, UPM11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.elif @0 == EvenParity
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		CLRRB r25, UPM10
		SETRB r25, UPM11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.elif @0 == OddParity
		SETRB r25, URSEL1
		WRITE_REG UCSR1C, r25
		SETRB r25, UPM10
		SETRB r25, UPM11
		WRITE_REG UCSR1C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR1C, r25
	.endif
.endm
.macro ParityMode2
	READ_REG UCSR2C, r25
	.if @0 == Disable
		CLRRB r25, UPM20
		CLRRB r25, UPM21
	.elif @0 == EvenParity
		CLRRB r25, UPM20
		SETRB r25, UPM21
	.elif @0 == OddParity
		SETRB r25, UPM20
		SETRB r25, UPM21
	.endif
	WRITE_REG UCSR2C, r25
.endm
.macro ParityMode3
	READ_REG UCSR3C, r25
	.if @0 == Disable
		CLRRB r25, UPM30
		CLRRB r25, UPM31
	.elif @0 == EvenParity
		CLRRB r25, UPM30
		SETRB r25, UPM31
	.elif @0 == OddParity
		SETRB r25, UPM30
		SETRB r25, UPM31
	.endif
	WRITE_REG UCSR3C, r25
.endm
    
    
.macro USARTParityMode
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
		ParityMode @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0
		ParityMode0 @1
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0
		ParityMode0 @1
		.elif @0 == 1
		ParityMode1 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0
			ParityModeURSEL0 @1
		.elif @0 == 1
			ParityModeURSEL1 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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
