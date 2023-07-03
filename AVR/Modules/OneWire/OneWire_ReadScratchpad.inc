/*
* Читает scratch pad, проверяет CRC и, если проверка прошла успешна, 
* записывае результат в память по метке OneWireScratchpad
* если проверка провалена, то по данной метке будут 00
*/
.macro OneWire_ReadScratchpad
	OneWireSendCommand OneWireReadScreatchpadCommand
	OneWireReadBytes OneWireScratchpad, 9
.endm
