
	.org $000 rjmp RESET ; Reset Handler
	.org $001 rjmp EXT_INT0 ; IRQ0 Handler
	.org $002 rjmp EXT_INT1 ; IRQ1 Handler
	.org $003 rjmp TIM1_CAPT ; Timer1 Capture Handler
	.org $004 rjmp TIM1_COMPA ; Timer1 Compare A Handler
	.org $005 rjmp TIM1_COMPB ; Timer1 Compare B Handler
	.org $006 rjmp TIM1_OVF ; Timer1 Overflow Handler
	.org $007 rjmp TIM0_OVF ; Timer0 Overflow Handler
	.org $008 rjmp SPI_STC ; SPI Transfer Complete Handler
	.org $009 rjmp USART0_RXC ; USART RX Complete Handler
	.org $00a rjmp USART0_UDRE ; UDR0 Empty Handler
	.org $00b rjmp USART0_TXC ; USART TX Complete Handler
	.org $00c rjmp ANA_COMP ; Analog Comparator Handler
	.org $00d rjmp EXT_INT2 ; IRQ2 Handler
	.org $00e rjmp TIM0_COMP ; Timer0 Compare Handler
	.org $00f rjmp EE_RDY ; EEPROM Ready Handler
	.org $010 rjmp SPM_RDY ; Store Program memory Ready Handler
  