/*
* �������� 3 ����� �������, ������� ���� configuration
* ��������� ���� �������� ������ 9, 10, 11 ��� 12 - ���������� ��� ��� ���������� �����������
*/
.macro OneWire_WriteScratchpad
	OneWireSendCommand OneWireWriteScratchpadCommand
	OneWireSendConfByte @0
.endm
