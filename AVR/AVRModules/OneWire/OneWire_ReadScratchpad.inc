/*
* ������ scratch pad, ��������� CRC �, ���� �������� ������ �������, 
* ��������� ��������� � ������ �� ����� OneWireScratchpad
* ���� �������� ���������, �� �� ������ ����� ����� 00
*/
.macro OneWire_ReadScratchpad
	OneWireSendCommand OneWireReadScreatchpadCommand
	OneWireReadBytes OneWireScratchpad, 9
.endm