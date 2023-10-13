.include "Main/Constants.inc"
.include "FunctionModules/FunctionModules_Config.inc"
.include "AVRModules/AVRModules_Config.inc"
.include "GadgetModules/GadgetModules_Config.inc"
.include "Config.inc"
.include "Main/Relative.inc"


.dseg ;сегмент данных



.eseg ;сегмент EEPROM



.cseg ;програмный сегмен
.include "Main/Interrupts/Vectors.inc"

.include "Main/Macros.inc"
.include "Main/Time_Cycles.inc"


; добавляем модули сюда
.include "Main/FunctionModules.inc"
.include "Main/AVRModules.inc"
.include "Main/GadgetModules.inc"


.include "Interrupts.inc"
.include "Main/Modules_Inits.inc"
	
