.macro USARTTXCompleteInterr
	READ_REG UCSRB, r25
	.if @0 == Enable
		SETRB r25, TXCIE
	.elif  @0 == Disable
		CLRRB r25, TXCIE
	.endif
	WRITE_REG UCSRB, r25
.endm
.macro USART0TXCompleteInterr
	READ_REG UCSR0B, r25
	.if @0 == Enable
		SETRB r25, TXCIE0
	.elif  @0 == Disable
		CLRRB r25, TXCIE0
	.endif
	WRITE_REG UCSR0B, r25
.endm
.macro USART1TXCompleteInterr
	READ_REG UCSR1B, r25
	.if @0 == Enable
		SETRB r25, TXCIE1
	.elif  @0 == Disable
		CLRRB r25, TXCIE1
	.endif
	WRITE_REG UCSR1B, r25
.endm
.macro USART2TXCompleteInterr
	READ_REG UCSR2B, r25
	.if @0 == Enable
		SETRB r25, TXCIE2
	.elif  @0 == Disable
		CLRRB r25, TXCIE2
	.endif
	WRITE_REG UCSR2B, r25
.endm
.macro USART3TXCompleteInterr
	READ_REG UCSR3B, r25
	.if @0 == Enable
		SETRB r25, TXCIE3
	.elif  @0 == Disable
		CLRRB r25, TXCIE3
	.endif
	WRITE_REG UCSR3B, r25
.endm

.macro TXCompleteInterrupt
	.if @0 == 0
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
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
