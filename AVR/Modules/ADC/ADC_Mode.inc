.macro SetADCModeSelect
	.if ctlr == 8 || ctlr == 128
		#ifdef FreeRun
			SETB ADCSRA, ADFR
		#elif defined AnComp || ExtIntReq0 || TC0CompMatch || TC0Overflow || TC1CompMatchB || TC1Overflow || TC1CaptEvent
			.error "ADC Mode not available! Change the setting in the file ADC_config.inc"
		#else
			CLRB ADCSRA, ADFR
		#endif
	.else
		#if defined FreeRun || AnComp || ExtIntReq0 || TC0CompMatch || TC0Overflow || TC1CompMatchB || TC1Overflow || TC1CaptEvent
			SETB ADCSRA, ADATE
			.if ctlr == 16 || ctlr == 32
				#ifdef FreeRun
					CLRB SFIOR, ADTS0
					CLRB SFIOR, ADTS1
					CLRB SFIOR, ADTS2
				#elif defined AnComp
					SETB SFIOR, ADTS0
					CLRB SFIOR, ADTS1
					CLRB SFIOR, ADTS2
				#elif defined ExtIntReq0
					CLRB SFIOR, ADTS0
					SETB SFIOR, ADTS1
					CLRB SFIOR, ADTS2
				#elif defined TC0CompMatch
					SETB SFIOR, ADTS0
					SETB SFIOR, ADTS1
					CLRB SFIOR, ADTS2
				#elif defined TC0Overflow
					CLRB SFIOR, ADTS0
					CLRB SFIOR, ADTS1
					SETB SFIOR, ADTS2
				#elif defined TC1CompMatchB
					SETB SFIOR, ADTS0
					CLRB SFIOR, ADTS1
					SETB SFIOR, ADTS2
				#elif defined TC1Overflow
					CLRB SFIOR, ADTS0
					SETB SFIOR, ADTS1
					SETB SFIOR, ADTS2
				#elif defined TC1CaptEvent
					SETB SFIOR, ADTS0
					SETB SFIOR, ADTS1
					SETB SFIOR, ADTS2
				#endif
			.else
				#ifdef FreeRun
					CLRB ADCSRB, ADTS0
					CLRB ADCSRB, ADTS1
					CLRB ADCSRB, ADTS2
				#elif defined AnComp
					SETB ADCSRB, ADTS0
					CLRB ADCSRB, ADTS1
					CLRB ADCSRB, ADTS2
				#elif defined ExtIntReq0
					CLRB ADCSRB, ADTS0
					SETB ADCSRB, ADTS1
					CLRB ADCSRB, ADTS2
				#elif defined TC0CompMatch
					SETB ADCSRB, ADTS0
					SETB ADCSRB, ADTS1
					CLRB ADCSRB, ADTS2
				#elif defined TC0Overflow
					CLRB ADCSRB, ADTS0
					CLRB ADCSRB, ADTS1
					SETB ADCSRB, ADTS2
				#elif defined TC1CompMatchB
					SETB ADCSRB, ADTS0
					CLRB ADCSRB, ADTS1
					SETB ADCSRB, ADTS2
				#elif defined TC1Overflow
					CLRB ADCSRB, ADTS0
					SETB ADCSRB, ADTS1
					SETB ADCSRB, ADTS2
				#elif defined TC1CaptEvent
					SETB ADCSRB, ADTS0
					SETB ADCSRB, ADTS1
					SETB ADCSRB, ADTS2
				#endif
			.endif
		#else
			CLRB ADCSRA, ADATE
		#endif
	.endif
.endm

