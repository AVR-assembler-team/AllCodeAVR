// Analog Comparator Handler
ANA_COMP:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// ADC Conversion Complete Handler
ADC_Conv_Comp:
	cli
	// ��� ���
	//_call ADCINTtt
	sei
reti
////////////////////////////////////////////////////////////
//EEPROM Ready Handler
EE_RDY:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// External Interrupts
EXT_INT0:
	cli
	// ��� ���
	sei
reti
EXT_INT1:
	cli
	// ��� ���
	sei
reti
EXT_INT2:
	cli
	// ��� ���
	sei
reti
EXT_INT3:
	cli
	// ��� ���
	sei
reti
EXT_INT4:
	cli
	// ��� ���
	//PCF8574_Read $70, PCF8574_Data
	sei
reti
EXT_INT5:
	cli
	// ��� ���
	//Disable_INT_Interrupt INT5
	//PCF8575_Read $40, PCF8575_Data, PCF8575_Data + 1
	//PCF8574_Read $70, PCF8574_Data

	//Enable_INT_Interrupt INT5, FallingEdge
	sei
reti
EXT_INT6:
	cli
	// ��� ���
	sei
reti
EXT_INT7:
	cli
	// ��� ���
	sei
reti
EXT_PCINT0:
	cli
	// ��� ���
	sei
reti
EXT_PCINT1:
	cli
	// ��� ���
	sei
reti
EXT_PCINT2:
	cli
	// ��� ���
	sei
ret
EXT_PCINT3:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// LCD_SOF
LCD_SOF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// SPI
SPI_STC:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// SPM_RDY
SPM_RDY:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// Timer 0
TIM0_COMP:
	cli
	// ��� ���
	sei
reti
TIM0_COMPA:
	cli
	// ��� ���
	sei
reti
TIM0_COMPB:
	cli
	// ��� ���
	sei
reti
TIM0_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// Timer 1
TIM1_CAPT:
	cli
	// ��� ���
	sei
reti
TIM1_COMPA:
	cli
	// ��� ���
	sei
reti
TIM1_COMPB:
	cli
	// ��� ���
	sei
reti
TIM1_COMPC:
	cli
	// ��� ���
	sei
reti
TIM1_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// Timer 2
TIM2_COMP:
	cli
	// ��� ���
	sei
reti
TIM2_COMPA:
	cli
	// ��� ���
	sei
reti
TIM2_COMPB:
	cli
	// ��� ���
	sei
reti
TIM2_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
//Timer 3
TIM3_CAPT:
	cli
	// ��� ���
	sei
reti
TIM3_COMPA:
	cli
	// ��� ���
	sei
reti
TIM3_COMPB:
	cli
	// ��� ���
	sei
reti
TIM3_COMPC:
	cli
	// ��� ���
	sei
reti
TIM3_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// Timer 4
TIM4_CAPT:
	cli
	// ��� ���
	sei
reti
TIM4_COMPA:
	cli
	// ��� ���
	sei
reti
TIM4_COMPB:
	cli
	// ��� ���
	sei
reti
TIM4_COMPC:
	cli
	// ��� ���
	sei
reti
TIM4_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// Timer 5
TIM5_CAPT:
	cli
	// ��� ���
	sei
reti
TIM5_COMPA:
	cli
	// ��� ���
	sei
reti
TIM5_COMPB:
	cli
	// ��� ���
	sei
reti
TIM5_COMPC:
	cli
	// ��� ���
	sei
reti
TIM5_OVF:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// TWSI
TWSI:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// USART
USART0_RXC:
	cli
	// ��� ���
	sei
reti
USART0_UDRE:
	cli
	// ��� ���
	sei
reti
USART0_TXC:
	cli
	// ��� ���
	sei
reti
USART1_RXC:
	cli
	// ��� ���
	sei
reti
USART1_UDRE:
	cli
	// ��� ���
	sei
reti
USART1_TXC:
	cli
	// ��� ���
	sei
reti
USART2_RXC:
	cli
	// ��� ���
	sei
reti
USART2_UDRE:
	cli
	// ��� ���
	sei
reti
USART2_TXC:
	cli
	// ��� ���
	sei
reti

USART3_RXC:
	cli
	// ��� ���
	sei
reti
USART3_UDRE:
	cli
	// ��� ���
	sei
reti
USART3_TXC:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
//USI
USI_STRT:
	cli
	// ��� ���
	sei
reti
USI_OVFL:
	cli
	// ��� ���
	sei
reti
////////////////////////////////////////////////////////////
// WDT
WDT:
	cli
	// ��� ���
	sei
reti
