
	.include "AVRModules/Counters/CountersIncludes.inc"


#ifdef TWSI_Module
	.include "AVRModules/TWSI/TWSI_Includes.inc"
#endif

#ifdef USART_Module
	.include "AVRModules/USART/USART_Includes.inc"
#endif

	.include "AVRModules/ADC/ADCIncludes.inc"

#ifdef OneWire_Module
	.include "AVRModules/OneWire/OneWire_Includes.inc"
#endif

#ifdef ExternalInterrupts_Module
	.include "AVRModules/ExternalInterrupts/ExtInt_Includes.inc"
#endif
