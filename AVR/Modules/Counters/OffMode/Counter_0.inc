.macro CountersOffModeCounter0
	.if ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		CLRB TCCR0A, CS00
		CLRB TCCR0A, CS01
		CLRB TCCR0A, CS02
	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
		CLRB TCCR0B, CS00
		CLRB TCCR0B, CS01
		CLRB TCCR0B, CS02
	.elif ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
		CLRB TCCR0, CS00
		CLRB TCCR0, CS01
		CLRB TCCR0, CS02
	.endif
.endm
