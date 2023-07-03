    .macro USARTTXCompleteInterr
	.if @0 == enabled
	    SETB UCSRB, TXCIE
	.elif  @0 == disabled
	    CLRB UCSRB, TXCIE
	.endif
    .endm
    .macro USART0TXCompleteInterr
	.if @0 == enabled
	    SETB UCSR0B, TXCIE0
	.elif  @0 == disabled
	    CLRB UCSR0B, TXCIE0
	.endif
    .endm
    .macro USART1TXCompleteInterr
	.if @0 == enabled
	    SETB UCSR1B, TXCIE1
	.elif  @0 == disabled
	    CLRB UCSR1B, TXCIE1
	.endif
    .endm
    .macro USART2TXCompleteInterr
	.if @0 == enabled
	    SETB UCSR2B, TXCIE2
	.elif  @0 == disabled
	    CLRB UCSR2B, TXCIE2
	.endif
    .endm
    .macro USART3TXCompleteInterr
	.if @0 == enabled
	    SETB UCSR3B, TXCIE3
	.elif  @0 == disabled
	    CLRB UCSR3B, TXCIE3
	.endif
    .endm

    .macro TXCompleteInterrupt
	.if @0 == 0
	    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		USARTTXCompleteInterr @1
	    .else
		USART0TXCompleteInterr @1
	    .endif
	.elif @0 == 1
	    USART1TXCompleteInterr @1
	.elif @0 == 2
	    USART2TXCompleteInterr @1
	.elif @0 == 3
	    USART3TXCompleteInterr @1
	.endif
    .endm
