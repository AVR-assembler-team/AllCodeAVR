.macro ADCReferenceSelection
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if @0 == Off
			CLRB ADMUX, REFS0
			CLRB ADMUX, REFS1
		.elif @0 == AREFpin
			SETB ADMUX, REFS0
			CLRB ADMUX, REFS1
		.elif @0 == Internal_1_1V
			.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128
				.error "Internal 1.1V Voltage Reference with external capacitor at AREF pin is not supporting by this controller!"
			.elif ctrl == 164 || ctrl == 324 || ctrl == 640 || ctrl == 644 || ctrl == 1280 || ctrl == 1281 || ctrl == 1284 || ctrl == 2560 || ctrl == 2561
				CLRB ADMUX, REFS0
				SETB ADMUX, REFS1
			.elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
				SETB ADMUX, REFS0
				SETB ADMUX, REFS1
			.endif
		.elif @0 == Internal_2_56V
			.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 164 || ctrl == 324 || ctrl == 640 || ctrl == 644 || ctrl == 1280 || ctrl == 1281 || ctrl == 1284 || ctrl == 2560 || ctrl == 2561
				SETB ADMUX, REFS0
				SETB ADMUX, REFS1
			.else
				.error "Internal 2.56V Voltage Reference with external capacitor at AREF pin is not supporting by this controller!"
			.endif
		.else
			.error "This ADC Reference Selection mode is not supporting by this controller!"
		.endif
	.endif
.endm
