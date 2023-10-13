/*
* Задержка в 4,1 мс
*/

.macro TWSI_Delay_4_1ms
	_call TWSI_Delay_4_1ms_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_Delay_4_1ms_act:
	ldi		xh, HIGH(ATmegaFREQ/1600)
	ldi		xl, LOW(ATmegaFREQ/1600)
	_call Time_Cycles
	ldi		xh, HIGH(ATmegaFREQ/1600)
	ldi		xl, LOW(ATmegaFREQ/1600)
	_call Time_Cycles
ret

