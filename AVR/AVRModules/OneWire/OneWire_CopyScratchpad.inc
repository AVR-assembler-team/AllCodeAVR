/*
* �������� TH, TL � config ����� � EEPROM
* � ���������� ��������� �����������
*/
.macro OneWire_CopyScratchpad
	OneWireSendCommand OneWireCopyScratchpadCommand
	OneWire_DeviceBusy OneWireCopyScratchpadCommand
.endm