.macro StopBits
	.if @0 == One
		SETB UCSRC, URSEL
		CLRB UCSRC, USBS
		CLRB UCSRC, URSEL
	.elif @0 == Two
		SETB UCSRC, URSEL
		SETB UCSRC, USBS
		CLRB UCSRC, URSEL
	.endif
.endm 
.macro StopBitsURSEL0
	.if @0 == One
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, USBS0
		CLRB UCSR0C, URSEL0
	.elif @0 == Two
		SETB UCSR0C, URSEL0
		SETB UCSR0C, USBS0
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro StopBitsURSEL1
	.if @0 == One
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, USBS1
		CLRB UCSR1C, URSEL1
	.elif @0 == Two
		SETB UCSR1C, URSEL1
		SETB UCSR1C, USBS1
		CLRB UCSR1C, URSEL1
	.endif
.endm 
.macro StopBits0
	.if @0 == One
		CLRB UCSR0C, USBS0
	.elif @0 == Two
		SETB UCSR0C, USBS0
	.endif
.endm
.macro StopBits1
	.if @0 == One
		CLRB UCSR1C, USBS1
	.elif @0 == Two
		SETB UCSR1C, USBS1
	.endif
.endm
.macro StopBits2
	.if @0 == One
		CLRB UCSR2C, USBS2
	.elif @0 == Two
		SETB UCSR2C, USBS2
	.endif
.endm
.macro StopBits3
	.if @0 == One
		CLRB UCSR3C, USBS3
	.elif @0 == Two
		SETB UCSR3C, USBS3
	.endif
.endm

.macro USARTStopBits
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
.endm