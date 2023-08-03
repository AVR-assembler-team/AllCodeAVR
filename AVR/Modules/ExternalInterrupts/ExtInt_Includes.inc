
.include "Modules/Configs/ExtInt_Config.inc"

.if ctrl == 8
	.include "Modules/ExternalInterrupts/ExtInt_Set_8.inc"
.elif ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
	.include "Modules/ExternalInterrupts/ExtInt_Set_16_32_8515_8535.inc"
.elif ctrl == 48 || ctrl == 88 || ctrl == 168
	.include "Modules/ExternalInterrupts/ExtInt_Set_48_88_168.inc"
.elif ctrl == 64 || ctrl == 128
	.include "Modules/ExternalInterrupts/ExtInt_Set_64_128.inc"
.elif ctrl == 162
	.include "Modules/ExternalInterrupts/ExtInt_Set_162.inc"
.elif ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284
	.include "Modules/ExternalInterrupts/ExtInt_Set_164_324_644_1284.inc"
.elif ctrl == 165 || ctrl == 169
	.include "Modules/ExternalInterrupts/ExtInt_Set_165_169.inc"
.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450
	.include "Modules/ExternalInterrupts/ExtInt_Set_325_3250_645_6450.inc"
.elif ctrl == 328
	.include "Modules/ExternalInterrupts/ExtInt_Set_328.inc"
.elif ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
	.include "Modules/ExternalInterrupts/ExtInt_Set_329_3290_649_6490.inc"
.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
	.include "Modules/ExternalInterrupts/ExtInt_Set_640_1280_1281_2560_2561.inc"
.endif


.include "Modules/ExternalInterrupts/ExtInt_INTenable.inc"
.include "Modules/ExternalInterrupts/ExtInt_INTdisable.inc"
.include "Modules/ExternalInterrupts/ExtInt_Pins.inc"
.include "Modules/ExternalInterrupts/ExtInt_Init.inc"
