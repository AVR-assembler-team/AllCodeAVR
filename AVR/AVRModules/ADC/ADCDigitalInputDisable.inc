.macro ADCDigitalInputDisable
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8535
			.error "Digital Input Disable is not supporting by this controller!"
		.else
			.if @0 == pin0D
				SETB DIDR0, ADC0D
			.elif @0 == pin1D
				SETB DIDR0, ADC1D
			.elif @0 == pin2D
				SETB DIDR0, ADC2D
			.elif @0 == pin3D
				SETB DIDR0, ADC3D
			.elif @0 == pin4D
				SETB DIDR0, ADC4D
			.elif @0 == pin5D
				SETB DIDR0, ADC5D
			.else
				.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 328
					.error "This ADC_D pin is not supporting by this controller!"
				.else
					.if @0 == pin6D
						SETB DIDR0, ADC6D
					.elif @0 == pin7D
						SETB DIDR0, ADC7D
					.else
						.if ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
							.if @0 == pin8D
								SETB DIDR2, ADC8D
							.elif @0 == pin9D
								SETB DIDR2, ADC9D
							.elif @0 == pin10D
								SETB DIDR2, ADC10D
							.elif @0 == pin11D
								SETB DIDR2, ADC11D
							.elif @0 == pin12D
								SETB DIDR2, ADC12D
							.elif @0 == pin13D
								SETB DIDR2, ADC13D
							.elif @0 == pin14D
								SETB DIDR2, ADC14D
							.elif @0 == pin15D
								SETB DIDR2, ADC15D
							.endif
						.else
							.error "This ADC_D pin is not supporting by this controller!"
						.endif
					.endif
				.endif
			.endif
		.endif
	.endif
.endm
