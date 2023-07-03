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
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
			MultiProcessorCommunication @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.endif
	.elif ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.elif @0 == 1
			MultiProcessorCommunication1 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0
			MultiProcessorCommunication0 @1
		.elif @0 == 1
			MultiProcessorCommunication1 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
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
