.macro MultiProcessorCommunication
	.if @0 == enabled
		SETB UCSRA, MPCM
	.elif @0 == disabled
		CLRB UCSRA, MPCM
	.endif
.endm
.macro MultiProcessorCommunication0
	.if @0 == enabled
		SETB UCSR0A, MPCM0
	.elif @0 == disabled
		CLRB UCSR0A, MPCM0
	.endif
.endm
.macro MultiProcessorCommunication1
	.if @0 == enabled
		SETB UCSR1A, MPCM1
	.elif @0 == disabled
		CLRB UCSR1A, MPCM1
	.endif
.endm
.macro MultiProcessorCommunication2
	.if @0 == enabled
		SETB UCSR2A, MPCM2
	.elif @0 == disabled
		CLRB UCSR2A, MPCM2
	.endif
.endm
.macro MultiProcessorCommunication3
	.if @0 == enabled
		SETB UCSR3A, MPCM3
	.elif @0 == disabled
		CLRB UCSR3A, MPCM3
	.endif
.endm

.macro USARTMultiProcessorCommunicationMode
	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
			MultiProcessorCommunication @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.elif @0 == 1
			MultiProcessorCommunication1 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.elif @0 == 1
			MultiProcessorCommunication1 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.elif @0 == 1
			MultiProcessorCommunication1 @1
		.elif @0 == 2
			MultiProcessorCommunication2 @1
		.elif @0 == 3
			MultiProcessorCommunication3 @1
		.endif
	.endif
.endm
