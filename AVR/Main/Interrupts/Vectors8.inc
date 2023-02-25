
	.org $000 rjmp RESET ; Reset Handler
	.org $001 rjmp EXT_INT0 ; IRQ0 Handler
	.org $002 rjmp EXT_INT1 ; IRQ1 Handler
	.org $003 rjmp TIM2_COMP ; Timer2 Compare Handler
	.org $004 rjmp TIM2_OVF ; Timer2 Overflow Handler
	.org $005 rjmp TIM1_CAPT ; Timer1 Capture Handler
	.org $006 rjmp TIM1_COMPA ; Timer1 CompareA Handler
	.org $007 rjmp TIM1_COMPB ; Timer1 CompareB Handler
	.org $008 rjmp TIM1_OVF ; Timer1 Overflow Handler
	.org $009 rjmp TIM0_OVF ; Timer0 Overflow Handler
	.org $00a rjmp SPI_STC ; SPI Transfer Complete Handler
	.org $00b rjmp USART0_RXC ; USART RX Complete Handler
	.org $00c rjmp USART0_UDRE ; UDR Empty Handler
	.org $00d rjmp USART0_TXC ; USART TX Complete Handler
	.org $00e rjmp ADC_Conv_Comp ; ADC Conversion Complete Handler
	.org $00f rjmp EE_RDY ; EEPROM Ready Handler
	.org $010 rjmp ANA_COMP ; Analog Comparator Handler
	.org $011 rjmp TWSI ; Two-wire Serial Interface Handler
	.org $012 rjmp SPM_RDY ; Store Program Memory Ready Handler

