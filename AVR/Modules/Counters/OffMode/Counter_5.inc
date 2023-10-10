.macro CountersOffModeCounter5
	.if ctrl == 640 || ctrl == 1280 || ctrl == 1280 || ctrl == 2560 || ctrl == 2561
		CLRB TCCR5B, CS50
		CLRB TCCR5B, CS51
		CLRB TCCR5B, CS52
	.else
		.error "Counter 5 is not supporting by this controller!"
	.endif
.endm
