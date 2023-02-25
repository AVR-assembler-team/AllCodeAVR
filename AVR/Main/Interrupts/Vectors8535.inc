
	.org 0x000 rjmp RESET ; Reset Handler
	.org 0x001 rjmp EXT_INT0 ; IRQ0 Handler
	.org 0x002 rjmp EXT_INT1 ; IRQ1 Handler
	.org 0x003 rjmp TIM2_COMP ; Timer2 Compare Handler
	.org 0x004 rjmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x005 rjmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x006 rjmp TIM1_COMPA ; Timer1 Compare A Handler
	.org 0x007 rjmp TIM1_COMPB ; Timer1 Compare B Handler
	.org 0x008 rjmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x009 rjmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x00A rjmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x00B rjmp USART0_RXC ; USART RX Complete Handler
	.org 0x00C rjmp USART0_UDRE ; UDR Empty Handler
	.org 0x00D rjmp USART0_TXC ; USART TX Complete Handler
	.org 0x00E rjmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org 0x00F rjmp EE_RDY ; EEPROM Ready Handler
	.org 0x010 rjmp ANA_COMP ; Analog Comparator Handler
	.org 0x011 rjmp TWSI ; Two-wire Serial Interface Handler
	.org 0x012 rjmp EXT_INT2 ; IRQ2 Handler
	.org 0x013 rjmp TIM0_COMP ; Timer0 Compare Handler
	.org 0x014 rjmp SPM_RDY ; Store Program Memory Ready Handler
