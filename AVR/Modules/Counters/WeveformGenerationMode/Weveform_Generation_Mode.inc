.macro WeveformGenerationMode
	.if @0 == Counter0
		WeveformGenerationModeCounter0 @1
	.elif @0 == Counter1
		WeveformGenerationModeCounter1 @1
	.elif @0 == Counter2
		.if ctrl == 8515 || ctrl == 8535
			.error "Counter 2 is not supporting by this controller!"
		.else
			WeveformGenerationModeCounter2 @1
		.endif
	.elif @0 == Counter3
		.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			WeveformGenerationModeCounter3 @1
		.else
			.error "Counter 3 is not supporting by this controller!"
		.endif
	.elif @0 == Counter4
		.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			WeveformGenerationModeCounter4 @1
		.else
			.error "Counter 4 is not supporting by this controller!"
		.endif
	.elif @0 == Counter5
		.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			WeveformGenerationModeCounter5 @1
		.else
			.error "Counter 5 is not supporting by this controller!"
		.endif
	.endif
.endm
