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
	
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		out UBRRH, r17
		out UBRRL, r16

	.elif ctrl == 48 || ctrl == 88 || ctrl == 168
		out UBRR0H, r17
		out UBRR0L, r16

	.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 328 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		sts UBRR0H, r17
		sts UBRR0L, r16
	
	.elif ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284 
		out UBRR0H, r17
		out UBRR0L, r16
		out UBRR1H, r17
		out UBRR1L, r16

	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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
