.macro USARTMod2
	.if @0 == asynchron
		SETB UCSRC, URSEL
		CLRB UCSRC, UMSEL
		CLRB UCSRC, URSEL
	.elif @0 == synchron
		SETB UCSRC, URSEL
		SETB UCSRC, UMSEL
		CLRB UCSRC, URSEL
	.endif
.endm
.macro USART0Mod2
	.if @0 == asynchron
		CLRB UCSR0C, UMSEL0
	.elif @0 == synchron
		SETB UCSR0C, UMSEL0
	.endif
.endm
.macro USART0URSEL0Mod2
	.if @0 == asynchron
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UMSEL0
		CLRB UCSR0C, URSEL0
	.elif @0 == synchron
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UMSEL0
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro USART0Mod3
	.if @0 == asynchron
		CLRB UCSR0C, UMSEL0
		CLRB UCSR0C, UMSEL1
	.elif @0 == synchron
		SETB UCSR0C, UMSEL0
		CLRB UCSR0C, UMSEL1
	.elif @0 == masterSPI
		SETB UCSR0C, UMSEL0
		SETB UCSR0C, UMSEL1
	.endif
.endm
.macro USART1Mod2
	.if @0 == asynchron
		CLRB UCSR1C, UMSEL1
	.elif @0 == synchron
		SETB UCSR1C, UMSEL1
	.endif
.endm
.macro USART1URSEL1Mod2
	.if @0 == asynchron
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UMSEL1
		CLRB UCSR1C, URSEL1
	.elif @0 == synchron
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UMSEL1
		CLRB UCSR1C, URSEL1
	.endif
.endm
.macro USART1Mod3
	.if @0 == asynchron
		CLRB UCSR1C, UMSEL0
		CLRB UCSR1C, UMSEL1
	.elif @0 == synchron
		SETB UCSR1C, UMSEL0
		CLRB UCSR1C, UMSEL1
	.elif @0 == masterSPI
		SETB UCSR1C, UMSEL0
		SETB UCSR1C, UMSEL1	
	.endif
.endm
.macro USART00Mod3
	.if @0 == asynchron
		CLRB UCSR0C, UMSEL00
		CLRB UCSR0C, UMSEL01
	.elif @0 == synchron
		SETB UCSR0C, UMSEL00
		CLRB UCSR0C, UMSEL01
	.elif @0 == masterSPI	
		SETB UCSR0C, UMSEL00
		SETB UCSR0C, UMSEL01
	.endif
.endm
.macro USART01Mod3
	.if @0 == asynchron
		CLRB UCSR1C, UMSEL10
		CLRB UCSR1C, UMSEL11
	.elif @0 == synchron
		SETB UCSR1C, UMSEL10
		CLRB UCSR1C, UMSEL11
	.elif @0 == masterSPI	
		SETB UCSR1C, UMSEL10
		SETB UCSR1C, UMSEL11
	.endif
.endm
.macro USART02Mod3
	.if @0 == asynchron
		CLRB UCSR2C, UMSEL20
		CLRB UCSR2C, UMSEL21
	.elif @0 == synchron
		SETB UCSR2C, UMSEL20
		CLRB UCSR2C, UMSEL21
	.elif @0 == masterSPI	
		SETB UCSR2C, UMSEL20
		SETB UCSR2C, UMSEL21
	.endif
.endm
.macro USART03Mod3
	.if @0 == asynchron
		CLRB UCSR3C, UMSEL30
		CLRB UCSR3C, UMSEL31
	.elif @0 == synchron
		SETB UCSR3C, UMSEL30
		CLRB UCSR3C, UMSEL31
	.elif @0 == masterSPI	
		SETB UCSR3C, UMSEL30
		SETB UCSR3C, UMSEL31
	.endif
.endm
    
.macro USARTModeSelect
	.if ctlr == 8 || ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
		.if @0 == 0	
		USARTMod2 @1
		.endif
	.elif ctlr == 162
		.if @0 == 0    
		USART0URSEL0Mod2 @1
		.elif @0 == 1
		USART1URSEL1Mod2 @1
		.endif
	.elif ctlr == 165 || ctlr == 169 || ctlr == 325 || ctlr == 329 || ctlr == 645 || ctlr == 649 || ctlr == 3250 || ctlr == 3290 || ctlr == 6450 || ctlr == 6490
		.if @0 == 0        
		USART0Mod2 @1
		.endif
	.elif ctlr == 48 || ctlr == 88 || ctlr == 168 || ctlr == 328 || ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == 0     
		USART00Mod3 @1
		.elif @0 == 1
		USART01Mod3 @1
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
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
.endm
