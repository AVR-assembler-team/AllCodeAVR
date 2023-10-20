.macro ADCLeftAdjustResult
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if @0 == Left
			SETB ADMUX, ADLAR
		.elif @0 == Right
			CLRB ADMUX, ADLAR
		.endif
	.endif
.endm
