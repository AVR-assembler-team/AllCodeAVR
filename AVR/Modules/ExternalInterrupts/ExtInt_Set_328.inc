
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
		
	WRITE_REG EICRA, r17
	WRITE_REG EIMSK, r16

	#if defined EnablePCINT0 || EnablePCINT1 || EnablePCINT2 || EnablePCINT3 || EnablePCINT4 || EnablePCINT5 || EnablePCINT6 || EnablePCINT7
		sbr r16, (1<<PCIE0)
		#ifdef EnablePCINT0
			sbr r17, (1<<PCINT0)
		#endif
		#ifdef EnablePCINT1
			sbr r17, (1<<PCINT1)
		#endif
		#ifdef EnablePCINT2
			sbr r17, (1<<PCINT2)
		#endif
		#ifdef EnablePCINT3
			sbr r17, (1<<PCINT3)
		#endif
		#ifdef EnablePCINT4
			sbr r17, (1<<PCINT4)
		#endif
		#ifdef EnablePCINT5
			sbr r17, (1<<PCINT5)
		#endif
		#ifdef EnablePCINT6
			sbr r17, (1<<PCINT6)
		#endif
		#ifdef EnablePCINT7
			sbr r17, (1<<PCINT7)
		#endif
		WRITE_REG PCMSK0, r17
	#endif
	#if defined EnablePCINT8 || EnablePCINT9 || EnablePCINT10 || EnablePCINT11 || EnablePCINT12 || EnablePCINT13 || EnablePCINT14
		sbr r16, (1<<PCIE1)
		#ifdef EnablePCINT8
			sbr r17, (1<<PCINT8)
		#endif
		#ifdef EnablePCINT9
			sbr r17, (1<<PCINT9)
		#endif
		#ifdef EnablePCINT10
			sbr r17, (1<<PCINT10)
		#endif
		#ifdef EnablePCINT11
			sbr r17, (1<<PCINT11)
		#endif
		#ifdef EnablePCINT12
			sbr r17, (1<<PCINT12)
		#endif
		#ifdef EnablePCINT13
			sbr r17, (1<<PCINT13)
		#endif
		#ifdef EnablePCINT14
			sbr r17, (1<<PCINT14)
		#endif
		WRITE_REG PCMSK1, r17
	#endif
	#if defined EnablePCINT16 || EnablePCINT17 || EnablePCINT18 || EnablePCINT19 || EnablePCINT20 || EnablePCINT21 || EnablePCINT22 || EnablePCINT23
		sbr r16, (1<<PCIE2)
		#ifdef EnablePCINT16
			sbr r17, (1<<PCINT16)
		#endif
		#ifdef EnablePCINT17
			sbr r17, (1<<PCINT17)
		#endif
		#ifdef EnablePCINT18
			sbr r17, (1<<PCINT18)
		#endif
		#ifdef EnablePCINT19
			sbr r17, (1<<PCINT19)
		#endif
		#ifdef EnablePCINT20
			sbr r17, (1<<PCINT20)
		#endif
		#ifdef EnablePCINT21
			sbr r17, (1<<PCINT21)
		#endif
		#ifdef EnablePCINT22
			sbr r17, (1<<PCINT22)
		#endif
		#ifdef EnablePCINT23
			sbr r17, (1<<PCINT23)
		#endif
		WRITE_REG PCMSK2, r17
	#endif		
	#if defined EnablePCINT15 || EnablePCINT24 || EnablePCINT25 || EnablePCINT26 || EnablePCINT27 || EnablePCINT28 || EnablePCINT29 || EnablePCINT30 || EnablePCINT31
		.error "Pins PCINT15, PCINT24 - PCINT31 are not supported."
	#endif	
		
	WRITE_REG PCICR, r16

.endm
