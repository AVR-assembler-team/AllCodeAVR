.macro ADC_init
	ADCPrescalerSelection 128				; ��������� ������������
	SetRefSel
	SetAdjustResult
	SetChannelSelection
	SetADCModeSelect
	SetADCInterrupt
	SetDigInpDis
.endm