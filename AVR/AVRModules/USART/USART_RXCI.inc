.macro USARTRXCompleteInterr
	READ_REG UCSRB, r25
	.if @0 == Enable
		SETRB r25, RXCIE
	.elif  @0 == Disable
		CLRRB r25, RXCIE
	.endif
	WRITE_REG UCSRB, r25
.endm
.macro USART0RXCompleteInterr
	READ_REG UCSR0B, r25
	.if @0 == Enable
		SETRB r25, RXCIE0
	.elif  @0 == Disable
		CLRRB r25, RXCIE0
	.endif
	WRITE_REG UCSR0B, r25
.endm
.macro USART1RXCompleteInterr
	READ_REG UCSR1B, r25
	.if @0 == Enable
		SETRB r25, RXCIE1
	.elif  @0 == Disable
		CLRRB r25, RXCIE1
	.endif
	WRITE_REG UCSR1B, r25
.endm
.macro USART2RXCompleteInterr
	READ_REG UCSR2B, r25
	.if @0 == Enable
		SETRB r25, RXCIE2
	.elif  @0 == Disable
		CLRRB r25, RXCIE2
	.endif
	WRITE_REG UCSR2B, r25
.endm
.macro USART3RXCompleteInterr
	READ_REG UCSR3B, r25
	.if @0 == Enable
		SETRB r25, RXCIE3
	.elif  @0 == Disable
		CLRRB r25, RXCIE3
	.endif
	WRITE_REG UCSR3B, r25
.endm
	
.macro RXCompleteInterrupt
	.if @0 == 0
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
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
