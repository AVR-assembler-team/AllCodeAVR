
	.org $0000 jmp RESET ; Reset Handler
	.org $0002 jmp EXT_INT0 ; IRQ0 Handler
	.org $0004 jmp EXT_INT1 ; IRQ1 Handler
	.org $0006 jmp EXT_INT2 ; IRQ2 Handler
	.org $0008 jmp EXT_INT3 ; IRQ3 Handler
	.org $000A jmp EXT_INT4 ; IRQ4 Handler
	.org $000C jmp EXT_INT5 ; IRQ5 Handler
	.org $000E jmp EXT_INT6 ; IRQ6 Handler
	.org $0010 jmp EXT_INT7 ; IRQ7 Handler
	.org $0012 jmp TIM2_COMP ; Timer2 Compare Handler
	.org $0014 jmp TIM2_OVF ; Timer2 Overflow Handler
	.org $0016 jmp TIM1_CAPT ; Timer1 Capture Handler
	.org $0018 jmp TIM1_COMPA; Timer1 CompareA Handler
	.org $001A jmp TIM1_COMPB; Timer1 CompareB Handler
	.org $001C jmp TIM1_OVF ; Timer1 Overflow Handler
	.org $001E jmp TIM0_COMP ; Timer0 Compare Handler
	.org $0020 jmp TIM0_OVF ; Timer0 Overflow Handler
	.org $0022 jmp SPI_STC ; SPI Transfer Complete Handler
	.org $0024 jmp USART0_RXC; USART0 RX Complete Handler
	.org $0026 jmp USART0_UDRE; USART0,UDR Empty Handler
	.org $0028 jmp USART0_TXC; USART0 TX Complete Handler
	.org $002A jmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org $002C jmp EE_RDY ; EEPROM Ready Handler
	.org $002E jmp ANA_COMP ; Analog Comparator Handler
	.org $0030 jmp TIM1_COMPC; Timer1 CompareC Handler
	.org $0032 jmp TIM3_CAPT ; Timer3 Capture Handler
	.org $0034 jmp TIM3_COMPA; Timer3 CompareA Handler
	.org $0036 jmp TIM3_COMPB; Timer3 CompareB Handler
	.org $0038 jmp TIM3_COMPC; Timer3 CompareC Handler
	.org $003A jmp TIM3_OVF ; Timer3 Overflow Handler
	.org $003C jmp USART1_RXC; USART1 RX Complete Handler
	.org $003E jmp USART1_UDRE; USART1,UDR Empty Handler
	.org $0040 jmp USART1_TXC; USART1 TX Complete Handler
	.org $0042 jmp TWSI ; Two-wire Serial Interface Interrupt Handler
	.org $0044 jmp SPM_RDY ; SPM Ready Handler

