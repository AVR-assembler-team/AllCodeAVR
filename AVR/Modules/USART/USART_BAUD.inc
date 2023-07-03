.macro UBBR1
	.if @0 == 2400
		ldi r16, 25
	.elif @0 == 4800
		ldi r16, 12
	.elif @0 == 9600
		ldi r16, 6
	.elif @0 == 14400
		ldi r16, 3
	.elif @0 == 19200
		ldi r16, 2
	.elif @0 == 28800
		ldi r16, 1
	.elif @0 == 38400
		ldi r16, 1
	.elif @0 > 57600
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR2
	.if @0 == 2400
		ldi r16, 51
	.elif @0 == 4800
		ldi r16, 25
	.elif @0 == 9600
		ldi r16, 12
	.elif @0 == 14400
		ldi r16, 8
	.elif @0 == 19200
		ldi r16, 6
	.elif @0 == 28800
		ldi r16, 3
	.elif @0 == 38400
		ldi r16, 2
	.elif @0 == 57600
		ldi r16, 1
	.elif @0 == 76800
		ldi r16, 1
	.elif @0 > 115200
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR3
	.if @0 == 2400
		ldi r16, 103
	.elif @0 == 4800
		ldi r16, 51
	.elif @0 == 9600
		ldi r16, 25
	.elif @0 == 14400
		ldi r16, 16
	.elif @0 == 19200
		ldi r16, 12
	.elif @0 == 28800
		ldi r16, 8
	.elif @0 == 38400
		ldi r16, 6
	.elif @0 == 57600
		ldi r16, 3
	.elif @0 == 76800
		ldi r16, 2
	.elif @0 == 115200
		ldi r16, 1
	.elif @0 > 250000
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR4
	.if @0 == 2400
		ldi r16, 207
	.elif @0 == 4800
		ldi r16, 103
	.elif @0 == 9600
		ldi r16, 51
	.elif @0 == 14400
		ldi r16, 34
	.elif @0 == 19200
		ldi r16, 25
	.elif @0 == 28800
		ldi r16, 16
	.elif @0 == 38400
		ldi r16, 12
	.elif @0 == 57600
		ldi r16, 8
	.elif @0 == 76800
		ldi r16, 6
	.elif @0 == 115200
		ldi r16, 3
	.elif @0 == 230400
		ldi r16, 1
	.elif @0 == 250000
		ldi r16, 1
	.elif @0 > 500000
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR5
	.if @0 == 2400
		ldi r16, 160
		ldi r17, 1
	.elif @0 == 4800
		ldi r16, 207
	.elif @0 == 9600
		ldi r16, 103
	.elif @0 == 14400
		ldi r16, 68
	.elif @0 == 19200
		ldi r16, 51
	.elif @0 == 28800
		ldi r16, 34
	.elif @0 == 38400
		ldi r16, 25
	.elif @0 == 57600
		ldi r16, 16
	.elif @0 == 76800
		ldi r16, 12
	.elif @0 == 115200
		ldi r16, 8
	.elif @0 == 230400
		ldi r16, 3
	.elif @0 == 250000
		ldi r16, 3
	.elif @0 == 500000
		ldi r16, 1
	.endif
.endm
.macro UBBR6
	.if @0 == 2400
		ldi r16, 64
		ldi r17, 3
	.elif @0 == 4800
		ldi r16, 160
		ldi r17, 1
	.elif @0 == 9600
		ldi r16, 207
	.elif @0 == 14400
		ldi r16, 138
	.elif @0 == 19200
		ldi r16, 103
	.elif @0 == 28800
		ldi r16, 68
	.elif @0 == 38400
		ldi r16, 51
	.elif @0 == 57600
		ldi r16, 34
	.elif @0 == 76800
		ldi r16, 25
	.elif @0 == 115200
		ldi r16, 16
	.elif @0 == 230400
		ldi r16, 8
	.elif @0 == 250000
		ldi r16, 7
	.elif @0 == 500000
		ldi r16, 3
	.elif @0 == 1000000
		ldi r16, 1
	.endif
.endm


.macro USARTBaudRate
	
	clr r16
	clr r17

	.if ATmegaFREQ == 1000000
		.if @1 == normal
			UBBR1 @2
		.elif @1 == double
			UBBR2 @2
		.endif
	.elif ATmegaFREQ == 2000000
		.if @1 == normal
			UBBR2 @2
		.elif @1 == double
			UBBR3 @2
			.if @2 == 230400
				.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
			.endif
		.endif
	.elif ATmegaFREQ == 4000000
		.if @1 == normal
			UBBR3 @2
		.elif @1 == double
			UBBR4 @2
		.endif
	.elif ATmegaFREQ == 8000000
		.if @1 == normal
			UBBR4 @2
		.elif @1 == double
			UBBR5 @2
		.endif
	.elif ATmegaFREQ == 16000000
		.if @1 == normal
			UBBR5 @2
		.elif @1 == double
			UBBR6 @2
		.endif
	.endif


	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
			out UBRRH, r17
			out UBRRL, r16
		.endif

	.elif ctlr == 48 || ctlr == 88 || ctlr == 168
		.if @0 == 0
			out UBRR0H, r17
			out UBRR0L, r16
		.endif

	.elif ctlr == 165 || ctlr == 169 || ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450 || ctlr == 328 || ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
		.if @0 == 0
			sts UBRR0H, r17
			sts UBRR0L, r16
		.endif
	
	.elif ctlr == 64 || ctlr == 128 || ctlr == 162 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284 
		.if @0 == 0
			out UBRR0H, r17
			out UBRR0L, r16
		.elif @0 == 1
			out UBRR1H, r17
			out UBRR1L, r16
		.endif

	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == 0
			sts UBRR0H, r17
			sts UBRR0L, r16
		.elif @0 == 1
			sts UBRR1H, r17
			sts UBRR1L, r16
		.elif @0 == 2
			sts UBRR2H, r17
			sts UBRR2L, r16
		.elif @0 == 3
			sts UBRR3H, r17
			sts UBRR3L, r16
		.endif

	.endif
.endm
