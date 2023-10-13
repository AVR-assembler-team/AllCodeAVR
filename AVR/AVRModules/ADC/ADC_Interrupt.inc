.macro SetADCInterrupt
	#ifdef ADCInterrupt_Enabled
		SETB ADCSRA, ADIE
	#endif
.endm
