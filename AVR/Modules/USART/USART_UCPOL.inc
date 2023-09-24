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