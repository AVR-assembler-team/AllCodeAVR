.macro CountersOffModeCounter4
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1280 || ctrl == 2560 || ctrl == 2561
		CLRB TCCR4B, CS40
		CLRB TCCR4B, CS41
		CLRB TCCR4B, CS42
	.else
		.error "Counter 4 is not supporting by this controller!"
	.endif
.endm
