/*
* »нициализаци€ работы модул€ I2C
* »спользует регистр r25
*/
.macro TWSI_init

	push r25

	ldi	r25, ((ATmegaFREQ/FreqSCL)-16)/8	;задаем частоту передачи по I2C, в формуле учитываетс€ –егистр TWPS == 0
	WRITE_REG TWBR, r25						;записываем данные в регистр дл€ I2C

	pop r25

.endm

