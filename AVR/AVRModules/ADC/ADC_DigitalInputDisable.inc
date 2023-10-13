.macro SetDigInpDis
	#ifdef Disable_ADC0D
		SETB DIDR0, ADC0D
	#endif

	#ifdef Disable_ADC1D
		SETB DIDR0, ADC1D
	#endif

	#ifdef Disable_ADC2D
		SETB DIDR0, ADC2D
	#endif

	#ifdef Disable_ADC3D
		SETB DIDR0, ADC3D
	#endif

	#ifdef Disable_ADC4D
		SETB DIDR0, ADC4D
	#endif

	#ifdef Disable_ADC5D
		SETB DIDR0, ADC5D
	#endif

	#ifdef Disable_ADC6D
		SETB DIDR0, ADC6D
	#endif

	#ifdef Disable_ADC7D
		SETB DIDR0, ADC7D
	#endif

	#ifdef Disable_ADC8D
		SETB DIDR2, ADC8D
	#endif

	#ifdef Disable_ADC9D
		SETB DIDR2, ADC9D
	#endif

	#ifdef Disable_ADC10D
		SETB DIDR2, ADC10D
	#endif

	#ifdef Disable_ADC11D
		SETB DIDR2, ADC11D
	#endif

	#ifdef Disable_ADC12D
		SETB DIDR2, ADC12D
	#endif

	#ifdef Disable_ADC13D
		SETB DIDR2, ADC13D
	#endif

	#ifdef Disable_ADC14D
		SETB DIDR2, ADC14D
	#endif

	#ifdef Disable_ADC15D
		SETB DIDR2, ADC15D
	#endif
.endm
