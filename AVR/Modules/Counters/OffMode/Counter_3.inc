.macro CountersOffModeCounter3
	.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		CLRB TCCR3B, CS30
		CLRB TCCR3B, CS31
		CLRB TCCR3B, CS32
	.else
		.error "Counter 3 in not supported by this controller!"
	.endif
.endm
