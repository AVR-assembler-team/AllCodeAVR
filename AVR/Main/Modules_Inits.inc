.macro Modules_Inits
	
	#ifdef TWSI_Module
		TWSI_init
	#endif

	#ifdef OneWire_Module
		OneWire_init
	#endif
.endm
