#ifdef TWSI_Module
	.include "Modules/TWSI/TWSI_Includes.inc"
#endif

#ifdef HD44780U_Module
	.include "Modules/HD44780U/HD44780U_Includes.inc"
#endif

#ifdef USART_Module
	.include "Modules/USART/USART_Includes.inc"
#endif

#ifdef ADC_Module
	.include "Modules/ADC/ADC_Includes.inc"
#endif

#ifdef ExternalInterrupts_Module
	.include "Modules/ExternalInterrupts/ExtInt_Includes.inc"
#endif

#ifdef RotaryEncoder_Module
	.include "Modules/RotaryEncoder/RotEnc_Includes.inc"
#endif

#ifdef OneWire_Module
	.include "Modules/OneWire/OneWire_Includes.inc"
#endif