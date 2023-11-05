.macro USARTReceiv
	.if @0 == Enable
		SETB UCSRB, RXEN
	.elif @0 == Disable
		CLRB UCSRB, RXEN
	.endif
.endm
.macro USART0Receiv
	.if @0 == Enable
		SETB UCSR0B, RXEN0
	.elif  @0 == Disable
		CLRB UCSR0B, RXEN0
	.endif
.endm
.macro USART1Receiv
	.if @0 == Enable
		SETB UCSR1B, RXEN1
	.elif  @0 == Disable
		CLRB UCSR1B, RXEN1
	.endif
.endm
.macro USART2Receiv
	.if @0 == Enable
		SETB UCSR2B, RXEN2
	.elif  @0 == Disable
		CLRB UCSR2B, RXEN2
	.endif
.endm
.macro USART3Receiv
	.if @0 == Enable
		SETB UCSR3B, RXEN3
	.elif  @0 == Disable
		CLRB UCSR3B, RXEN3
	.endif
.endm
    
    
.macro USARTReceiver
	.if @0 == 0
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		USARTReceiv @1
		.else
		USART0Receiv @1
		.endif
	.elif @0 == 1
		USART1Receiv @1
	.elif @0 == 2
		.if ctrl != 1281 || ctrl != 2561
		USART2Receiv @1
		.endif
	.elif @0 == 3
		.if ctrl != 1281 || ctrl != 2561
		USART3Receiv @1
		.endif
	.endif
.endm
