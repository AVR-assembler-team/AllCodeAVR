/*
* Копирует TH, TL и config байты в EEPROM
* и дожидается окончания копирования
*/
.macro OneWire_CopyScratchpad
	OneWireSendCommand OneWireCopyScratchpadCommand
	OneWire_DeviceBusy OneWireCopyScratchpadCommand
.endm
