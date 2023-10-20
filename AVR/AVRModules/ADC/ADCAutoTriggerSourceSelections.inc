.macro ADCAutoTriggerSourceSelections
	.if ctrl == 162 || ctrl == 8515
		.error "ADC is not supporting by this controller!"
	.elif ctrl == 8 || ctrl == 128
		.if @0 == null
			CLRB ADCSRA, ADFR
		.elif @0 == FreeRun
			SETB ADCSRA, ADFR
		.else
			.error "This Trigger Source in ADC Auto Trigger Source Selections is not available by this controller!"
		.endif
	.elif ctrl == 16 || ctrl == 32 || ctrl == 8535
		.if @0 == null
			CLRB ADCSRA, ADATE
			CLRB SFIOR, ADTS0
			CLRB SFIOR, ADTS1
			CLRB SFIOR, ADTS2
		.elif @0 == FreeRun
			SETB ADCSRA, ADATE
			CLRB SFIOR, ADTS0
			CLRB SFIOR, ADTS1
			CLRB SFIOR, ADTS2
		.elif @0 == AnComp
			SETB ADCSRA, ADATE
			SETB SFIOR, ADTS0
			CLRB SFIOR, ADTS1
			CLRB SFIOR, ADTS2
		.elif @0 == ExtIntReq0
			SETB ADCSRA, ADATE
			CLRB SFIOR, ADTS0
			SETB SFIOR, ADTS1
			CLRB SFIOR, ADTS2
		.elif @0 == TC0CompMatch
			SETB ADCSRA, ADATE
			SETB SFIOR, ADTS0
			SETB SFIOR, ADTS1
			CLRB SFIOR, ADTS2
		.elif @0 == TC0Overflow
			SETB ADCSRA, ADATE
			CLRB SFIOR, ADTS0
			CLRB SFIOR, ADTS1
			SETB SFIOR, ADTS2
		.elif @0 == TC1CompMatchB
			SETB ADCSRA, ADATE
			SETB SFIOR, ADTS0
			CLRB SFIOR, ADTS1
			SETB SFIOR, ADTS2
		.elif @0 == TC1Overflow
			SETB ADCSRA, ADATE
			CLRB SFIOR, ADTS0
			SETB SFIOR, ADTS1
			SETB SFIOR, ADTS2
		.elif @0 == TC1CaptEvent
			SETB ADCSRA, ADATE
			SETB SFIOR, ADTS0
			SETB SFIOR, ADTS1
			SETB SFIOR, ADTS2
		.endif
	.else
		.if @0 == null
			CLRB ADCSRA, ADATE
			CLRB ADCSRB, ADTS0
			CLRB ADCSRB, ADTS1
			CLRB ADCSRB, ADTS2
		.elif @0 == FreeRun
			SETB ADCSRA, ADATE
			CLRB ADCSRB, ADTS0
			CLRB ADCSRB, ADTS1
			CLRB ADCSRB, ADTS2
		.elif @0 == AnComp
			SETB ADCSRA, ADATE
			SETB ADCSRB, ADTS0
			CLRB ADCSRB, ADTS1
			CLRB ADCSRB, ADTS2
		.elif @0 == ExtIntReq0
			SETB ADCSRA, ADATE
			CLRB ADCSRB, ADTS0
			SETB ADCSRB, ADTS1
			CLRB ADCSRB, ADTS2
		.elif @0 == TC0CompMatch
			SETB ADCSRA, ADATE
			SETB ADCSRB, ADTS0
			SETB ADCSRB, ADTS1
			CLRB ADCSRB, ADTS2
		.elif @0 == TC0Overflow
			SETB ADCSRA, ADATE
			CLRB ADCSRB, ADTS0
			CLRB ADCSRB, ADTS1
			SETB ADCSRB, ADTS2
		.elif @0 == TC1CompMatchB
			SETB ADCSRA, ADATE
			SETB ADCSRB, ADTS0
			CLRB ADCSRB, ADTS1
			SETB ADCSRB, ADTS2
		.elif @0 == TC1Overflow
			SETB ADCSRA, ADATE
			CLRB ADCSRB, ADTS0
			SETB ADCSRB, ADTS1
			SETB ADCSRB, ADTS2
		.elif @0 == TC1CaptEvent
			SETB ADCSRA, ADATE
			SETB ADCSRB, ADTS0
			SETB ADCSRB, ADTS1
			SETB ADCSRB, ADTS2
		.endif
	.endif
.endm
