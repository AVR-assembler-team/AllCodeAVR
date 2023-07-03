
.macro SetINT
	
	clr r16
	clr r17
	clr r18

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
	#if defined EnablePCINT8 || EnablePCINT9 || EnablePCINT10 || EnablePCINT11 || EnablePCINT12 || EnablePCINT13 || EnablePCINT14 || EnablePCINT15
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
		#ifdef EnablePCINT15
			sbr r17, (1<<PCINT15)
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
	#if defined EnablePCINT24 || EnablePCINT25 || EnablePCINT26 || EnablePCINT27 || EnablePCINT28 || EnablePCINT29 || EnablePCINT30 || EnablePCINT31
		.error "Pin 24-31 not supported."
	#endif	
		
	WRITE_REG PCICR, r16
 
.endm
