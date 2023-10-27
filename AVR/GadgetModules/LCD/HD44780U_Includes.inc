
.include "GadgetModules/LCD/HD44780U_Constants.inc"
.include "GadgetModules/HD44780U/HD44780U_SetMacs.inc"
.include "Configs/HD44780U_Config.inc"

.include "GadgetModules/HD44780U/HD44780U_Times.inc"
.include "GadgetModules/LCD/HD44780U_Function_set.inc"
.include "GadgetModules/LCD/HD44780U_Display_on_off_control.inc"
.include "GadgetModules/LCD/HD44780U_Entry_mode_set.inc"
.include "GadgetModules/LCD/HD44780U_Cursor_Display_shift.inc"


#ifdef HD44780U_8_Wires
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_BFCheck.inc"
#elif defined HD44780U_4_Wires
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_BFCheck.inc"
#elif defined HD44780U_TWSI
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_BFCheck.inc"
#endif

.include "GadgetModules/LCD/HD44780U_Init.inc"

.include "GadgetModules/LCD/Commands/HD44780U_SetCursor.inc"
