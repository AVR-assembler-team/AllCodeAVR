/*
* ќтсылает 3 байта девайсу, главный байт configuration
* ѕринимает один аргумент равный 9, 10, 11 или 12 - количество бит дл€ вычислени€ температуры
*/
.macro OneWire_WriteScratchpad
	OneWireSendCommand OneWireWriteScratchpadCommand
	OneWireSendConfByte @0
.endm
