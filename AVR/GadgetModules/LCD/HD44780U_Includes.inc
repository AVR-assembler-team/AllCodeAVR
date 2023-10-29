
.include "GadgetModules/LCD/HD44780U_Constants.inc"
.include "GadgetModules/LCD/HD44780U_SetMacs.inc"
.include "Configs/HD44780U_Config.inc"

.include "GadgetModules/LCD/HD44780U_Times.inc"


#ifdef HD44780U_8_Wires
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_BFCheck.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_SendData.inc"
	.include "GadgetModules/LCD/HD44780U_8_Wires/HD44780U_Command.inc"
#elif defined HD44780U_4_Wires
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_BFCheck.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_SendData.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_Command1.inc"
	.include "GadgetModules/LCD/HD44780U_4_Wires/HD44780U_Command2.inc"
#elif defined HD44780U_TWSI
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_Initialization.inc"
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_SendInstruction.inc"
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_BFCheck.inc"
	.include "GadgetModules/LCD/HD44780U_TWSI/HD44780U_SendData.inc"
#endif

.include "GadgetModules/LCD/HD44780U_Init.inc"

.include "GadgetModules/LCD/Commands/HD44780U_LCD_Led.inc"
.include "GadgetModules/LCD/Commands/HD44780U_SetCursor.inc"
.include "GadgetModules/LCD/Commands/HD44780U_WriteSymbol.inc"
.include "GadgetModules/LCD/Commands/HD44780U_WriteRegister.inc"
.include "GadgetModules/LCD/Commands/HD44780U_LcdClear.inc"
.include "GadgetModules/LCD/Commands/HD44780U_Writestring.inc"

.include "GadgetModules/LCD/HD44780U_DDRAMincrement.inc"
