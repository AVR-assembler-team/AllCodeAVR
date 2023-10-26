.macro USARTDataRegisterEmptyInterr
	READ_REG UCSRB, r25
	.if @0 == Enable
		SETRB r25, UDRIE
	.elif  @0 == Disable
		CLRRB r25, UDRIE
	.endif
	WRITE_REG UCSRB, r25
.endm
.macro USART0DataRegisterEmptyInterr
	READ_REG UCSR0B, r25
	.if @0 == Enable
		SETRB r25, UDRIE0
	.elif  @0 == Disable
		CLRRB r25, UDRIE0
	.endif
	WRITE_REG UCSR0B, r25
.endm
.macro USART1DataRegisterEmptyInterr
	READ_REG UCSR1B, r25
	.if @0 == Enable
		SETRB r25, UDRIE1
	.elif  @0 == Disable
		CLRRB r25, UDRIE1
	.endif
	WRITE_REG UCSR1B, r25
.endm
.macro USART2DataRegisterEmptyInterr
	READ_REG UCSR2B, r25
	.if @0 == Enable
		SETRB r25, UDRIE2
	.elif  @0 == Disable
		CLRRB r25, UDRIE2
	.endif
	WRITE_REG UCSR2B, r25
.endm
.macro USART3DataRegisterEmptyInterr
	READ_REG UCSR3B, r25
	.if @0 == Enable
		SETRB r25, UDRIE3
	.elif  @0 == Disable
		CLRRB r25, UDRIE3
	.endif
	WRITE_REG UCSR3B, r25
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
