
.include "Modules/Configs/ExtInt_Config.inc"

.if ctlr == 8
	.include "Modules/ExternalInterrupts/ExtInt_Set_8.inc"
.elif ctlr == 16 || ctlr == 32 || ctlr == 8515 || ctlr == 8535
	.include "Modules/ExternalInterrupts/ExtInt_Set_16_32_8515_8535.inc"
.elif ctlr == 48 || ctlr == 88 || ctlr == 168
	.include "Modules/ExternalInterrupts/ExtInt_Set_48_88_168.inc"
.elif ctlr == 64 || ctlr == 128
	.include "Modules/ExternalInterrupts/ExtInt_Set_64_128.inc"
.elif ctlr == 162
	.include "Modules/ExternalInterrupts/ExtInt_Set_162.inc"
.elif ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
	.include "Modules/ExternalInterrupts/ExtInt_Set_164_324_644_1284.inc"
.elif ctlr == 165 || ctlr == 169
	.include "Modules/ExternalInterrupts/ExtInt_Set_165_169.inc"
.elif ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450
	.include "Modules/ExternalInterrupts/ExtInt_Set_325_3250_645_6450.inc"
.elif ctlr == 328
	.include "Modules/ExternalInterrupts/ExtInt_Set_328.inc"
.elif ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
	.include "Modules/ExternalInterrupts/ExtInt_Set_329_3290_649_6490.inc"
.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
	.include "Modules/ExternalInterrupts/ExtInt_Set_640_1280_1281_2560_2561.inc"
.endif


.include "Modules/ExternalInterrupts/ExtInt_INTenable.inc"
.include "Modules/ExternalInterrupts/ExtInt_INTdisable.inc"
.include "Modules/ExternalInterrupts/ExtInt_Pins.inc"
.include "Modules/ExternalInterrupts/ExtInt_Init.inc"
