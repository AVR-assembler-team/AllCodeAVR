.macro Modules_Inits
	
	#ifdef TWSI_Module
		TWSI_init
	#endif

	#ifdef HD44780U_Module
		HD44780U_init
	#endif

	#ifdef OneWire_Module
		OneWire_init
	#endif
.endm
