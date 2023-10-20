.macro ParityMode
	.if @0 == Disable
		SETB UCSRC, UREL
		CLRB UCSRC, UPM0
		CLRB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.elif @0 == EvenParity
		SETB UCSRC, URSEL
		CLRB UCSRC, UPM0
		SETB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.elif @0 == OddParity
		SETB UCSRC, URSEL
		SETB UCSRC, UPM0
		SETB UCSRC, UPM1
		CLRB UCSRC, URSEL
	.endif
.endm
.macro ParityMode0
	.if @0 == Disable
		CLRB UCSR0C, UPM00
		CLRB UCSR0C, UPM01
	.elif @0 == EvenParity
		CLRB UCSR0C, UPM00
		SETB UCSR0C, UPM01
	.elif @0 == OddParity
		SETB UCSR0C, UPM00
		SETB UCSR0C, UPM01
	.endif
.endm
.macro ParityModeURSEL0
	.if @0 == Disable
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UPM00
		CLRB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.elif @0 == EvenParity
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UPM00
		SETB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.elif @0 == OddParity
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UPM00
		SETB UCSR0C, UPM01
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro ParityMode1
	.if @0 == Disable
		CLRB UCSR1C, UPM10
		CLRB UCSR1C, UPM11
	.elif @0 == EvenParity
		CLRB UCSR1C, UPM10
		SETB UCSR1C, UPM11
	.elif @0 == OddParity
		SETB UCSR1C, UPM10
		SETB UCSR1C, UPM11
	.endif
.endm
.macro ParityModeURSEL1
	.if @0 == Disable
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UPM10
		CLRB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.elif @0 == EvenParity
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UPM10
		SETB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.elif @0 == OddParity
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UPM10
		SETB UCSR1C, UPM11
		CLRB UCSR1C, URSEL1
	.endif
.endm
.macro ParityMode2
	.if @0 == Disable
		CLRB UCSR2C, UPM20
		CLRB UCSR2C, UPM21
	.elif @0 == EvenParity
		CLRB UCSR2C, UPM20
		SETB UCSR2C, UPM21
	.elif @0 == OddParity
		SETB UCSR2C, UPM20
		SETB UCSR2C, UPM21
	.endif
.endm
	.macro ParityMode3
	.if @0 == Disable
		CLRB UCSR3C, UPM30
		CLRB UCSR3C, UPM31
	.elif @0 == EvenParity
		CLRB UCSR3C, UPM30
		SETB UCSR3C, UPM31
	.elif @0 == OddParity
		SETB UCSR3C, UPM30
		SETB UCSR3C, UPM31
	.endif
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
