
	.org 0x0000 jmp RESET ; Reset 
	.org 0x0002 jmp EXT_INT0 ; IRQ0 Handler
	.org 0x0004 jmp EXT_PCINT0 ; PCINT0 Handler
	.org 0x0006 jmp EXT_PCINT1 ; PCINT0 Handler
	.org 0x0008 jmp TIM2_COMP ; Timer2 Compare Handler
	.org 0x000A jmp TIM2_OVF ; Timer2 Overflow Handler
	.org 0x000C jmp TIM1_CAPT ; Timer1 Capture Handler
	.org 0x000E jmp TIM1_COMPA ; Timer1 CompareA Handler
	.org 0x0010 jmp TIM1_COMPB ; Timer1 CompareB Handler
	.org 0x0012 jmp TIM1_OVF ; Timer1 Overflow Handler
	.org 0x0014 jmp TIM0_COMP ; Timer0 Compare Handler
	.org 0x0016 jmp TIM0_OVF ; Timer0 Overflow Handler
	.org 0x0018 jmp SPI_STC ; SPI Transfer Complete Handler
	.org 0x001A jmp USART0_RXC ; USART RX Complete Handler
	.org 0x001C jmp USART0_UDRE ; USART0,UDR0 Empty Handler
	.org 0x001E jmp USART0_TXC ; USART0 TX Complete Handler
	.org 0x0020 jmp USI_STRT ; USI Start Condition Handler
	.org 0x0022 jmp USI_OVFL ; USI Overflow Handler
    .org 0x0024 jmp ANA_COMP ; Analog Comparator Handler
    .org 0x0026 jmp ADC_Conv_Comp ; ADC Conversion Complete Handler
    .org 0x0028 jmp EE_RDY ; EEPROM Ready Handler
	.org 0x002A jmp SPM_RDY ; SPM Ready Handler

