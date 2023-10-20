.macro ADC_init
	ADCPrescalerSelection 128							; настройка претделителя
	ADCReferenceSelection AREFpin						; настройка Reference Selection
	SetAdjustResult
	ADCInputChannelSelection SingleEndedInput, ADC0		; настройка Input Channel Selections
	SetADCModeSelect
	SetADCInterrupt
.endm
