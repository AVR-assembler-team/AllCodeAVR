.macro USARTMod2
	.if @0 == Asynchron
		SETB UCSRC, URSEL
		CLRB UCSRC, UMSEL
		CLRB UCSRC, URSEL
	.elif @0 == Synchron
		SETB UCSRC, URSEL
		SETB UCSRC, UMSEL
		CLRB UCSRC, URSEL
	.endif
.endm
.macro USART0Mod2
	.if @0 == Asynchron
		CLRB UCSR0C, UMSEL0
	.elif @0 == Synchron
		SETB UCSR0C, UMSEL0
	.endif
.endm
.macro USART0URSEL0Mod2
	.if @0 == Asynchron
		SETB UCSR0C, URSEL0
		CLRB UCSR0C, UMSEL0
		CLRB UCSR0C, URSEL0
	.elif @0 == Synchron
		SETB UCSR0C, URSEL0
		SETB UCSR0C, UMSEL0
		CLRB UCSR0C, URSEL0
	.endif
.endm
.macro USART0Mod3
	.if @0 == Asynchron
		CLRB UCSR0C, UMSEL0
		CLRB UCSR0C, UMSEL1
	.elif @0 == Synchron
		SETB UCSR0C, UMSEL0
		CLRB UCSR0C, UMSEL1
	.elif @0 == MasterSPI
		SETB UCSR0C, UMSEL0
		SETB UCSR0C, UMSEL1
	.endif
.endm
.macro USART1Mod2
	.if @0 == Asynchron
		CLRB UCSR1C, UMSEL1
	.elif @0 == Synchron
		SETB UCSR1C, UMSEL1
	.endif
.endm
.macro USART1URSEL1Mod2
	.if @0 == Asynchron
		SETB UCSR1C, URSEL1
		CLRB UCSR1C, UMSEL1
		CLRB UCSR1C, URSEL1
	.elif @0 == Synchron
		SETB UCSR1C, URSEL1
		SETB UCSR1C, UMSEL1
		CLRB UCSR1C, URSEL1
	.endif
.endm
.macro USART1Mod3
	.if @0 == Asynchron
		CLRB UCSR1C, UMSEL0
		CLRB UCSR1C, UMSEL1
	.elif @0 == Synchron
		SETB UCSR1C, UMSEL0
		CLRB UCSR1C, UMSEL1
	.elif @0 == MasterSPI
		SETB UCSR1C, UMSEL0
		SETB UCSR1C, UMSEL1	
	.endif
.endm
.macro USART00Mod3
	.if @0 == Asynchron
		CLRB UCSR0C, UMSEL00
		CLRB UCSR0C, UMSEL01
	.elif @0 == Synchron
		SETB UCSR0C, UMSEL00
		CLRB UCSR0C, UMSEL01
	.elif @0 == MasterSPI	
		SETB UCSR0C, UMSEL00
		SETB UCSR0C, UMSEL01
	.endif
.endm
.macro USART01Mod3
	.if @0 == Asynchron
		CLRB UCSR1C, UMSEL10
		CLRB UCSR1C, UMSEL11
	.elif @0 == Synchron
		SETB UCSR1C, UMSEL10
		CLRB UCSR1C, UMSEL11
	.elif @0 == MasterSPI	
		SETB UCSR1C, UMSEL10
		SETB UCSR1C, UMSEL11
	.endif
.endm
.macro USART02Mod3
	.if @0 == Asynchron
		CLRB UCSR2C, UMSEL20
		CLRB UCSR2C, UMSEL21
	.elif @0 == Synchron
		SETB UCSR2C, UMSEL20
		CLRB UCSR2C, UMSEL21
	.elif @0 == MasterSPI	
		SETB UCSR2C, UMSEL20
		SETB UCSR2C, UMSEL21
	.endif
.endm
.macro USART03Mod3
	.if @0 == Asynchron
		CLRB UCSR3C, UMSEL30
		CLRB UCSR3C, UMSEL31
	.elif @0 == Synchron
		SETB UCSR3C, UMSEL30
		CLRB UCSR3C, UMSEL31
	.elif @0 == MasterSPI	
		SETB UCSR3C, UMSEL30
		SETB UCSR3C, UMSEL31
	.endif
.endm
    
.macro USARTModeSelect
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
.endm
