.macro CountersWeveformGenerationModeCounter0
	.if @0 == 0
		.if ctrl == 8
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
				CLRB TCCR0, WGM00
				CLRB TCCR0, WGM01
			.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CLRB TCCR0A, WGM00
				CLRB TCCR0A, WGM01
				CLRB TCCR0B, WGM02
			.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				CLRB TCCR0A, WGM00
				CLRB TCCR0A, WGM01
			.endif
		.endif
	.elif @0 == 1
		.if ctrl == 8
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
				SETB TCCR0, WGM00
				CLRB TCCR0, WGM01
			.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				SETB TCCR0A, WGM00
				CLRB TCCR0A, WGM01
				CLRB TCCR0B, WGM02
			.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				SETB TCCR0A, WGM00
				CLRB TCCR0A, WGM01
			.endif
		.endif
	.elif @0 == 2
		.if ctrl == 8
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
				CLRB TCCR0, WGM00
				SETB TCCR0, WGM01
			.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CLRB TCCR0A, WGM00
				SETB TCCR0A, WGM01
				CLRB TCCR0B, WGM02
			.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				CLRB TCCR0A, WGM00
				SETB TCCR0A, WGM01
			.endif
		.endif
	.elif @0 == 3
		.if ctrl == 8
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
				SETB TCCR0, WGM00
				SETB TCCR0, WGM01
			.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				SETB TCCR0A, WGM00
				SETB TCCR0A, WGM01
				CLRB TCCR0B, WGM02
			.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				SETB TCCR0A, WGM00
				SETB TCCR0A, WGM01
			.endif
		.endif
	.elif @0 == 4
		.error "This Mode Number is reserved for this controller!"
	.elif @0 == 5
		.if ctrl == 8 || ctrl == 16
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				SETB TCCR0A, WGM00
				CLRB TCCR0A, WGM01
				SETB TCCR0B, WGM02
			.else
				.error "This Weveform Generation Mode Number is not supporting by Counter 0 of this controller!"
			.endif
		.endif
	.elif @0 == 6
		.error "This Mode Number is reserved for this controller!"
	.elif @0 == 7
		.if ctrl == 8 || ctrl == 16
			.error "Weveform Generation Mode is not supporting by Counter 0 of this controller!"
		.else
			.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				SETB TCCR0A, WGM00
				SETB TCCR0A, WGM01
				SETB TCCR0B, WGM02
			.else
				.error "This Weveform Generation Mode Number is not supporting by Counter 0 of this controller!"
			.endif
		.endif
	.else
		.error "This Mode Number is not supporting by this controller!"
	.endif
.endm
