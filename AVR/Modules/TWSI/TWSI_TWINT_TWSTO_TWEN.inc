/*
* Устанавливает биты в TWCR
*/
.macro TWSI_TWIN_TWSTO_TWEN
	_call TWSI_TWIN_TWSTO_TWEN_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_TWIN_TWSTO_TWEN_act:
	push r16
	ldi		r16, (1<<TWINT) | (1<<TWEN) | (1<<TWSTO)		; формируем сигнал для передачи данных с TWDR
	WRITE_REG TWCR, r16						; отправляем по шине
	TWSI_TWINT_Flag
	pop r16
ret											; выход из подпрограммы
