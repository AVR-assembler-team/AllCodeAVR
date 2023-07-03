.macro SetChannelSelection
	.if ctlr == 8 || ctlr == 48 || ctlr == 88 || ctlr == 168 || ctlr == 328
		#ifdef SingleEndedInput_ADC0
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC2
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC3
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC4
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC5
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC6
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC7
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
		#elif defined SingleEndedInput_ADC8 || SingleEndedInput_ADC9 || SingleEndedInput_ADC10 || SingleEndedInput_ADC11 || SingleEndedInput_ADC12 || SingleEndedInput_ADC13 || SingleEndedInput_ADC14 || SingleEndedInput_ADC15
			.error "Single Ended Input is not available! Change the setting in the file ADC_config.inc"
		#elif defined SingleEndedInput_VBG
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
		#elif defined SingleEndedInput_GND
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
		#endif

		#if defined PositiveDifferentialInput_ADC0 || PositiveDifferentialInput_ADC1
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC2 || PositiveDifferentialInput_ADC3
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC4 || PositiveDifferentialInput_ADC5
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC6 || PositiveDifferentialInput_ADC7
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC8 || PositiveDifferentialInput_ADC9
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC10 || PositiveDifferentialInput_ADC11
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC12 || PositiveDifferentialInput_ADC13
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined PositiveDifferentialInput_ADC14 || PositiveDifferentialInput_ADC15
			.error "Positive Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined NegativeDifferentialInput_ADC0 || NegativeDifferentialInput_ADC1
			.error "Negative Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined NegativeDifferentialInput_ADC2 || NegativeDifferentialInput_ADC8
			.error "Negative Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined NegativeDifferentialInput_ADC9 || NegativeDifferentialInput_ADC10
			.error "Negative Differential Input is not available! Comment out this setting in the file ADC_config.inc"
		#elif defined Gain_1 || Gain_10 || Gain_200
			.error "Gain is not available! Comment out this setting in the file ADC_config.inc"
		#endif
		
	.elif ctlr == 16 || ctlr == 32 || ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 165 || ctlr == 169 || ctlr == 324 || ctlr == 325 || ctlr == 329 || ctlr == 644 || ctlr == 645 || ctlr == 649 || ctlr == 1284 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490 || ctlr == 8535
		#ifdef SingleEndedInput_ADC0
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC2
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC3
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC4
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC5
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC6
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC7
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
		#elif defined SingleEndedInput_ADC8 || SingleEndedInput_ADC9 || SingleEndedInput_ADC10 || SingleEndedInput_ADC11 || SingleEndedInput_ADC12 || SingleEndedInput_ADC13 || SingleEndedInput_ADC14 || SingleEndedInput_ADC15
			.error "Single Ended Input is not available! Change the setting in the file ADC_config.inc"
		#elif defined SingleEndedInput_VBG
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined SingleEndedInput_GND
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#endif

		.if ctlr == 16 || ctlr == 32 || ctlr == 64 || ctlr == 128 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284 || ctlr == 8535
			#if defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC0 && Gain_10
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC0 && Gain_10
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC0 && Gain_200
				CLRB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC0 && Gain_200
				SETB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_10
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_10
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_200
				CLRB ADMUX, MUX0
				SETB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_200
				SETB ADMUX, MUX0
				SETB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				CLRB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC1 && Gain_1
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC1 && Gain_1
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC1 && Gain_1
				CLRB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC1 && Gain_1
				SETB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC1 && Gain_1
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC1 && Gain_1
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC6 && NegativeDifferentialInput_ADC1 && Gain_1
				CLRB ADMUX, MUX0
				SETB ADMUX, MUX1
				SETB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC7 && NegativeDifferentialInput_ADC1 && Gain_1
				SETB ADMUX, MUX0
				SETB ADMUX, MUX1
				SETB ADMUX, MUX2
				CLRB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC2 && Gain_1
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC2 && Gain_1
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_1
				CLRB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_1
				SETB ADMUX, MUX0
				SETB ADMUX, MUX1
				CLRB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC2 && Gain_1
				CLRB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC2 && Gain_1
				SETB ADMUX, MUX0
				CLRB ADMUX, MUX1
				SETB ADMUX, MUX2
				SETB ADMUX, MUX3
				SETB ADMUX, MUX4
			#else
				.error "Positive Differential Input, Negative Differential Input and Gain combination is not available! Change the setting in the file ADC_config.inc"
			#endif
		.endif

		#if defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC6 && NegativeDifferentialInput_ADC1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC7 && NegativeDifferentialInput_ADC1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC2
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC2
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC2
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC2
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
		#else
			.error "Positive and Negative Differential Input combination is not available! Change the setting in the file ADC_config.inc"
		#endif
			
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		#ifdef SingleEndedInput_ADC0
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC2
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC3
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC4
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC5
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC6
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC7
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_VBG
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_GND
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC8
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC9
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC10
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC11
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC12
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC13
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC14
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined SingleEndedInput_ADC15
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#endif

		#if defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC0 && Gain_10
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC0 && Gain_10
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC0 && Gain_200
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC0 && Gain_200
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_10
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_10
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_200
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_200
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC1 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC1 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC1 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC1 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC1 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC1 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC6 && NegativeDifferentialInput_ADC1 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC7 && NegativeDifferentialInput_ADC1 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC0 && NegativeDifferentialInput_ADC2 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC1 && NegativeDifferentialInput_ADC2 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC2 && NegativeDifferentialInput_ADC2 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC3 && NegativeDifferentialInput_ADC2 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC4 && NegativeDifferentialInput_ADC2 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC5 && NegativeDifferentialInput_ADC2 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			CLRB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC8 && NegativeDifferentialInput_ADC8 && Gain_10
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC9 && NegativeDifferentialInput_ADC8 && Gain_10
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC8 && NegativeDifferentialInput_ADC8 && Gain_200
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC9 && NegativeDifferentialInput_ADC8 && Gain_200
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC10 && NegativeDifferentialInput_ADC10 && Gain_10
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC11 && NegativeDifferentialInput_ADC10 && Gain_10
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC10 && NegativeDifferentialInput_ADC10 && Gain_200
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC11 && NegativeDifferentialInput_ADC10 && Gain_200
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			CLRB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC8 && NegativeDifferentialInput_ADC9 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC9 && NegativeDifferentialInput_ADC9 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC10 && NegativeDifferentialInput_ADC9 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC11 && NegativeDifferentialInput_ADC9 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC12 && NegativeDifferentialInput_ADC9 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC13 && NegativeDifferentialInput_ADC9 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC14 && NegativeDifferentialInput_ADC9 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC15 && NegativeDifferentialInput_ADC9 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			SETB ADMUX, MUX2
			CLRB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC8 && NegativeDifferentialInput_ADC10 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC9 && NegativeDifferentialInput_ADC10 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC10 && NegativeDifferentialInput_ADC10 && Gain_1
			CLRB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC11 && NegativeDifferentialInput_ADC10 && Gain_1
			SETB ADMUX, MUX0
			SETB ADMUX, MUX1
			CLRB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC12 && NegativeDifferentialInput_ADC10 && Gain_1
			CLRB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#elif defined PositiveDifferentialInput_ADC13 && NegativeDifferentialInput_ADC10 && Gain_1
			SETB ADMUX, MUX0
			CLRB ADMUX, MUX1
			SETB ADMUX, MUX2
			SETB ADMUX, MUX3
			SETB ADMUX, MUX4
			SETB ADCSRB, MUX5
		#else
			.error "Positive Differential Input, Negative Differential Input and Gain combination is not available! Change the setting in the file ADC_config.inc"
		#endif
	.endif
.endm
