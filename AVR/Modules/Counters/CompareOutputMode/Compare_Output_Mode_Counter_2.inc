.macro CompareOutputModeCounter2
	.if @0 == CompareMatchOutput
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8535
			.if @1 == 0
				CLRB TCCR2, COM20
				CLRB TCCR2, COM21
			.elif @1 == 1
				SETB TCCR2, COM20
				CLRB TCCR2, COM21
			.elif @1 == 2
				CLRB TCCR2, COM20
				SETB TCCR2, COM21
			.elif @1 == 3
				SETB TCCR2, COM20
				SETB TCCR2, COM21
			.endif
		.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
			.if @1 == 0
				CLRB TCCR2A, COM2A0
				CLRB TCCR2A, COM2A1
			.elif @1 == 1
				SETB TCCR2A, COM2A0
				CLRB TCCR2A, COM2A1
			.elif @1 == 2
				CLRB TCCR2A, COM2A0
				SETB TCCR2A, COM2A1
			.elif @1 == 3
				SETB TCCR2A, COM2A0
				SETB TCCR2A, COM2A1
			.endif
		.else
			.error "Compare Output Mode is not supporting by counter 2 of this controller!"
		.endif
	.elif @0 == CompareMatchOutputA
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == 0
				CLRB TCCR2A, COM2A0
				CLRB TCCR2A, COM2A1
			.elif @1 == 1
				SETB TCCR2A, COM2A0
				CLRB TCCR2A, COM2A1
			.elif @1 == 2
				CLRB TCCR2A, COM2A0
				SETB TCCR2A, COM2A1
			.elif @1 == 3
				SETB TCCR2A, COM2A0
				SETB TCCR2A, COM2A1
			.endif
		.else
			.error "Compare Match Output A is not supporting by counter 0 of this controller!"
		.endif
	.elif @0 == CompareMatchOutputB
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == 0
				CLRB TCCR2A, COM2B0
				CLRB TCCR2A, COM2B1
			.elif @1 == 1
				SETB TCCR2A, COM2B0
				CLRB TCCR2A, COM2B1
			.elif @1 == 2
				CLRB TCCR2A, COM2B0
				SETB TCCR2A, COM2B1
			.elif @1 == 3
				SETB TCCR2A, COM2B0
				SETB TCCR2A, COM2B1
			.endif
		.else
			.error "Compare Match Output B is not supporting by counter 0 of this controller!"
		.endif
	.elif @0 == CompareMatchOutputC
		.error "Compare Match Output C is not supporting by counter 0 of this controller!"
	.endif
.endm
