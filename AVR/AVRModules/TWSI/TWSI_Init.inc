/*
* Инициализация работы модуля I2C
*/
.macro TWSI_init
	ldi	r25, ((ATmegaFREQ/FreqSCL)-16)/8	;задаем частоту передачи по I2C, в формуле учитывается Регистр TWPS == 0
	WRITE_REG TWBR, r25						;записываем данные в регистр для I2C
.endm

