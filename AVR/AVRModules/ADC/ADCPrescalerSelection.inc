.macro ADCPrescalerSelection
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if @0 == 2
			SETB ADCSRA, ADPS0
			CLRB ADCSRA, ADPS1
			CLRB ADCSRA, ADPS2
		.elif @0 == 4
			CLRB ADCSRA, ADPS0
			SETB ADCSRA, ADPS1
			CLRB ADCSRA, ADPS2
		.elif @0 == 8
			SETB ADCSRA, ADPS0
			SETB ADCSRA, ADPS1
			CLRB ADCSRA, ADPS2
		.elif @0 == 16
			CLRB ADCSRA, ADPS0
			CLRB ADCSRA, ADPS1
			SETB ADCSRA, ADPS2
		.elif @0 == 32
			SETB ADCSRA, ADPS0
			CLRB ADCSRA, ADPS1
			SETB ADCSRA, ADPS2
		.elif @0 == 64
			CLRB ADCSRA, ADPS0
			SETB ADCSRA, ADPS1
			SETB ADCSRA, ADPS2
		.elif @0 == 128
			SETB ADCSRA, ADPS0
			SETB ADCSRA, ADPS1
			SETB ADCSRA, ADPS2
		.else
			.error "ADC Prescaller is not available!"
		.endif
	.endif
.endm
