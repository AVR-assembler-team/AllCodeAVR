.macro SetRefSel
	#ifdef TurnedOff
		CLRB ADMUX, REFS0
		CLRB ADMUX, REFS1
	#elif defined AREFpin
		SETB ADMUX, REFS0
		CLRB ADMUX, REFS1
	#elif defined Voltage_1_1
		.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 64 || ctlr == 128
			CLRB ADMUX, REFS0
			CLRB ADMUX, REFS1
		.elif ctlr == 164 || ctlr == 324 || ctlr == 640 || ctlr == 644 || ctlr == 1280 || ctlr == 1281 || ctlr == 1284 || ctlr == 2560 || ctlr == 2561
			CLRB ADMUX, REFS0
			SETB ADMUX, REFS1
		.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
			SETB ADMUX, REFS0
			SETB ADMUX, REFS1
		.endif
	#elif defined Voltage_2_56
		.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 640 || ctlr == 644 || ctlr == 1280 || ctlr == 1281 || ctlr == 1284 || ctlr == 2560 || ctlr == 2561
			SETB ADMUX, REFS0
			SETB ADMUX, REFS1
		.endif
	#endif
.endm
