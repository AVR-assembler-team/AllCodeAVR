
	.org 0x0000 jmp RESET ; Reset 
	.org 0x0002 jmp EXT_INT0 ; IRQ0 
	.org 0x0004 jmp EXT_INT1 ; IRQ1 
	.org 0x0006 jmp EXT_INT2 ; IRQ2 
	.org 0x0008 jmp EXT_PCINT0 ; PCINT0 
	.org 0x000A jmp EXT_PCINT1 ; PCINT1 
	.org 0x000C jmp EXT_PCINT2 ; PCINT2 
	.org 0x000E jmp EXT_PCINT3 ; PCINT3 
	.org 0x0010 jmp WDT ; Watchdog Timeout 
	.org 0x0012 jmp TIM2_COMPA ; Timer2 CompareA 
	.org 0x0014 jmp TIM2_COMPB ; Timer2 CompareB 
	.org 0x0016 jmp TIM2_OVF ; Timer2 Overflow
	.org 0x0018 jmp TIM1_CAPT ; Timer1 Capture 
	.org 0x001A jmp TIM1_COMPA ; Timer1 CompareA 
	.org 0x001C jmp TIM1_COMPB ; Timer1 CompareB 
	.org 0x001E jmp TIM1_OVF ; Timer1 Overflow 
	.org 0x0020 jmp TIM0_COMPA ; Timer0 CompareA 
	.org 0x0022 jmp TIM0_COMPB ; Timer0 CompareB 
	.org 0x0024 jmp TIM0_OVF ; Timer0 Overflow 
	.org 0x0026 jmp SPI_STC ; SPI Transfer Complete 
	.org 0x0028 jmp USART0_RXC ; USART0 RX Complete 
	.org 0x002A jmp USART0_UDRE ; USART0,UDR Empty
	.org 0x002C jmp USART0_TXC ; USART0 TX Complete 
	.org 0x002E jmp ANA_COMP ; Analog Comparator 
	.org 0x0030 jmp ADC_Conv_Comp ; ADC Conversion Complete 
	.org 0x0032 jmp EE_RDY ; EEPROM Ready 
	.org 0x0034 jmp TWSI ; 2-wire Serial 
	.org 0x0036 jmp SPM_RDY ; SPM Ready 
	.org 0x0038 jmp USART1_RXC ; USART1 RX Complete
	.org 0x003A jmp USART1_UDRE ; USART1,UDR Empty 
	.org 0x003C jmp USART1_TXC ; USART1 TX Complete 
	.org 0x003E jmp TIM3_CAPT ; Timer3 Capture 
	.org 0x0040 jmp TIM3_COMPA ; Timer3 CompareA 
	.org 0x0042 jmp TIM3_COMPB ; Timer3 CompareB 
	.org 0x0044 jmp TIM3_OVF ; Timer3 Overflow

