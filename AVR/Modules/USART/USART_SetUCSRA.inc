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
	
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		
		MultiProcessor r16
		WriteUCSRA  UCSRA, r16

	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 169 || ctrl == 165 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 328 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490

		MultiProcessor0 r16
		WriteUCSRA  UCSR0A, r16

	.elif ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284

		MultiProcessor0 r16
		MultiProcessor1 r17
		WriteUCSRA  UCSR0A, r16
		WriteUCSRA  UCSR1A, r17
		
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
	
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