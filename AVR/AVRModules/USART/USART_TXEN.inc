.macro USARTTransmit
	READ_REG UCSRB, r25
	.if @0 == Enable
		SETRB r25, TXEN
	.elif  @0 == Disable
		CLRRB r25, TXEN
	.endif
	WRITE_REG UCSRB, r25
.endm
.macro USART0Transmit
	READ_REG UCSR0B, r25
	.if @0 == Enable
		SETRB r25, TXEN0
	.elif  @0 == Disable
		CLRRB r25, TXEN0
	.endif
	WRITE_REG UCSR0B, r25
.endm
.macro USART1Transmit
	READ_REG UCSR1B, r25
	.if @0 == Enable
		SETRB r25, TXEN1
	.elif  @0 == Disable
		CLRRB r25, TXEN1
	.endif
	WRITE_REG UCSR1B, r25
.endm
.macro USART2Transmit
	READ_REG UCSR2B, r25
	.if @0 == Enable
		SETRB r25, TXEN2
	.elif  @0 == Disable
		CLRRB r25, TXEN2
	.endif
	WRITE_REG UCSR2B, r25
.endm
.macro USART3Transmit
	READ_REG UCSR3B, r25
	.if @0 == Enable
		SETRB r25, TXEN3
	.elif  @0 == Disable
		CLRRB r25, TXEN3
	.endif
	WRITE_REG UCSR3B, r25
.endm
    
.macro USARTTransmitter
	.if @0 == 0
	    .if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		USARTTransmit @1
	    .else
		USART0Transmit @1
		ldi r20, $ff
	    .endif
	.elif @0 == 1
	    USART1Transmit @1
	.elif @0 == 2
	    .if ctrl != 1281 || ctrl != 2561
		USART2Transmit @1
	    .endif
	.elif @0 == 3
	    .if ctrl != 1281 || ctrl != 2561
		USART3Transmit @1
	    .endif
	.endif
.endm
