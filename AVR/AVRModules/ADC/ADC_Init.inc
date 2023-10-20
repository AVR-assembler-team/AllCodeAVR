.macro ADC_init
	ADCPrescalerSelection 128							; настройка претделителя
	ADCReferenceSelection AREFpin						; настройка Reference Selection
	ADCLeftAdjustResult Left							; настройка ADC Left Adjust Result
	ADCInputChannelSelection SingleEndedInput, ADC0		; настройка Input Channel Selections
	SetADCModeSelect
	SetADCInterrupt
.endm
