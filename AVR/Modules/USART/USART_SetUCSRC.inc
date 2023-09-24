.macro SetUCSRC
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		SETB UCSRC, UCSZ0
		SETB UCSRC, UCSZ1

	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 328 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01

	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11

	.elif ctrl == 162
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		
	.elif ctrl == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		SETB UCSR2C, UCSZ20
		SETB UCSR2C, UCSZ21
		SETB UCSR3C, UCSZ30
		SETB UCSR3C, UCSZ31
	.endif
.endm


