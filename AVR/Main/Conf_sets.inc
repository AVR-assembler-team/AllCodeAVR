#ifdef TWSI
	.include "TWSI/Files/TWSI_Const.inc"
	.include "Configs/TWSI_config.inc"
#endif
/////////////
#ifdef HD44780U
	.include "HD44780U/Files/HD44780U_Constants.inc"
	.include "HD44780U/Files/HD44780U_SetMacs.inc"
	.include "Configs/HD44780U_config.inc"
#endif
/////////////
#ifdef OneWire
	.include "OneWire/Files/OneWire_Constants.inc"
	.include "OneWire/Files/OneWire_Set_Macs.inc"
	.include "Configs/OneWire_config.inc"
#endif
/////////////
#ifdef ADCMode
	.include "ADC/Files/Constants.inc"
	.include "ADC/Sets/Prescaler.inc"
	.include "ADC/Sets/ReferenceSelection.inc"
	.include "ADC/Sets/LeftAdjustResult.inc"
	.include "ADC/Sets/ADCMode.inc"
	.include "ADC/Sets/ADCInterrupt.inc"
	.include "ADC/Sets/MControllers.inc"
	.include "Configs/ADC_config.inc"
#endif
/////////////
#ifdef USARTMode
	.include "Configs/USART_config.inc"
#endif
////////////
#ifdef ExtInterruptsMode
	.include "Configs/ExtInterrupt_config.inc"
#endif
////////////
#ifdef RotaryEncoder
	.include "RotaryEncoder/Files/Constants.inc"
	.include "RotaryEncoder/Files/SetMacs.inc"
	.include "Configs/RotaryEncoder_config.inc"
#endif



