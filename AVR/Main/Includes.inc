.include "Main/Constants.inc"
.include "Config.inc"
.include "Main/Relative.inc"


.dseg ;������� ������



.eseg ;������� EEPROM



.cseg ;���������� ������
.include "Main/Interrupts/Vectors.inc"

.include "Main/Macros.inc"
.include "Main/Time_Cycles.inc"

; ��������� ������ ����



.include "Interrupts.inc"
	