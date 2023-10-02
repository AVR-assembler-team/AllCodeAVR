.macro TimerSet
	.if ctrl == 8515 || ctrl == 8535
		.if @0 == Counter0
			TimersCounter0 @1, @2
		.elif @0 == Counter1
			TimersCounter1 @1, @2
		.else
			.error "This Timer for your controller is not available!"
		.endif
	.elif ctrl == 64 || ctrl == 128 || ctrl == 162
		.if @0 == Counter0
			TimersCounter0 @1, @2
		.elif @0 == Counter1
			TimersCounter1 @1, @2
		.elif @0 == Counter2
			TimersCounter2 @1, @2
		.elif @0 == Counter3
			TimersCounter3 @1, @2
		.else
			.error "This Timer for your controller is not available!"
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == Counter0
			TimersCounter0 @1, @2
		.elif @0 == Counter1
			TimersCounter1 @1, @2
		.elif @0 == Counter2
			TimersCounter2 @1, @2
		.elif @0 == Counter3
			TimersCounter3 @1, @2
		.elif @0 == Counter4
			TimersCounter4 @1, @2
		.elif @0 == Counter5
			TimersCounter5 @1, @2
		.endif
	.else
		.if @0 == Counter0
			TimersCounter0 @1, @2
		.elif @0 == Counter1
			TimersCounter1 @1, @2
		.elif @0 == Counter2
			TimersCounter2 @1, @2
		.else
			.error "This Timer for your controller is not available!"
		.endif
	.endif
.endm
