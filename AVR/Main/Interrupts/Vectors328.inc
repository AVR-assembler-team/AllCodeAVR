
	.org 0x0000 jmp RESET ; Reset Handler
	.org 0x0002 jmp EXT_INT0 ; IRQ0 Handler
	.org 0x0004 jmp EXT_INT1 ; IRQ1 Handler
	.org 0x0006 jmp EXT_PCINT0 ; PCINT0 Handler
	.org 0x0008 jmp EXT_PCINT1 ; PCINT1 Handler
	.org 0x000A jmp EXT_PCINT2 ; PCINT2 Handler
	.org 0x000C jmp WDT ; Watchdog Timer Handler
	.org 0x000E jmp TIM2_COMPA ; Timer2 Compare A Handler
	.org 0x0010 jmp TIM2_COMPB ; Timer2 Compare B Handler
	.org 0x0012 jmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x0014 jmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x0016 jmp TIM1_COMPA ; Timer1 Compare A Handler
	.org 0x0018 jmp TIM1_COMPB ; Timer1 Compare B Handler
	.org 0x001A jmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x001C jmp TIM0_COMPA ; Timer0 Compare A Handler
	.org 0x001E jmp TIM0_COMPB ; Timer0 Compare B Handler
	.org 0x0020 jmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x0022 jmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x0024 jmp USART0_RXC ; USART, RX Complete Handler
	.org 0x0026 jmp USART0_UDRE ; USART, UDR Empty Handler
	.org 0x0028 jmp USART0_TXC ; USART, TX Complete Handler
	.org 0x002A jmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org 0x002C jmp EE_RDY ; EEPROM Ready Handler
	.org 0x002E jmp ANA_COMP ; Analog Comparator Handler
	.org 0x0030 jmp TWSI ; 2-wire Serial Interface Handler
	.org 0x0032 jmp SPM_RDY ; Store Program Memory Ready Handler

