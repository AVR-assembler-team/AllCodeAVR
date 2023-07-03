/*
* Посылает команду начала конвертации температуры
* и ждет окончания процесса конвертации
*/

.macro OneWire_ConvertTemperature
	OneWireSendCommand OneWireConvertTemperatureCommand
	OneWire_DeviceBusy OneWireConvertTemperatureCommand
.endm
