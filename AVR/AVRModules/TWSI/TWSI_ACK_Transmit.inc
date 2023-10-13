/*
* „тение байта из модул€ I2C
* ѕринимает один аргумент - регистр в который производим запись прочитанного TWDR
*/
.macro TWSI_ACK_Transmit
	push r16
	ldi		r16, (1<<TWINT) | (1<<TWEN)	| (1<<TWEA)	; формируем сигнал дл€ передачи данных с TWDR
	WRITE_REG TWCR, r16						; отправл€ем по шине
	TWSI_TWINT_Flag
	pop r16
.endm						; выход из подпрограммы
