/*
* �������� ������� ������ ����������� �����������
* � ���� ��������� �������� �����������
*/

.macro OneWire_ConvertTemperature
	OneWireSendCommand OneWireConvertTemperatureCommand
	OneWire_DeviceBusy OneWireConvertTemperatureCommand
.endm
