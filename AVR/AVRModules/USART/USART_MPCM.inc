.macro MultiProcessorCommunication
	READ_REG UCSRA, r25
	.if @0 == Enable
		SETRB r25, MPCM
	.elif @0 == Disable
		CLRRB r25, MPCM
	.endif
	WRITE_REG UCSRA, r25
.endm
.macro MultiProcessorCommunication0
	READ_REG UCSR0A, r25
	.if @0 == Enable
		SETRB r25, MPCM0
	.elif @0 == Disable
		CLRRB r25, MPCM0
	.endif
	WRITE_REG UCSR0A, r25
.endm
.macro MultiProcessorCommunication1
	READ_REG UCSR1A, r25
	.if @0 == Enable
		SETRB r25, MPCM1
	.elif @0 == Disable
		CLRRB r25, MPCM1
	.endif
	WRITE_REG UCSR1A, r25
.endm
.macro MultiProcessorCommunication2
	READ_REG UCSR2A, r25
	.if @0 == Enable
		SETRB r25, MPCM2
	.elif @0 == Disable
		CLRRB r25, MPCM2
	.endif
	WRITE_REG UCSR2A, r25
.endm
.macro MultiProcessorCommunication3
	READ_REG UCSR3A, r25
	.if @0 == Enable
		SETRB r25, MPCM3
	.elif @0 == Disable
		CLRRB r25, MPCM3
	.endif
	WRITE_REG UCSR3A, r25
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
