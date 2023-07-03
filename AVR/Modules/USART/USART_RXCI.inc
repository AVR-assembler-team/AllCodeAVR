    .macro USARTRXCompleteInterr
	.if @0 == enabled
	    SETB UCSRB, RXCIE
	.elif  @0 == disabled
	    CLRB UCSRB, RXCIE
	.endif
    .endm
    .macro USART0RXCompleteInterr
	.if @0 == enabled
	    SETB UCSR0B, RXCIE0
	.elif  @0 == disabled
	    CLRB UCSR0B, RXCIE0
	.endif
    .endm
    .macro USART1RXCompleteInterr
	.if @0 == enabled
	    SETB UCSR1B, RXCIE1
	.elif  @0 == disabled
	    CLRB UCSR1B, RXCIE1
	.endif
    .endm
    .macro USART2RXCompleteInterr
	.if @0 == enabled
	    SETB UCSR2B, RXCIE2
	.elif  @0 == disabled
	    CLRB UCSR2B, RXCIE2
	.endif
    .endm
    .macro USART3RXCompleteInterr
	.if @0 == enabled
	    SETB UCSR3B, RXCIE3
	.elif  @0 == disabled
	    CLRB UCSR3B, RXCIE3
	.endif
    .endm
	
    .macro RXCompleteInterrupt
	.if @0 == 0
	    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		USARTRXCompleteInterr @1
	    .else
		USART0RXCompleteInterr @1
	    .endif
	.elif @0 == 1
	    USART1RXCompleteInterr @1
	.elif @0 == 2
	    USART2RXCompleteInterr @1
	.elif @0 == 3
	    USART3RXCompleteInterr @1
	.endif
    .endm
