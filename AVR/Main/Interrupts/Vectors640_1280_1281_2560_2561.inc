
	.org 0x0000	 jmp RESET ; Reset Handler
	.org 0x0002 jmp EXT_INT0 ; IRQ0 Handler
	.org 0x0004 jmp EXT_INT1 ; IRQ1 Handler
	.org 0x0006 jmp EXT_INT2 ; IRQ2 Handler
	.org 0x0008 jmp EXT_INT3 ; IRQ3 Handler
	.org 0x000A jmp EXT_INT4 ; IRQ4 Handler
	.org 0x000C jmp EXT_INT5 ; IRQ5 Handler
	.org 0x000E jmp EXT_INT6 ; IRQ6 Handler
	.org 0x0010 jmp EXT_INT7 ; IRQ7 Handler
	.org 0x0012 jmp EXT_PCINT0 ; PCINT0 Handler
	.org 0x0014 jmp EXT_PCINT1 ; PCINT1 Handler
	.org 0x0016 jmp EXT_PCINT2 ; PCINT2 Handler
	.org 0X0018 jmp WDT ; Watchdog Timeout Handler
	.org 0x001A jmp TIM2_COMPA ; Timer2 CompareA Handler
	.org 0x001C jmp TIM2_COMPB ; Timer2 CompareB Handler
	.org 0x001E jmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x0020 jmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x0022 jmp TIM1_COMPA ; Timer1 CompareA Handler
	.org 0x0024 jmp TIM1_COMPB ; Timer1 CompareB Handler
	.org 0x0026 jmp TIM1_COMPC ; Timer1 CompareC Handler
	.org 0x0028 jmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x002A jmp TIM0_COMPA ; Timer0 CompareA Handler
	.org 0x002C jmp TIM0_COMPB ; Timer0 CompareB Handler
	.org 0x002E jmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x0030 jmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x0032 jmp USART0_RXC ; USART0 RX Complete Handler
	.org 0x0034 jmp USART0_UDRE ; USART0,UDR Empty Handler
	.org 0x0036 jmp USART0_TXC ; USART0 TX Complete Handler
	.org 0x0038 jmp ANA_COMP ; Analog Comparator Handler
	.org 0x003A jmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org 0x003C jmp EE_RDY ; EEPROM Ready Handler
	.org 0x003E jmp TIM3_CAPT ; Timer3 Capture Handler
	.org 0x0040 jmp TIM3_COMPA ; Timer3 CompareA Handler
	.org 0x0042 jmp TIM3_COMPB ; Timer3 CompareB Handler
	.org 0x0044 jmp TIM3_COMPC ; Timer3 CompareC Handler
	.org 0x0046 jmp TIM3_OVF ; Timer3 Overflow Handler
	.org 0x0048 jmp USART1_RXC ; USART1 RX Complete Handler
	.org 0x004A jmp USART1_UDRE ; USART1,UDR Empty Handler
	.org 0x004C jmp USART1_TXC ; USART1 TX Complete Handler
	.org 0x004E jmp TWSI ; 2-wire Serial Handler
	.org 0x0050 jmp SPM_RDY ; SPM Ready Handler
	.if ctrl == 640 || ctrl == 1280 || ctrl == 2560
		.org 0x0052 jmp TIM4_CAPT ; Timer4 Capture Handler
	.endif
	.org 0x0054 jmp TIM4_COMPA ; Timer4 CompareA Handler
	.org 0x0056 jmp TIM4_COMPB ; Timer4 CompareB Handler
	.org 0x0058 jmp TIM4_COMPC ; Timer4 CompareC Handler
	.org 0x005A jmp TIM4_OVF ; Timer4 Overflow Handler
	.if ctrl == 640 || ctrl == 1280 || ctrl == 2560
		.org 0x005C jmp TIM5_CAPT ; Timer5 Capture Handler
	.endif
	.org 0x005E jmp TIM5_COMPA ; Timer5 CompareA Handler
	.org 0x0060 jmp TIM5_COMPB ; Timer5 CompareB Handler
	.org 0x0062 jmp TIM5_COMPC ; Timer5 CompareC Handler
	.org 0x0064 jmp TIM5_OVF ; Timer5 Overflow Handler
	.if ctrl == 640 || ctrl == 1280 || ctrl == 2560
		.org 0x0066 jmp USART2_RXC ; USART2 RX Complete Handler
		.org 0x0068 jmp USART2_UDRE ; USART2,UDR Empty Handler
		.org 0x006A jmp USART2_TXC ; USART2 TX Complete Handler
		.org 0x006C jmp USART3_RXC ; USART3 RX Complete Handler
		.org 0x006E jmp USART3_UDRE ; USART3,UDR Empty Handler
		.org 0x0070 jmp USART3_TXC ; USART3 TX Complete Handler
	.endif
