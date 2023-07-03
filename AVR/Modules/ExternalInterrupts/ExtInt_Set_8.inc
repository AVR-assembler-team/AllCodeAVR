
.macro SetINT
	
	clr r16
	clr r17

	#ifdef _INT0_
		sbr r16, (1<<INT0)
		#ifdef _AnyEdge_INT0_
			sbr r17, (1<<ISC00)
		#elif defined _FallingEdge_INT0_
			sbr r17, (1<<ISC01)
		#elif defined _RisingEdge_INT0_
			sbr r17, (1<<ISC00)
			sbr r17, (1<<ISC01)
		#endif
	#endif

	#ifdef _INT1_
		sbr r16, (1<<INT1)
		#ifdef _AnyEdge_INT1_
			sbr r17, (1<<ISC10)
		#elif defined _FallingEdge_INT1_
			sbr r17, (1<<ISC11)
		#elif defined _RisingEdge_INT1_
			sbr r17, (1<<ISC10)
			sbr r17, (1<<ISC11)
		#endif
	#endif

	#if defined _INT2_ || _INT3_ || _INT4_ || _INT5_ || _INT6_ || _INT7_
		.error "Only INT0 è INT1" 
	#endif

	WRITE_REG MCUCR, r17
	WRITE_REG GICR, r16
		
	#if defined EnablePCINT0 || EnablePCINT1 || EnablePCINT2 || EnablePCINT3
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT4 || EnablePCINT5 || EnablePCINT6 || EnablePCINT7 || EnablePCINT8
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT9 || EnablePCINT10 || EnablePCINT11 || EnablePCINT12 || EnablePCINT13
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT14 || EnablePCINT15 || EnablePCINT16 || EnablePCINT17 || EnablePCINT18
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT19 || EnablePCINT20 || EnablePCINT21 || EnablePCINT22 || EnablePCINT23
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT24 || EnablePCINT25 || EnablePCINT26 || EnablePCINT27 || EnablePCINT28
		.error "Pins PCINT0 - PCINT31 are not supported."
	#elif defined EnablePCINT29 || EnablePCINT30 || EnablePCINT31
		.error "Pins PCINT0 - PCINT31 are not supported."
	#endif

.endm
