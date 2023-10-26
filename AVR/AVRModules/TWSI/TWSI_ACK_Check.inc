/*
* Проверяет состояние регистра TWI модуля I2C
*/
.macro TWSI_ACK_Check
	ldi r24, @0
	ldi r23, @1
	_call TWSI_ACK_Check_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
TWSI_ACK_Check_act:
	TWSI_ACK_Check_act_1:
		READ_REG TWSR, r25					; читаем TWSR
		andi	r25, 0xF8					; обнуляем первые три бита
		cpse	r25, r24					; сравниваем r16 и r17
		rjmp TWSI_Status_act_2				; переходим

		// обнуляем флаг
		READ_REG TWSI_Flags, r25
		CLRRB r25, No_ACK
		WRITE_REG TWSI_Flags, r25

		rjmp TWSI_ACK_Check_act_end			; переходим

		TWSI_Status_act_2:
			cpse	r25, r23				; сравниваем r16 и r18
			rjmp	TWSI_ACK_Check_act_1	; если не равны, то переходим
			// устанавливаем флаг
			READ_REG TWSI_Flags, r25
			SETRB r25, No_ACK
			WRITE_REG TWSI_Flags, r25
	TWSI_ACK_Check_act_end:
ret
