.macro CountersCompareOutputMode
	.if @2 >= 0 && @2 <= 3
		.if @0 == Counter0
			CountersCompareOutputModeCounter0 @1, @2
		.elif @0 == Counter1
			CountersCompareOutputModeCounter1 @1, @2
		.elif @0 == Counter2
			.if ctrl == 5815
				.error "Counter 2 is not supporting by this controller!"
			.else
				CountersCompareOutputModeCounter2 @1, @2
			.endif
		.elif @0 == Counter3
			.if ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersCompareOutputModeCounter3 @1, @2
			.else
				.error "Counter 3 is not supporting by this controller!"
			.endif
		.elif @0 == Counter4
			.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersCompareOutputModeCounter4 @1, @2
			.else
				.error "Counter 4 is not supporting by this controller!"
			.endif
		.elif @0 == Counter5
			.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
				CountersCompareOutputModeCounter5 @1, @2
			.else
				.error "Counter 5 is not supporting by this controller!"
			.endif
		.endif
	.else
		.error "This Compare Output Mode is not supporting by counter 0 of this controller!"
	.endif
.endm
