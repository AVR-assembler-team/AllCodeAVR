.if ctrl == 8
    .include "Main/Interrupts/Vectors8.inc"
.elif ctrl == 16
    .include "Main/Interrupts/Vectors16.inc"
.elif ctrl == 32
    .include "Main/Interrupts/Vectors32.inc"
.elif ctrl == 48 || ctrl == 88 || ctrl == 168
    .include "Main/Interrupts/Vectors48_88_168.inc"
.elif ctrl == 64
    .include "Main/Interrupts/Vectors64.inc"
.elif ctrl == 128
    .include "Main/Interrupts/Vectors128.inc"
.elif ctrl == 162
    .include "Main/Interrupts/Vectors162.inc"
.elif ctrl == 164 || ctrl == 324 || ctrl == 644
    .include "Main/Interrupts/Vectors164_324_644.inc"
.elif ctrl == 165
    .include "Main/Interrupts/Vectors165.inc"
.elif ctrl == 169
    .include "Main/Interrupts/Vectors169.inc"
.elif ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450
    .include "Main/Interrupts/Vectors325_3250_645_6450.inc"
.elif ctrl == 328
    .include "Main/Interrupts/Vectors328.inc"
.elif ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
    .include "Main/Interrupts/Vectors329_3290_649_6490.inc"
.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
    .include "Main/Interrupts/Vectors640_1280_1281_2560_2561.inc"
.elif ctrl == 1284
    .include "Main/Interrupts/Vectors1284.inc"
.elif ctrl == 8515
    .include "Main/Interrupts/Vectors8515.inc"
.elif ctrl == 8535
    .include "Main/Interrupts/Vectors8535.inc"
.endif
