.macro MultiProcessor
	#ifdef MultiProcessorCommunicationModeEnabled0
		sbr @0, (1<<MPCM)
	#endif
.endm
.macro MultiProcessor0
	#ifdef MultiProcessorCommunicationModeEnabled0
		sbr @0, (1<<MPCM0)
	#endif
.endm
.macro MultiProcessor1
	#ifdef MultiProcessorCommunicationModeEnabled1
		sbr @0, (1<<MPCM1)
	#endif
.endm
.macro MultiProcessor2
	#ifdef MultiProcessorCommunicationModeEnabled2
		sbr @0, (1<<MPCM2)
	#endif
.endm
.macro MultiProcessor3
	#ifdef MultiProcessorCommunicationModeEnabled3
		sbr @0, (1<<MPCM3)
	#endif
.endm



.macro WriteUCSRA
	WRITE_REG @0, @1
.endm
.macro SetUCSRA
	
	clr r16
	clr r17
	clr r18
	clr r19
	
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		
		MultiProcessor r16
		WriteUCSRA  UCSRA, r16

	.elif ctlr == 48 || ctlr == 88 || ctlr == 168 || ctlr == 169 || ctlr == 165 || ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450 || ctlr == 328 || ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490

		MultiProcessor0 r16
		WriteUCSRA  UCSR0A, r16

	.elif ctlr == 64 || ctlr == 128 || ctlr == 162 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284

		MultiProcessor0 r16
		MultiProcessor1 r17
		WriteUCSRA  UCSR0A, r16
		WriteUCSRA  UCSR1A, r17
		
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
	
		MultiProcessor0 r16
		MultiProcessor1 r17
		MultiProcessor2 r18
		MultiProcessor3 r19
		WriteUCSRC  UCSR0C, r16
		WriteUCSRC  UCSR1C, r17
		WriteUCSRC  UCSR2C, r18
		WriteUCSRC  UCSR3C, r19

	.endif
.endm