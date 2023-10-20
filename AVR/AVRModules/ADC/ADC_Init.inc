.macro ADC_init
	ADCPrescalerSelection 128				; настройка претделителя
	SetRefSel
	SetAdjustResult
	SetChannelSelection
	SetADCModeSelect
	SetADCInterrupt
	SetDigInpDis
.endm
