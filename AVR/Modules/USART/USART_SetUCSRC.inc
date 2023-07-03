.macro SetUCSRC
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		SETB UCSRC, UCSZ0
		SETB UCSRC, UCSZ1

	.elif ctlr == 48 || ctlr == 88 || ctlr == 168 || ctlr == 165 || ctlr == 169 || ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450 || ctlr == 328 || ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01

	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11

	.elif ctlr == 162
		SETB UCSR0C, UCSZ00
		SETB UCSR0C, UCSZ01
		SETB UCSR1C, UCSZ10
		SETB UCSR1C, UCSZ11
		
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
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


