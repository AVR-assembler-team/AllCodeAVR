.include "Main/Constants.inc"
.include "Configs/FunctionModules_Config.inc"
.include "Configs/AVRModules_Config.inc"
.include "Configs/GadgetModules_Config.inc"
.include "Config.inc"
.include "Main/Relative.inc"


.dseg ;������� ������



.eseg ;������� EEPROM



.cseg ;���������� ������
.include "Main/Interrupts/Vectors.inc"

.include "Main/Macros.inc"
.include "Main/Time_Cycles.inc"


; ��������� ������ ����
.include "Main/FunctionModules.inc"
.include "Main/AVRModules.inc"
.include "Main/GadgetModules.inc"


.include "Interrupts.inc"
.include "Main/Modules_Inits.inc"
	
