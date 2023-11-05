.macro USARTMod2
	READ_REG UCSRC, r25
	.if @0 == Asynchron
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, UMSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.elif @0 == Synchron
		SETRB r25, URSEL
		WRITE_REG UCSRC, r25
		SETRB r25, UMSEL
		WRITE_REG UCSRC, r25
		CLRRB r25, URSEL
		WRITE_REG UCSRC, r25
	.endif
.endm
.macro USART0Mod2
	READ_REG UCSR0C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL0
	.elif @0 == Synchron
		SETRB r25, UMSEL0
	.endif
	WRITE_REG UCSR0C, r25
.endm
.macro USART0URSEL0Mod2
	READ_REG UCSR0C, r25
	.if @0 == Asynchron
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, UMSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.elif @0 == Synchron
		SETRB r25, URSEL0
		WRITE_REG UCSR0C, r25
		SETRB r25, UMSEL0
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL0
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro USART0Mod3
	READ_REG UCSR0C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL0
		CLRRB r25, UMSEL1
	.elif @0 == Synchron
		SETRB r25, UMSEL0
		CLRRB r25, UMSEL1
	.elif @0 == MasterSPI
		SETRB r25, UMSEL0
		SETRB r25, UMSEL1
	.endif
	WRITE_REG UCSR0C, r25
.endm
.macro USART1Mod2
	READ_REG UCSR1C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL1
	.elif @0 == Synchron
		SETRB r25, UMSEL1
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro USART1URSEL1Mod2
	READ_REG UCSR1C, r25
	.if @0 == Asynchron
		SETRB r25, URSEL1
		WRITE_REG UCSR0C, r25
		CLRRB r25, UMSEL1
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR0C, r25
	.elif @0 == Synchron
		SETRB r25, URSEL1
		WRITE_REG UCSR0C, r25
		SETRB r25, UMSEL1
		WRITE_REG UCSR0C, r25
		CLRRB r25, URSEL1
		WRITE_REG UCSR0C, r25
	.endif
.endm
.macro USART1Mod3
	READ_REG UCSR1C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL0
		CLRRB r25, UMSEL1
	.elif @0 == Synchron
		SETRB r25, UMSEL0
		CLRRB r25, UMSEL1
	.elif @0 == MasterSPI
		SETRB r25, UMSEL0
		SETRB r25, UMSEL1	
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro USART00Mod3
	READ_REG UCSR0C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL00
		CLRRB r25, UMSEL01
	.elif @0 == Synchron
		SETRB r25, UMSEL00
		CLRRB r25, UMSEL01
	.elif @0 == MasterSPI	
		SETRB r25, UMSEL00
		SETRB r25, UMSEL01
	.endif
	WRITE_REG UCSR0C, r25
.endm
.macro USART01Mod3
	READ_REG UCSR1C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL10
		CLRRB r25, UMSEL11
	.elif @0 == Synchron
		SETRB r25, UMSEL10
		CLRRB r25, UMSEL11
	.elif @0 == MasterSPI	
		SETRB r25, UMSEL10
		SETRB r25, UMSEL11
	.endif
	WRITE_REG UCSR1C, r25
.endm
.macro USART02Mod3
	READ_REG UCSR2C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL20
		CLRRB r25, UMSEL21
	.elif @0 == Synchron
		SETRB r25, UMSEL20
		CLRRB r25, UMSEL21
	.elif @0 == MasterSPI	
		SETRB r25, UMSEL20
		SETRB r25, UMSEL21
	.endif
	WRITE_REG UCSR2C, r25
.endm
.macro USART03Mod3
	READ_REG UCSR3C, r25
	.if @0 == Asynchron
		CLRRB r25, UMSEL30
		CLRRB r25, UMSEL31
	.elif @0 == Synchron
		SETRB r25, UMSEL30
		CLRRB r25, UMSEL31
	.elif @0 == MasterSPI	
		SETRB r25, UMSEL30
		SETRB r25, UMSEL31
	.endif
	WRITE_REG UCSR3C, r25
.endm
    
.macro USARTModeSelect

	push r25

	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
		USARTMod2 @1
		.endif
	.elif ctrl == 162
		.if @0 == 0    
		USART0URSEL0Mod2 @1
		.elif @0 == 1
		USART1URSEL1Mod2 @1
		.endif
	.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 329 || ctrl == 645 || ctrl == 649 || ctrl == 3250 || ctrl == 3290 || ctrl == 6450 || ctrl == 6490
		.if @0 == 0        
		USART0Mod2 @1
		.endif
	.elif ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 328 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
		.if @0 == 0     
		USART00Mod3 @1
		.elif @0 == 1
		USART01Mod3 @1
		.endif
	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == 0     
		USART00Mod3 @1
		.elif @0 == 1
		USART01Mod3 @1
		.elif @0 == 2
		USART02Mod3 @1
		.elif @0 == 3
		USART03Mod3 @1
		.endif
	.endif

	pop r25

.endm
