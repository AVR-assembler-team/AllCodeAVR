
    .org 0x000 jmp RESET ; Reset Handler
	.org 0x002 jmp EXT_INT0 ; IRQ0 Handler
	.org 0x004 jmp EXT_INT1 ; IRQ1 Handler
	.org 0x006 jmp EXT_INT2 ; IRQ2 Handler
	.org 0x008 jmp EXT_PCINT0 ; PCINT0 Handler
	.org 0x00A jmp EXT_PCINT1 ; PCINT1 Handler
	.org 0x00C jmp TIM3_CAPT ; Timer3 Capture Handler
	.org 0x00E jmp TIM3_COMPA ; Timer3 CompareA Handler
	.org 0x010 jmp TIM3_COMPB ; Timer3 CompareB Handler
	.org 0x012 jmp TIM3_OVF ; Timer3 Overflow Handler
	.org 0x014 jmp TIM2_COMP ; Timer2 Compare Handler
	.org 0x016 jmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x018 jmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x01A jmp TIM1_COMPA ; Timer1 CompareA Handler
	.org 0x01C jmp TIM1_COMPB ; Timer1 CompareB Handler
	.org 0x01E jmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x020 jmp TIM0_COMP ; Timer0 Compare Handler
	.org 0x022 jmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x024 jmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x026 jmp USART0_RXC ; USART0 RX Complete Handler
	.org 0x028 jmp USART1_RXC ; USART1 RX Complete Handler
	.org 0x02A jmp USART0_UDRE ; UDR0 Empty Handler
	.org 0x02C jmp USART1_UDRE ; UDR1 Empty Handler
	.org 0x02E jmp USART0_TXC ; USART0 TX Complete Handler
	.org 0x030 jmp USART1_TXC ; USART1 TX Complete Handler
    .org 0x032 jmp EE_RDY ; EEPROM Ready Handler
    .org 0x034 jmp ANA_COMP ; Analog Comparator Handler
	.org 0x036 jmp SPM_RDY ; Store Program Memory Ready Handler

