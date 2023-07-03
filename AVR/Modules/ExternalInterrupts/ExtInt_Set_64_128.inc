
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
	#ifdef _INT2_
		sbr r16, (1<<INT2)
		#ifdef _AnyEdge_INT2_
			sbr r17, (1<<ISC20)
		#elif defined _FallingEdge_INT2_
			sbr r17, (1<<ISC21)
		#elif defined _RisingEdge_INT2_
			sbr r17, (1<<ISC20)
			sbr r17, (1<<ISC21)
		#endif 
	#endif
	#ifdef _INT3_
		sbr r16, (1<<INT3)
		#ifdef _AnyEdge_INT3_
			sbr r17, (1<<ISC30)
		#elif defined _FallingEdge_INT3_
			sbr r17, (1<<ISC31)
		#elif defined _RisingEdge_INT3_
			sbr r17, (1<<ISC30)
			sbr r17, (1<<ISC31)
		#endif 
	#endif
	#ifdef _INT4_
		sbr r16, (1<<INT4)
		#ifdef _AnyEdge_INT4_
			sbr r18, (1<<ISC40)
		#elif defined _FallingEdge_INT4_
			sbr r18, (1<<ISC41)
		#elif defined _RisingEdge_INT4_
			sbr r18, (1<<ISC40)
			sbr r18, (1<<ISC41)
		#endif 
	#endif
	#ifdef _INT5_
		sbr r16, (1<<INT5)
		#ifdef _AnyEdge_INT5_
			sbr r18, (1<<ISC50)
		#elif defined _FallingEdge_INT5_
			sbr r18, (1<<ISC51)
		#elif defined _RisingEdge_INT5_
			sbr r18, (1<<ISC50)
			sbr r18, (1<<ISC51)
		#endif 
	#endif
	#ifdef _INT6_
		sbr r16, (1<<INT6)
		#ifdef _AnyEdge_INT6_
			sbr r18, (1<<ISC60)
		#elif defined _FallingEdge_INT6_
			sbr r18, (1<<ISC61)
		#elif defined _RisingEdge_INT6_
			sbr r18, (1<<ISC60)
			sbr r18, (1<<ISC61)
		#endif 
	#endif
	#ifdef _INT7_
		sbr r16, (1<<INT7)
		#ifdef _AnyEdge_INT7_
			sbr r18, (1<<ISC70)
		#elif defined _FallingEdge_INT7_
			sbr r18, (1<<ISC71)
		#elif defined _RisingEdge_INT7_
			sbr r18, (1<<ISC70)
			sbr r18, (1<<ISC71)
		#endif 
	#endif

	WRITE_REG EICRA, r17
	WRITE_REG EICRB, r18
	WRITE_REG EIMSK, r16
	
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
