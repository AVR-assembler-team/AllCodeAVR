
	.org $000 jmp RESET ; Reset Handler
	.org $002 jmp EXT_INT0 ; IRQ0 Handler
	.org $004 jmp EXT_INT1 ; IRQ1 Handler
	.org $006 jmp TIM2_COMP ; Timer2 Compare Handler
	.org $008 jmp TIM2_OVF ; Timer2 Overflow Handler
	.org $00A jmp TIM1_CAPT ; Timer1 Capture Handler
	.org $00C jmp TIM1_COMPA ; Timer1 CompareA Handler
	.org $00E jmp TIM1_COMPB ; Timer1 CompareB Handler
	.org $010 jmp TIM1_OVF ; Timer1 Overflow Handler
	.org $012 jmp TIM0_OVF ; Timer0 Overflow Handler
	.org $014 jmp SPI_STC ; SPI Transfer Complete Handler
	.org $016 jmp USART0_RXC ; USART RX Complete Handler
	.org $018 jmp USART0_UDRE ; UDR Empty Handler
	.org $01A jmp USART0_TXC ; USART TX Complete Handler
	.org $01C jmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org $01E jmp EE_RDY ; EEPROM Ready Handler
	.org $020 jmp ANA_COMP ; Analog Comparator Handler
	.org $022 jmp TWSI ; Two-wire Serial Interface Handler
	.org $024 jmp EXT_INT2 ; IRQ2 Handler
	.org $026 jmp TIM0_COMP ; Timer0 Compare Handler
	.org $028 jmp SPM_RDY ; Store Program Memory Ready Handler

