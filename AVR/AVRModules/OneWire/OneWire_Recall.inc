/*
* �������� TH, TL � config ��������� �� EEPROM � scratch pad
* � ���������� ��������� ��������
*/
.macro OneWire_Recall
	OneWireSendCommand OneWireRecallCommand
	OneWire_ExternalPowerDeviceBusy
.endm
