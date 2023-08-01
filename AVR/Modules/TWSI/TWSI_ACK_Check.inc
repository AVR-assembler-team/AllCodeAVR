/*
* Проверяет состояние регистра TWI модуля I2C
*/
.macro TWSI_ACK_Check
	push r17
	push r18
	ldi r17, @0
	ldi r18, @1
	_call TWSI_ACK_Check_act
	pop r18
	pop r17
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_ACK_Check_act:
	push r16
	TWSI_ACK_Check_act_1:
		READ_REG TWSR, r16					; читаем TWSR
		andi	r16, 0xF8					; обнуляем первые три бита
		cpse	r16, r17					; сравниваем r16 и r17
		rjmp TWSI_Status_act_2				; переходим
		CLRB TWSI_Flags, No_ACK				; обнуляем флаг
		rjmp TWSI_ACK_Check_act_end			; переходим

		TWSI_Status_act_2:
			cpse	r16, r18				; сравниваем r16 и r18
			rjmp	TWSI_ACK_Check_act_1	; если не равны, то переходим
			SETB TWSI_Flags, No_ACK			; устанавливаем флаг
	TWSI_ACK_Check_act_end:
	pop r16
ret
