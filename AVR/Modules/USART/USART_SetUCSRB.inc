
.macro WriteUCSRB
	WRITE_REG @0, @1
.endm

.macro SetUCSRB

	clr r16
	clr r17
	clr r18
	clr r19

    .if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
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

    .elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
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
	
		.if ctrl == 640 || ctrl == 1280 || ctrl == 2560
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

    .elif ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
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

    .elif ctrl == 48 || ctrl == 88 || ctrl == 165 || ctrl == 168 || ctrl == 169 || ctrl == 325 || ctrl == 328 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
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
