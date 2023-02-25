.if ctlr == 8
    .include "Main/Interrupts/Vectors8.inc"
.elif ctlr == 16
    .include "Main/Interrupts/Vectors16.inc"
.elif ctlr == 32
    .include "Main/Interrupts/Vectors32.inc"
.elif ctlr == 48 || ctlr == 88 || ctlr == 168
    .include "Main/Interrupts/Vectors48_88_168.inc"
.elif ctlr == 64
    .include "Main/Interrupts/Vectors64.inc"
.elif ctlr == 128
    .include "Main/Interrupts/Vectors128.inc"
.elif ctlr == 162
    .include "Main/Interrupts/Vectors162.inc"
.elif ctlr == 164 || ctlr == 324 || ctlr == 644
    .include "Main/Interrupts/Vectors164_324_644.inc"
.elif ctlr == 165
    .include "Main/Interrupts/Vectors165.inc"
.elif ctlr == 169
    .include "Main/Interrupts/Vectors169.inc"
.elif ctlr == 325 || ctlr == 3250 || ctlr == 645 || ctlr == 6450
    .include "Main/Interrupts/Vectors325_3250_645_6450.inc"
.elif ctlr == 328
    .include "Main/Interrupts/Vectors328.inc"
.elif ctlr == 329 || ctlr == 3290 || ctlr == 649 || ctlr == 6490
    .include "Main/Interrupts/Vectors329_3290_649_6490.inc"
.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
    .include "Main/Interrupts/Vectors640_1280_1281_2560_2561.inc"
.elif ctlr == 1284
    .include "Main/Interrupts/Vectors1284.inc"
.elif ctlr == 8515
    .include "Main/Interrupts/Vectors8515.inc"
.elif ctlr == 8535
    .include "Main/Interrupts/Vectors8535.inc"
.endif
