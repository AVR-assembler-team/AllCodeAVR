/*
* Отправка инструкций дисплею
* Принимает один аргумент - регистр с инструкцией для отправки дисплею
*/
.macro HD44780U_Send_instruction
	
	push r16							; вталкиваем r16 в STACK
	
	mov r16, @0							; копируем @0 в R16
	_call HD44780U_Send_instruction_act	; переходим

	pop r16								; выталкиваем r16 из STACK

.endm
;-------------------------------------
.macro HD44780U_Command
	_call HD44780U_Command_act
.endm
;-------------------------------------
.macro HD44780U_Command1
	_call HD44780U_Command1_act
.endm
;-------------------------------------
.macro HD44780U_Command2
	_call HD44780U_Command2_act
.endm
;-------------------------------------
.macro HD44780U_Send_instr_byte_high
	_call HD44780U_Send_instr_byte_high_act
.endm
;-------------------------------------
.macro HD44780U_Send_instr_byte_low
	_call HD44780U_Send_instr_byte_low_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires
	HD44780U_Send_instruction_act:
		cbi HD44780U_RS_PORT, HD44780U_RS_bit						; устанавливаем на инструкции
		HD44780U_Command
		HD44780U_BF_Check											; проверяем состояние флага занятости
	ret																; выход из подпрограммы
	;-------------------------------------
	HD44780U_Command_act:
		cbi HD44780U_RW_PORT, HD44780U_RW_bit						; опрокидываем RW на землю (запись)

		// Устанавливаем биты
		Bits_set_or_clear r16, 7, HD44780U_D7_PORT, HD44780U_D7_bit	  
		Bits_set_or_clear r16, 6, HD44780U_D6_PORT, HD44780U_D6_bit	  
		Bits_set_or_clear r16, 5, HD44780U_D5_PORT, HD44780U_D5_bit	  
		Bits_set_or_clear r16, 4, HD44780U_D4_PORT, HD44780U_D4_bit	  
		Bits_set_or_clear r16, 3, HD44780U_D3_PORT, HD44780U_D3_bit	  
		Bits_set_or_clear r16, 2, HD44780U_D2_PORT, HD44780U_D2_bit	  
		Bits_set_or_clear r16, 1, HD44780U_D1_PORT, HD44780U_D1_bit	  
		Bits_set_or_clear r16, 0, HD44780U_D0_PORT, HD44780U_D0_bit	  

		sbi	HD44780U_E_PORT, HD44780U_E_bit							; начинаем запись
		HD44780U_Delay_5mks											; задержка 5 мкс
		cbi	HD44780U_E_PORT, HD44780U_E_bit							; заканчиваем запись
	ret																; выход из подпрограммы
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_Send_instruction_act:
		cbi HD44780U_RS_PORT, HD44780U_RS_bit						; устанавливаем на инструкции
		HD44780U_Command1
		HD44780U_Delay_5mks											; задержка 5 мкс

		HD44780U_Command2
		HD44780U_Delay_20mks										; задержка 20 мкс
		HD44780U_Delay_20mks										; задержка 20 мкс
	ret																; выход из подпрограммы
	;-------------------------------------
	HD44780U_Command1_act:
		cbi HD44780U_RW_PORT, HD44780U_RW_bit						; опрокидываем RW на землю (запись)
		
		// Устанавливаем биты
		Bits_set_or_clear r16, 7, HD44780U_D7_PORT, HD44780U_D7_bit
		Bits_set_or_clear r16, 6, HD44780U_D6_PORT, HD44780U_D6_bit
		Bits_set_or_clear r16, 5, HD44780U_D5_PORT, HD44780U_D5_bit
		Bits_set_or_clear r16, 4, HD44780U_D4_PORT, HD44780U_D4_bit

		sbi	HD44780U_E_PORT, HD44780U_E_bit							; начинаем запись
		HD44780U_Delay_5mks											; задержка 5 мкс
		cbi	HD44780U_E_PORT, HD44780U_E_bit							; заканчиваем запись
	ret																; выход из подпрограммы
	;-------------------------------------
	HD44780U_Command2_act:
	
		// Устанавливаем биты
		Bits_set_or_clear r16, 3, HD44780U_D7_PORT, HD44780U_D7_bit
		Bits_set_or_clear r16, 2, HD44780U_D6_PORT, HD44780U_D6_bit
		Bits_set_or_clear r16, 1, HD44780U_D5_PORT, HD44780U_D5_bit
		Bits_set_or_clear r16, 0, HD44780U_D4_PORT, HD44780U_D4_bit
	
		sbi	HD44780U_E_PORT, HD44780U_E_bit		; начинаем запись
		HD44780U_Delay_5mks						; задержка 5 мкс
		cbi	HD44780U_E_PORT, HD44780U_E_bit		; заканчиваем запись
	ret											; выход из подпрограммы
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_Send_instruction_act:
		HD44780U_Send_instr_byte_high			; переходим по метке
		HD44780U_Send_instr_byte_low			; переходим по метке
	ret											; выход из подпрограммы
	;----------------------------------------------------------------
	HD44780U_Send_instr_byte_high_act:			; метка
		push	r16								; записываем в стек
		andi	r16, $f0						; обнуляем первые 4 бита
		push	r16								; записываем в стек
		HD44780U_led_check $04, $0c

		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		pop		r16								; извлекаем из стека

		HD44780U_led_check $00, $08
		HD44780U_Delay_5mks						; задержка

		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ
			
		pop		r16								; извлекаем из стека
	ret											; выход из подпрограммы
	;--------------------------------------------------------------
	HD44780U_Send_instr_byte_low_act:
		swap	r16								; меняем тетрады местами
		andi	r16, 0xF0						; обнуляем первые 4 бита
		push	r16								; записываем в стек
		HD44780U_led_check $04, $0c

		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	

		pop		r16								; извлекаем из стека

		HD44780U_led_check $00, $08
		HD44780U_Delay_5mks						; задержка

		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
	ret											; выход из подпрограммы
#endif

