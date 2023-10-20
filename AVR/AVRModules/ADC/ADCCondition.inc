.macro ADCCondition
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.else
		.if @0 == Enable
			SETB ADCSRA, ADEN
		.elif @0 == Disable
			CLRB ADCSRA, ADEN
		.endif
	.endif
.endm
