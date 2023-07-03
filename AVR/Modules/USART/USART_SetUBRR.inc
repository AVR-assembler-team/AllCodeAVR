.macro SetUBRR
	
	clr r16
	clr r17

	.if ATmegaFREQ == 1000000
		ldi r16, 6
	.elif ATmegaFREQ == 2000000
		ldi r16, 12
	.elif ATmegaFREQ == 4000000
		ldi r16, 25
	.elif ATmegaFREQ == 8000000
		ldi r16, 51
	.elif ATmegaFREQ == 16000000
		ldi r16, 103
	.endif
	
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		out UBRRH, r17
		out UBRRL, r16

	.elif ctlr == 48 || ctlr == 88 || ctlr == 168
		out UBRR0H, r17
		out UBRR0L, r16

	.elif ctlr == 165 || ctlr == 169 || ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450 || ctlr == 328 || ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
		sts UBRR0H, r17
		sts UBRR0L, r16
	
	.elif ctlr == 64 || ctlr == 128 || ctlr == 162 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284 
		out UBRR0H, r17
		out UBRR0L, r16
		out UBRR1H, r17
		out UBRR1L, r16

	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		sts UBRR0H, r17
		sts UBRR0L, r16
		sts UBRR1H, r17
		sts UBRR1L, r16
		sts UBRR2H, r17
		sts UBRR2L, r16
		sts UBRR3H, r17
		sts UBRR3L, r16

	.endif
.endm
