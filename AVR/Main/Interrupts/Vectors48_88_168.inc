
	.org 0x000 rjmp RESET ; Reset Handler
	.org 0x001 rjmp EXT_INT0 ; IRQ0 Handler
	.org 0x002 rjmp EXT_INT1 ; IRQ1 Handler
	.org 0x003 rjmp EXT_PCINT0 ; PCINT0 Handler
	.org 0x004 rjmp EXT_PCINT1 ; PCINT1 Handler
	.org 0x005 rjmp EXT_PCINT2 ; PCINT2 Handler
	.org 0x006 rjmp WDT ; Watchdog Timer Handler
	.org 0x007 rjmp TIM2_COMPA ; Timer2 Compare A Handler
	.org 0x008 rjmp TIM2_COMPB ; Timer2 Compare B Handler
	.org 0x009 rjmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x00A rjmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x00B rjmp TIM1_COMPA ; Timer1 Compare A Handler
	.org 0x00C rjmp TIM1_COMPB ; Timer1 Compare B Handler
	.org 0x00D rjmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x00E rjmp TIM0_COMPA ; Timer0 Compare A Handler
	.org 0x00F rjmp TIM0_COMPB ; Timer0 Compare B Handler
	.org 0x010 rjmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x011 rjmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x012 rjmp USART0_RXC ; USART, RX Complete Handler
	.org 0x013 rjmp USART0_UDRE ; USART, UDR Empty Handler
	.org 0x014 rjmp USART0_TXC ; USART, TX Complete Handler
	.org 0x015 rjmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org 0x016 rjmp EE_RDY ; EEPROM Ready Handler
	.org 0x017 rjmp ANA_COMP ; Analog Comparator Handler
	.org 0x018 rjmp TWSI ; 2-wire Serial Interface Handler
	.org 0x019 rjmp SPM_RDY ; Store Program Memory Ready Handler

