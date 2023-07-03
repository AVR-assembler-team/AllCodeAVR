    .macro USARTTransmit
	.if @0 == enabled
	    SETB UCSRB, TXEN
	.elif  @0 == disabled
	    CLRB UCSRB, TXEN
	.endif
    .endm
    .macro USART0Transmit
	.if @0 == enabled
	    SETB UCSR0B, TXEN0
	.elif  @0 == disabled
	    CLRB UCSR0B, TXEN0
	.endif
    .endm
    .macro USART1Transmit
	.if @0 == enabled
	    SETB UCSR1B, TXEN1
	.elif  @0 == disabled
	    CLRB UCSR1B, TXEN1
	.endif
    .endm
    .macro USART2Transmit
	.if @0 == enabled
	    SETB UCSR2B, TXEN2
	.elif  @0 == disabled
	    CLRB UCSR2B, TXEN2
	.endif
    .endm
    .macro USART3Transmit
	.if @0 == enabled
	    SETB UCSR3B, TXEN3
	.elif  @0 == disabled
	    CLRB UCSR3B, TXEN3
	.endif
    .endm
    
    .macro USARTTransmitter
	.if @0 == 0
	    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		USARTTransmit @1
	    .else
		USART0Transmit @1
		ldi r20, $ff
	    .endif
	.elif @0 == 1
	    USART1Transmit @1
	.elif @0 == 2
	    .if ctlr != 1281 || ctlr != 2561
		USART2Transmit @1
	    .endif
	.elif @0 == 3
	    .if ctlr != 1281 || ctlr != 2561
		USART3Transmit @1
	    .endif
	.endif
    .endm
