/*
* Отправка данных дисплею
* Принимает один аргуммент - регистр с данными для отправки
*/
.macro HD44780U_Send_data

	push r16						; вталкиваем r16 в STACK

	mov r16, @0						; копируем @0 в r16
	_call HD44780U_Send_data_act	; переходим

	pop r16							; выталкиваем r16 из STACK

.endm
;-------------------------------------
.macro HD44780U_Send_data_byte_high
	_call HD44780U_Send_data_byte_high_act
.endm
;-------------------------------------
.macro HD44780U_Send_data_byte_low
	_call HD44780U_Send_data_byte_low_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires
	HD44780U_Send_data_act:
		sbi HD44780U_RS_PORT, HD44780U_RS_bit	; устанавливаем на команду
		HD44780U_Command
		HD44780U_Delay_20mks					; задержка 20 мкс
		HD44780U_Delay_20mks					; задержка 20 мкс
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_Send_data_act:
		sbi HD44780U_RS_PORT, HD44780U_RS_bit	; устанавливаем на команду
		HD44780U_Command1
		HD44780U_Delay_5mks						; задержка 5 мкс

		HD44780U_Command2
		cbi HD44780U_D7_PORT, HD44780U_D7_bit	; очищаем бит D7
		HD44780U_Delay_20mks
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_Send_data_act:
		HD44780U_Send_data_byte_high	; переходим по метке
		HD44780U_Send_data_byte_low		; переходим по метке
	ret									; выход из подпрограммы
	;----------------------------------------------------------------
	HD44780U_Send_data_byte_high_act:
		push	r16						; записываем в стек
		andi	r16, $f0				; обнуляем первые 4 бита
		push	r16						; записываем в стек
		HD44780U_led_check $05, $0d
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r16						; извлекаем из стека
		HD44780U_led_check $01, $09
		HD44780U_Delay_5mks				; задержка
		HD44780U_Delay_5mks				; задержка
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r16						; извлекаем из стека
	ret									; выход из подпрограммы
	;----------------------------------------------------------------
	HD44780U_Send_data_byte_low_act:
		swap	r16						; меняем тетрады местами
		andi	r16, $f0				; обнуляем первые 4 бита
		push	r16						; помещаем в стек
		HD44780U_led_check $05, $0d
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
		pop		r16						; извлекаем из стека r16
		HD44780U_led_check $01, $09
		HD44780U_Delay_5mks				; задержка
		HD44780U_Delay_5mks				; задержка
		WRITE_REG TWDR, r16								; Вталкиваем в дата регистр
		TWSI_Byte_Transmit								; Отправляем TWDR по шине
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ	
	ret									; выход из подпрограммы	
#endif
