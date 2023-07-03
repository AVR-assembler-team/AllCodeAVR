.include "Main/Constants.inc"
.include "Config.inc"
.include "Main/Relative.inc"


.dseg ;сегмент данных



.eseg ;сегмент EEPROM



.cseg ;програмный сегмен
.include "Main/Interrupts/Vectors.inc"

.include "Main/Macros.inc"
.include "Main/Time_Cycles.inc"


; добавляем модули сюда
.include "Main/Modules.inc"
//.include "Modules/TWSI/TWSI_Includes.inc"

//.include "Modules/USART/USART_Includes.inc"


.include "Interrupts.inc"
.include "Main/Modules_Inits.inc"
	
