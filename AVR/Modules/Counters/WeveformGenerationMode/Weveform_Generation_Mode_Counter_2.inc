.macro WeveformGenerationModeCounter2
	.if @0 == 0
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 165 || ctrl == 169
			CLRB TCCR2, WGM20
			CLRB TCCR2, WGM21
		.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			CLRB TCCR2A, WGM20
			CLRB TCCR2A, WGM21
			CLRB TCCR2B, WGM22
		.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
			CLRB TCCR2A, WGM20
			CLRB TCCR2A, WGM21
		.endif
		#define NormalMode
	.elif @0 == 1
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 165 || ctrl == 169
			SETB TCCR2, WGM20
			CLRB TCCR2, WGM21
		.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			SETB TCCR2A, WGM20
			CLRB TCCR2A, WGM21
			CLRB TCCR2B, WGM22
		.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
			SETB TCCR2A, WGM20
			CLRB TCCR2A, WGM21
		.endif
		#define PWMPhaseCorrectMode
	.elif @0 == 2
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 165 || ctrl == 169
			CLRB TCCR2, WGM20
			SETB TCCR2, WGM21
		.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			CLRB TCCR2A, WGM20
			SETB TCCR2A, WGM21
			CLRB TCCR2B, WGM22
		.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
			CLRB TCCR2A, WGM20
			SETB TCCR2A, WGM21
		.endif
		#define CTCMode
	.elif @0 == 3
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 165 || ctrl == 169
			SETB TCCR2, WGM20
			SETB TCCR2, WGM21
		.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			SETB TCCR2A, WGM20
			SETB TCCR2A, WGM21
			CLRB TCCR2B, WGM22
		.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
			SETB TCCR2A, WGM20
			SETB TCCR2A, WGM21
		.endif
		#define FastPWMMode
	.elif @0 == 4
		.error "This Mode Number is reserved for this controller!"
	.elif @0 == 5
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			SETB TCCR2A, WGM20
			CLRB TCCR2A, WGM21
			SETB TCCR2B, WGM22
			#define PWMPhaseCorrectMode
		.else
			.error "This Weveform Generation Mode Number is not supporting by Counter 2 of this controller!"
		.endif
	.elif @0 == 6
		.error "This Mode Number is reserved for this controller!"
	.elif @0 == 7
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			SETB TCCR2A, WGM20
			SETB TCCR2A, WGM21
			SETB TCCR2B, WGM22
			#define FastPWMMode
		.else
			.error "This Weveform Generation Mode Number is not supporting by Counter 2 of this controller!"
		.endif
	.else
		.error "This Mode Number is not supporting by this controller!"
	.endif
.endm
