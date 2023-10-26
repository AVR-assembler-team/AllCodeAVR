.macro USARTReceiv
	READ_REG UCSRB, r25
	.if @0 == Enable
		SETRB r25, RXEN
	.elif @0 == Disable
		CLRRB r25, RXEN
	.endif
	WRITE_REG UCSRB, r25
.endm
.macro USART0Receiv
	READ_REG UCSR0B, r25
	.if @0 == Enable
		SETRB r25, RXEN0
	.elif  @0 == Disable
		CLRRB r25, RXEN0
	.endif
	WRITE_REG UCSR0B, r25
.endm
.macro USART1Receiv
	READ_REG UCSR1B, r25
	.if @0 == Enable
		SETRB r25, RXEN1
	.elif  @0 == Disable
		CLRRB r25, RXEN1
	.endif
	WRITE_REG UCSR1B, r25
.endm
.macro USART2Receiv
	READ_REG UCSR2B, r25
	.if @0 == Enable
		SETRB r25, RXEN2
	.elif  @0 == Disable
		CLRRB r25, RXEN2
	.endif
	WRITE_REG UCSR2B, r25
.endm
.macro USART3Receiv
	READ_REG UCSR3B, r25
	.if @0 == Enable
		SETRB r25, RXEN3
	.elif  @0 == Disable
		CLRRB r25, RXEN3
	.endif
	WRITE_REG UCSR3B, r25
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
