.macro ADCConversion
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if @0 == Enable
			SETB ADCSRA, ADSC
		.elif @0 == Disable
			CLRB ADCSRA, ADSC
		.endif
	.endif
.endm
