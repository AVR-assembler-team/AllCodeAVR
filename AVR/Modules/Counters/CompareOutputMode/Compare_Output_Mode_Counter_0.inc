.macro CompareOutputModeCounter0
	.if ctrl == 8
		.error "Compare Output Mode is not supporting by counter 0 of this controller!"
	.else
		.if @0 == CompareMatchOutput
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
				.if @1 == 0
					CLRB TCCR0, COM00
					CLRB TCCR0, COM01
				.elif @1 == 1
					SETB TCCR0, COM00
					CLRB TCCR0, COM01
				.elif @1 == 2
					CLRB TCCR0, COM00
					SETB TCCR0, COM01
				.elif @1 == 3
					SETB TCCR0, COM00
					SETB TCCR0, COM01
				.endif
			.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				.if @1 == 0
					CLRB TCCR0A, COM0A0
					CLRB TCCR0A, COM0A1
				.elif @1 == 1
					SETB TCCR0A, COM0A0
					CLRB TCCR0A, COM0A1
				.elif @1 == 2
					CLRB TCCR0A, COM0A0
					SETB TCCR0A, COM0A1
				.elif @1 == 3
					SETB TCCR0A, COM0A0
					SETB TCCR0A, COM0A1
				.endif
			.else
				.error "Compare Match Output is not supporting by counter 0 of this controller!"
			.endif
		.elif @0 == CompareMatchOutputA
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 162 || ctrl == 8515 || ctrl == 8535 || ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				.error "Compare Match Output A is not supporting by counter 0 of this controller!"
			.else
				.if @1 == 0
					CLRB TCCR0A, COM0A0
					CLRB TCCR0A, COM0A1
				.elif @1 == 1
					SETB TCCR0A, COM0A0
					CLRB TCCR0A, COM0A1
				.elif @1 == 2
					CLRB TCCR0A, COM0A0
					SETB TCCR0A, COM0A1
				.elif @1 == 3
					SETB TCCR0A, COM0A0
					SETB TCCR0A, COM0A1
				.endif
			.endif
		.elif @0 == CompareMatchOutputB
			.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 162 || ctrl == 8515 || ctrl == 8535 || ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
				.error "Compare Match Output B is not supporting by counter 0 of this controller!"
			.else
				.if @1 == 0
					CLRB TCCR0A, COM0B0
					CLRB TCCR0A, COM0B1
				.elif @1 == 1
					SETB TCCR0A, COM0B0
					CLRB TCCR0A, COM0B1
				.elif @1 == 2
					CLRB TCCR0A, COM0B0
					SETB TCCR0A, COM0B1
				.elif @1 == 3
					SETB TCCR0A, COM0B0
					SETB TCCR0A, COM0B1
				.endif
			.endif
		.elif @0 == CompareMatchOutputC
			.error "Compare Match Output C is not supporting by counter 0 of this controller!"
		.endif
	.endif
.endm
