/*
* В данном файле все временные задержки которые использует данная библиотека
*/
.macro HD44780U_Delay_5mks
	_call HD44780U_Delay_5mks_act
.endm
;----------------------------
.macro HD44780U_Delay_20mks
	_call HD44780U_Delay_20mks_act
.endm
;----------------------------
.macro HD44780U_Delay_100mks
	_call HD44780U_Delay_100mks_act
.endm
;----------------------------
.macro HD44780U_Delay_4_1ms
	_call HD44780U_Delay_4_1ms_act
.endm
;----------------------------
.macro HD44780U_Delay_15ms
	_call HD44780U_Delay_15ms_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_Delay_5mks_act:
	ldi		xh, HIGH(ATmegaFREQ/700000)
	ldi		xl, LOW(ATmegaFREQ/700000)
	_call Time_Cycles
ret
;----------------------------
HD44780U_Delay_20mks_act:
	ldi		xh, HIGH(ATmegaFREQ/175000)
	ldi		xl, LOW(ATmegaFREQ/175000)
	_call Time_Cycles
ret
;----------------------------
HD44780U_Delay_100mks_act:
	ldi		xh, HIGH(ATmegaFREQ/35000)
	ldi		xl, LOW(ATmegaFREQ/35000)
	_call Time_Cycles
ret
;----------------------------
HD44780U_Delay_4_1ms_act:
	ldi		xh, HIGH(ATmegaFREQ/1600)
	ldi		xl, LOW(ATmegaFREQ/1600)
	_call Time_Cycles
	ldi		xh, HIGH(ATmegaFREQ/1600)
	ldi		xl, LOW(ATmegaFREQ/1600)
	_call Time_Cycles
ret
;----------------------------
HD44780U_Delay_15ms_act:
	ldi		xh, HIGH(ATmegaFREQ/400)
	ldi		xl, LOW(ATmegaFREQ/400)
	_call Time_Cycles
	ldi		xh, HIGH(ATmegaFREQ/400)
	ldi		xl, LOW(ATmegaFREQ/400)
	_call Time_Cycles
ret
