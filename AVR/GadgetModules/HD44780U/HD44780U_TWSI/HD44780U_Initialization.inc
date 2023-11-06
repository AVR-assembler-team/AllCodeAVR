
HD44780U_Initialization:

	push r25

	HD44780U_Delay_15ms										; ждем 15-40 ms
	TWSI_START												; отсылаем START (рестартуем для записи)
	TWSI_SLA r24, 'W'

	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; формируем первую инструкцию инициализации	
	_call HD44780U_Send_instr_byte_high		 				; передаем старшую тетраду байта инструкции

	HD44780U_Delay_4_1ms									; ждем больше 4,1 ms

	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; формируем вторую инструкцию инициализации
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции

	HD44780U_Delay_100mks									; ждем больше 100 mks
	
	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; формируем третью инструкцию инициализации
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	
	ldi	r25, (1<<HD44780U_LCD_D5)							; формируем четвертую инструкцию инициализации
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции

	_call HD44780U_BF_Check									; проверка занятости LCD

	READ_REG HD44780U_Function_Set_byte, r25				; Читаем Function Set в r25
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	_call HD44780U_Send_instr_byte_low						; передаем младшую тетраду байта инструкции
	_call HD44780U_BF_Check									; проверка занятости LCD

	READ_REG HD44780U_Display_On_Off_Control_byte, r25		; Читаем Display On/Off Control в r16
		
	HD44780U_Delay_100mks									; ждем больше 100 mks
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	_call HD44780U_Send_instr_byte_low						; передаем младшую тетраду байта инструкции
	_call HD44780U_BF_Check									; проверка занятости LCD

	ldi	r25, HD44780U_LCDClear								; LCD_Clear
	HD44780U_Delay_100mks									; ждем больше 100 mks
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	_call HD44780U_Send_instr_byte_low						; передаем младшую тетраду байта инструкции
	_call HD44780U_BF_Check									; проверка занятости LCD

	READ_REG HD44780U_Entry_Mode_Set_byte, r25				; Читаем Entry Mode Set в r25
	HD44780U_Delay_100mks									; ждем больше 100 mks
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	_call HD44780U_Send_instr_byte_low						; передаем младшую тетраду байта инструкции

	READ_REG HD44780U_Cursor_or_display_shift, r25			; Читаем Cursor or display shift в r16
	_call HD44780U_Send_instr_byte_high						; передаем старшую тетраду байта инструкции
	_call HD44780U_Send_instr_byte_low						; передаем младшую тетраду байта инструкции

	TWSI_STOP												; отсылаем команду STOP

	pop r25

ret															; выход из подпрограммы
