    .macro USARTReceiv
	.if @0 == enabled
	    SETB UCSRB, RXEN
	.elif @0 == disabled
	    CLRB UCSRB, RXEN
	.endif
    .endm
    .macro USART0Receiv
	.if @0 == enabled
	    SETB UCSR0B, RXEN0
	.elif  @0 == disabled
	    CLRB UCSR0B, RXEN0
	.endif
    .endm
    .macro USART1Receiv
	.if @0 == enabled
	    SETB UCSR1B, RXEN1
	.elif  @0 == disabled
	    CLRB UCSR1B, RXEN1
	.endif
    .endm
    .macro USART2Receiv
	.if @0 == enabled
	    SETB UCSR2B, RXEN2
	.elif  @0 == disabled
	    CLRB UCSR2B, RXEN2
	.endif
    .endm
    .macro USART3Receiv
	.if @0 == enabled
	    SETB UCSR3B, RXEN3
	.elif  @0 == disabled
	    CLRB UCSR3B, RXEN3
	.endif
    .endm
    
    
    .macro USARTReceiver
	.if @0 == 0
	    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		USARTReceiv @1
	    .else
		USART0Receiv @1
	    .endif
	.elif @0 == 1
	    USART1Receiv @1
	.elif @0 == 2
	    .if ctlr != 1281 || ctlr != 2561
		USART2Receiv @1
	    .endif
	.elif @0 == 3
	    .if ctlr != 1281 || ctlr != 2561
		USART3Receiv @1
	    .endif
	.endif
    .endm


