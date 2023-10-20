.macro ADC_init
	ADCPrescalerSelection 128							; настройка претделителя
	SetRefSel
	SetAdjustResult
	ADCInputChannelSelection SingleEndedInput, ADC0		; настройка Input Channel Selections
	SetADCModeSelect
	SetADCInterrupt
	SetDigInpDis
.endm
