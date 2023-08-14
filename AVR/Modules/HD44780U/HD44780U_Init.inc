/*
* Инициализация дисплея
*/
.macro HD44780U_init
	HD44780U_Function_set
	HD44780U_Display_on_off_control
	HD44780U_Entry_mode_set
	HD44780U_Cursor_Display_shift
	.equ TWSI_Address = HD44780U_SLA_
	_call HD44780U_init_Act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires				; подключение микроконтроллера по 8-ми битам
	HD44780U_init_Act:
		SETB HD44780U_D0_DDR, HD44780U_D0_bit			; устанавливаем все биты рабочего регистра на выход
		SETB HD44780U_D1_DDR, HD44780U_D1_bit					  
		SETB HD44780U_D2_DDR, HD44780U_D2_bit					  
		SETB HD44780U_D3_DDR, HD44780U_D3_bit					  
		SETB HD44780U_D4_DDR, HD44780U_D4_bit					  
		SETB HD44780U_D5_DDR, HD44780U_D5_bit					  
		SETB HD44780U_D6_DDR, HD44780U_D6_bit					  
		SETB HD44780U_D7_DDR, HD44780U_D7_bit					 							
		SETB HD44780U_RS_DDR, HD44780U_RS_bit					  
		SETB HD44780U_RW_DDR, HD44780U_RW_bit					  
		SETB HD44780U_E_DDR, HD44780U_E_bit					  
												  
		HD44780U_Delay_15ms								; ждем более 15 мс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_Delay_4_1ms							; ждем более 4,1 мс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_Delay_100mks							; ждем более 100мкс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_BF_Check								; проверяем состояние флага занятости
												  
		lds r16, HD44780U_Function_Set_byte				; Читаем Function Set в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию

		lds r16, HD44780U_Display_On_Off_Control_byte	; Читаем Display On/Off Control в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
												  
		ldi r16, HD44780U_LCDClear						; настраиваем инструкцию Display clear
		HD44780U_Send_instruction r16					; скармливаем инструкцию

		lds r16, HD44780U_Entry_Mode_Set_byte			; Читаем Entry Mode Set в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию

		lds r16, HD44780U_Cursor_or_display_shift		; Читаем Cursor or display shift в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_init_Act:
		SETB HD44780U_D4_DDR, HD44780U_D4_bit			; устанавливаем все биты рабочего регистра на выход
		SETB HD44780U_D5_DDR, HD44780U_D5_bit					  
		SETB HD44780U_D6_DDR, HD44780U_D6_bit					  
		SETB HD44780U_D7_DDR, HD44780U_D7_bit					 							
		SETB HD44780U_RS_DDR, HD44780U_RS_bit					  
		SETB HD44780U_RW_DDR, HD44780U_RW_bit					  
		SETB HD44780U_E_DDR,  HD44780U_E_bit			; управляющие биты на выход
												  
		HD44780U_Delay_15ms								; ждем более 15 мс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_Delay_4_1ms							; ждем более 4,1 мс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_Delay_100mks							; ждем более 100мкс
		ldi	r16, $30									; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_BF_Check								; проверяем состояние флага занятости
												  
		ldi	r16, HD44780U_LCD_Function_Set				; устанавливаем инструкцию
		HD44780U_instr									; скармливаем инструкцию
		HD44780U_BF_Check								; проверяем состояние флага занятости
																	  
		lds r16, HD44780U_Function_Set_byte				; Читаем Function Set в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
		
		lds r16, HD44780U_Display_On_Off_Control_byte	; Читаем Display On/Off Control в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
																	  
		ldi r16, HD44780U_LCDClear						; настраиваем инструкцию Display clear
		HD44780U_Send_instruction r16					; скармливаем инструкцию
																	  
		lds r16, HD44780U_Entry_Mode_Set_byte			; Читаем Entry Mode Set в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
		HD44780U_Delay_15ms								; ждем более 15 мс

		lds r16, HD44780U_Cursor_or_display_shift		; Читаем Cursor or display shift в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_init_Act:

		HD44780U_Delay_15ms											; ждем 15-40 ms
		TWSI_START										; отсылаем START (рестартуем для записи)
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'W'

		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; формируем первую инструкцию инициализации	
		HD44780U_Send_instr_byte_high		 						; передаем старшую тетраду байта инструкции

		HD44780U_Delay_4_1ms										; ждем больше 4,1 ms

		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; формируем вторую инструкцию инициализации
		HD44780U_Send_instr_byte_high								; передаем старшую тетраду байта инструкции

		HD44780U_Delay_100mks										; ждем больше 100 mks
		
		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; формируем третью инструкцию инициализации
		HD44780U_Send_instr_byte_high								; передаем старшую тетраду байта инструкции
		
		ldi	r16, (1<<HD44780U_LCD_D5)								; формируем четвертую инструкцию инициализации
		HD44780U_Send_instr_byte_high								; передаем старшую тетраду байта инструкции

		HD44780U_BF_Check											; проверка занятости LCD

		lds r16, HD44780U_Function_Set_byte				; Читаем Function Set в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию
		HD44780U_BF_Check								; проверка занятости LCD

		lds r16, HD44780U_Display_On_Off_Control_byte	; Читаем Display On/Off Control в r16
		
		HD44780U_Delay_100mks							; ждем больше 100 mks
		HD44780U_Send_instruction r16					; отсылаем байт инструкции
		HD44780U_BF_Check								; проверка занятости LCD

		ldi	r16, HD44780U_LCDClear						; LCD_Clear
		HD44780U_Delay_100mks							; ждем больше 100 mks
		HD44780U_Send_instruction r16					; отсылаем байт инструкции
		HD44780U_BF_Check								; проверка занятости LCD

		lds r16, HD44780U_Entry_Mode_Set_byte			; Читаем Entry Mode Set в r16
		
		HD44780U_Delay_100mks							; ждем больше 100 mks
		HD44780U_Send_instruction r16					; отсылаем байт инструкции

		lds r16, HD44780U_Cursor_or_display_shift		; Читаем Cursor or display shift в r16
		HD44780U_Send_instruction r16					; скармливаем инструкцию

		TWSI_STOP										; отсылаем команду STOP
	ret													; выход из подпрограммы
#endif

