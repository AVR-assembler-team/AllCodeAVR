.macro SetAdjustResult
	#ifdef Adjust_Left
		SETB ADMUX, ADLAR
	#endif
.endm
