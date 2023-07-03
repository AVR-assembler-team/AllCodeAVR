    .macro USARTDataRegisterEmptyInterr
	.if @0 == enabled
	    SETB UCSRB, UDRIE
	.elif  @0 == disabled
	    CLRB UCSRB, UDRIE
	.endif
    .endm
    .macro USART0DataRegisterEmptyInterr
	.if @0 == enabled
	    SETB UCSR0B, UDRIE0
	.elif  @0 == disabled
	    CLRB UCSR0B, UDRIE0
	.endif
    .endm
    .macro USART1DataRegisterEmptyInterr
	.if @0 == enabled
	    SETB UCSR1B, UDRIE1
	.elif  @0 == disabled
	    CLRB UCSR1B, UDRIE1
	.endif
    .endm
    .macro USART2DataRegisterEmptyInterr
	.if @0 == enabled
	    SETB UCSR2B, UDRIE2
	.elif  @0 == disabled
	    CLRB UCSR2B, UDRIE2
	.endif
    .endm
    .macro USART3DataRegisterEmptyInterr
	.if @0 == enabled
	    SETB UCSR3B, UDRIE3
	.elif  @0 == disabled
	    CLRB UCSR3B, UDRIE3
	.endif
    .endm
    
    .macro USARTDataRegisterEmptyInterrupt
	.if @0 == 0
	    .if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		USARTDataRegisterEmptyInterr @1
	    .else
		USART0DataRegisterEmptyInterr @1
	    .endif
	.elif @0 == 1
	    USART1DataRegisterEmptyInterr @1
	.elif @0 == 2
	    .if ctlr != 1281 || ctlr != 2561
		USART2DataRegisterEmptyInterr @1
	    .endif
	.elif @0 == 3
	    .if ctlr != 1281 || ctlr != 2561
		USART3DataRegisterEmptyInterr @1
	    .endif
	.endif
    .endm
