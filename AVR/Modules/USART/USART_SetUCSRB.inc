
.macro WriteUCSRB
	WRITE_REG @0, @1
.endm

.macro SetUCSRB

	clr r16
	clr r17
	clr r18
	clr r19

    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		#ifdef ReceiverEnable0
			sbr r16, (1<<RXEN)
		#endif
		#ifdef TransmitterEnable0
			sbr r16, (1<<TXEN)
		#endif
		#ifdef RXCompleteInterruptEnable0
			sbr r16, (1<<RXCIE)
		#endif
		#ifdef TXCompleteInterruptEnable0
			sbr r16, (1<<TXCIE)
		#endif
		#ifdef CharacterSize0_9bit
			sbr r16, (1<<UCSZ2)
		#endif
		WriteUCSRB UCSRB, r16

    .elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		#ifdef ReceiverEnable0
			sbr r16, (1<<RXEN0)
		#endif
		#ifdef TransmitterEnable0
			sbr r16, (1<<TXEN0)
		#endif
		#ifdef RXCompleteInterruptEnable0
			sbr r16, (1<<RXCIE0)
		#endif
		#ifdef TXCompleteInterruptEnable0
			sbr r16, (1<<TXCIE0)
		#endif
		#ifdef CharacterSize0_9bit
			sbr r16, (1<<UCSZ02)
		#endif
	
		#ifdef ReceiverEnable1
			sbr r17, (1<<RXEN1)
		#endif
		#ifdef TransmitterEnable1
			sbr r17, (1<<TXEN1)
		#endif
		#ifdef RXCompleteInterruptEnable1
			sbr r17, (1<<RXCIE1)
		#endif
		#ifdef TXCompleteInterruptEnable1
			sbr r17, (1<<TXCIE1)
		#endif
		#ifdef CharacterSize1_9bit
			sbr r17, (1<<UCSZ12)
		#endif

		#ifdef ReceiverEnable2
			sbr r18, (1<<RXEN2)
		#endif
		#ifdef TransmitterEnable2
			sbr r18, (1<<TXEN2)
		#endif
		#ifdef CharacterSize2_9bit
			sbr r18, (1<<UCSZ22)
		#endif
	
		#ifdef ReceiverEnable3
			sbr r19, (1<<RXEN3)
		#endif
		#ifdef TransmitterEnable3
			sbr r19, (1<<TXEN3)
		#endif
		#ifdef CharacterSize3_9bit
			sbr r19, (1<<UCSZ32)
		#endif
	
		.if ctlr == 640 || ctlr == 1280 || ctlr == 2560
			#ifdef RXCompleteInterruptEnable2
				sbr r18, (1<<RXCIE2)
			#endif
			#ifdef TXCompleteInterruptEnable2
				sbr r18, (1<<TXCIE2)
			#endif
	    
			#ifdef RXCompleteInterruptEnable3
				sbr r19, (1<<RXCIE3)
			#endif
			#ifdef TXCompleteInterruptEnable3
				sbr r19, (1<<TXCIE3)
			#endif
		.endif
		WriteUCSRB UCSR0B, r16
		WriteUCSRB UCSR1B, r17
		WriteUCSRB UCSR2B, r18
		WriteUCSRB UCSR3B, r19

    .elif ctlr == 64 || ctlr == 128 || ctlr == 162 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		#ifdef ReceiverEnable0
			sbr r16, (1<<RXEN0)
		#endif
		#ifdef TransmitterEnable0
			sbr r16, (1<<TXEN0)
		#endif
		#ifdef RXCompleteInterruptEnable0
			sbr r16, (1<<RXCIE0)
		#endif
		#ifdef TXCompleteInterruptEnable0
			sbr r16, (1<<TXCIE0)
		#endif
		#ifdef CharacterSize0_9bit
			sbr r16, (1<<UCSZ02)
		#endif
	
		#ifdef ReceiverEnable1
			sbr r17, (1<<RXEN1)
		#endif
		#ifdef TransmitterEnable1
			sbr r17, (1<<TXEN1)
		#endif
		#ifdef RXCompleteInterruptEnable1
			sbr r17, (1<<RXCIE1)
		#endif
		#ifdef TXCompleteInterruptEnable1
			sbr r17, (1<<TXCIE1)
		#endif
		#ifdef CharacterSize10_9bit
			sbr r17, (1<<UCSZ12)
		#endif
		WriteUCSRB UCSR0B, r16
		WriteUCSRB UCSR1B, r17

    .elif ctlr == 48 || ctlr == 88 || ctlr == 165 || ctlr == 168 || ctlr == 169 || ctlr == 325 || ctlr == 328 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		#ifdef ReceiverEnable0
			sbr r16, (1<<RXEN0)
		#endif
		#ifdef TransmitterEnable0
			sbr r16, (1<<TXEN0)
		#endif
		#ifdef RXCompleteInterruptEnable0
			sbr r16, (1<<RXCIE0)
		#endif
		#ifdef TXCompleteInterruptEnable0
			sbr r16, (1<<TXCIE0)
		#endif
		#ifdef CharacterSize0_9bit
			sbr r16, (1<<UCSZ02)
		#endif
		WriteUCSRB UCSR0B, r16

    .endif

.endm
