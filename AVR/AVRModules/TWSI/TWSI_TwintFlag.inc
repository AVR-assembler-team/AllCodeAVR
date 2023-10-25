/*
* ѕровер€ет состо€ние флага TWINT модул€ TWSI
*/
.macro TWSI_TWINT_Flag
	_call TWSI_TWINT_Flag_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_TWINT_Flag_act:
	TWSI_TWINT_Flag_act_1:
		READ_REG TWCR, r25					; записываем TWCR в R16
		sbrs	r25, TWINT						; если бит TWINT подн€т, то пропускаем след строку
		rjmp	TWSI_TWINT_Flag_act_1					; перепрыгиваем на метку
ret
 