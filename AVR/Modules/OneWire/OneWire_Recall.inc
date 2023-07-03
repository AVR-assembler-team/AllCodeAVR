/*
* Копирует TH, TL и config регистров из EEPROM в scratch pad
* и дожидается окончания операции
*/
.macro OneWire_Recall
	OneWireSendCommand OneWireRecallCommand
	OneWire_ExternalPowerDeviceBusy
.endm
