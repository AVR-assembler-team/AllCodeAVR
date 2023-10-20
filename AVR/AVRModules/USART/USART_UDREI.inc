    .macro USARTDataRegisterEmptyInterr
	.if @0 == Enable
	    SETB UCSRB, UDRIE
	.elif  @0 == Disable
	    CLRB UCSRB, UDRIE
	.endif
    .endm
    .macro USART0DataRegisterEmptyInterr
	.if @0 == Enable
	    SETB UCSR0B, UDRIE0
	.elif  @0 == Disable
	    CLRB UCSR0B, UDRIE0
	.endif
    .endm
    .macro USART1DataRegisterEmptyInterr
	.if @0 == Enable
	    SETB UCSR1B, UDRIE1
	.elif  @0 == Disable
	    CLRB UCSR1B, UDRIE1
	.endif
    .endm
    .macro USART2DataRegisterEmptyInterr
	.if @0 == Enable
	    SETB UCSR2B, UDRIE2
	.elif  @0 == Disable
	    CLRB UCSR2B, UDRIE2
	.endif
    .endm
    .macro USART3DataRegisterEmptyInterr
	.if @0 == Enable
	    SETB UCSR3B, UDRIE3
	.elif  @0 == Disable
	    CLRB UCSR3B, UDRIE3
	.endif
    .endm
    
    .macro USARTDataRegisterEmptyInterrupt
	.if @0 == 0
	    .if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		USARTDataRegisterEmptyInterr @1
	    .else
		USART0DataRegisterEmptyInterr @1
	    .endif
	.elif @0 == 1
	    USART1DataRegisterEmptyInterr @1
	.elif @0 == 2
	    .if ctrl != 1281 || ctrl != 2561
		USART2DataRegisterEmptyInterr @1
	    .endif
	.elif @0 == 3
	    .if ctrl != 1281 || ctrl != 2561
		USART3DataRegisterEmptyInterr @1
	    .endif
	.endif
    .endm
