
.include "GadgetModules/HD44780U/HD44780U_Constants.inc"
.include "GadgetModules/HD44780U/HD44780U_SetMacs.inc"
.include "Configs/HD44780U_Config.inc"

.include "GadgetModules/HD44780U/HD44780U_Times.inc"


#ifdef HD44780U_8_Wires
	.include "GadgetModules/HD44780U/HD44780U_8_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/HD44780U/HD44780U_8_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/HD44780U/HD44780U_8_Wires/HD44780U_BFCheck.inc"
	.include "GadgetModules/HD44780U/HD44780U_8_Wires/HD44780U_SendData.inc"
	.include "GadgetModules/HD44780U/HD44780U_8_Wires/HD44780U_Command.inc"
#elif defined HD44780U_4_Wires
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_Initialization.inc"
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_SendInstruction.inc"
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_BFCheck.inc"
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_SendData.inc"
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_Command1.inc"
	.include "GadgetModules/HD44780U/HD44780U_4_Wires/HD44780U_Command2.inc"
#elif defined HD44780U_TWSI
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_Initialization.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_SendInstruction.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_BFCheck.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_SendData.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_Send_data_byte_high.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_Send_data_byte_low.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_Send_instr_byte_high.inc"
	.include "GadgetModules/HD44780U/HD44780U_TWSI/HD44780U_Send_instr_byte_low.inc"
#endif

.include "GadgetModules/HD44780U/HD44780U_Init.inc"

.include "GadgetModules/HD44780U/Commands/HD44780U_LCD_Led.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_SetCursor.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_WriteSymbol.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_WriteRegister.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_LcdClear.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_Writestring.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_Cursor_Blinking.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_Cursor_visible.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_Shift.inc"
.include "GadgetModules/HD44780U/Commands/HD44780U_DDRAM_Address.inc"

.include "GadgetModules/HD44780U/HD44780U_DDRAMincrement.inc"
