.macro CountersWeveformGenerationMode
	.if @1 >0 && @1 <= 15
		.if @0 == Counter0
			CountersWeveformGenerationModeCounter0 @1
		.elif @0 == Counter1
			CountersWeveformGenerationModeCounter1 @1
		.elif @0 == Counter2
			.if ctrl == 8515
				.error "Counter 2 is not supporting by this controller!"
			.else
				CountersWeveformGenerationModeCounter2 @1
			.endif
		.elif @0 == Counter3
			.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersWeveformGenerationModeCounter3 @1
			.else
				.error "Counter 3 is not supporting by this controller!"
			.endif
		.elif @0 == Counter4
			.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersWeveformGenerationModeCounter4 @1
			.else
				.error "Counter 4 is not supporting by this controller!"
			.endif
		.elif @0 == Counter5
			.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersWeveformGenerationModeCounter5 @1
			.else
				.error "Counter 5 is not supporting by this controller!"
			.endif
		.endif
	.else
		.error "This Weveform Generation Mode is not supporting by counter 0 of this controller!"
	.endif
.endm
