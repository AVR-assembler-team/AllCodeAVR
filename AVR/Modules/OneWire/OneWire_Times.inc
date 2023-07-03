.macro OneWire_DelayA
	_call OneWire_DelayA_act
.endm
;----------------------------
.macro OneWire_DelayB
	_call OneWire_DelayB_act
.endm
;----------------------------
.macro OneWire_DelayC
	_call OneWire_DelayC_act
.endm
;----------------------------
.macro OneWire_DelayD
	_call OneWire_DelayD_act
.endm
;----------------------------
.macro OneWire_DelayE
	_call OneWire_DelayE_act
.endm
;----------------------------
.macro OneWire_DelayF
	_call OneWire_DelayF_act
.endm
;----------------------------
.macro OneWire_DelayH
	_call OneWire_DelayH_act
.endm
;----------------------------
.macro OneWire_DelayI
	_call OneWire_DelayI_act
.endm
;----------------------------
.macro OneWire_DelayJ
	_call OneWire_DelayJ_act
.endm
;----------------------------
.macro OneWire_Delay_10ms
	_call OneWire_Delay_10ms_act
.endm
;----------------------------
.macro OneWire_Delay_750ms
	_call OneWire_Delay_750ms_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWire_DelayA_act:
	ldi		xh, HIGH(ATmegaFREQ/760000)
	ldi		xl, LOW(ATmegaFREQ/760000)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayB_act:
	ldi		xh, HIGH(ATmegaFREQ/63000)
	ldi		xl, LOW(ATmegaFREQ/63000)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayC_act:
	ldi		xh, HIGH(ATmegaFREQ/67500)
	ldi		xl, LOW(ATmegaFREQ/67500)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayD_act:
	ldi		xh, HIGH(ATmegaFREQ/425000)
	ldi		xl, LOW(ATmegaFREQ/425000)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayE_act:
	ldi		xh, HIGH(ATmegaFREQ/480000)
	ldi		xl, LOW(ATmegaFREQ/480000)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayF_act:
	ldi		xh, HIGH(ATmegaFREQ/73500)
	ldi		xl, LOW(ATmegaFREQ/73500)
	rcall Time_Cycles
ret
;----------------------------
OneWire_DelayH_act:
	ldi		xh, HIGH(ATmegaFREQ/8345)
	ldi		xl, LOW(ATmegaFREQ/8345)
	rcall	Time_Cycles
ret
;----------------------------
OneWire_DelayI_act:
	ldi		xh, HIGH(ATmegaFREQ/57575)
	ldi		xl, LOW(ATmegaFREQ/57575)
	rcall	Time_Cycles
ret
;----------------------------
OneWire_DelayJ_act:
	ldi		xh, HIGH(ATmegaFREQ/9770)
	ldi		xl, LOW(ATmegaFREQ/9770)
	rcall	Time_Cycles
ret
;----------------------------
OneWire_Delay_10ms_act:
	ldi		xh, HIGH(ATmegaFREQ/400)
	ldi		xl, LOW(ATmegaFREQ/400)
	rcall	Time_Cycles
ret
;----------------------------
OneWire_Delay_750ms_act:
	push r16
	ldi r16, $4b
	Cont_750ms:
		OneWire_Delay_10ms
	dec r16
	brne Cont_750ms
	pop r16
ret
