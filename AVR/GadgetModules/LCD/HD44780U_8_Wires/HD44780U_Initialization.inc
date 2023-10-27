
HD44780U_Initialization:
	// устанавливаем все биты рабочего регистра на выход
	READ_REG HD44780U_D0_DDR, r25
	SETRB r25, HD44780U_D0_bit
	WRITE_REG HD44780U_D0_DDR, r25

	READ_REG HD44780U_D1_DDR, r25
	SETRB r25, HD44780U_D1_bit
	WRITE_REG HD44780U_D1_DDR, r25
	
	READ_REG HD44780U_D2_DDR, r25
	SETRB r25, HD44780U_D2_bit
	WRITE_REG HD44780U_D2_DDR, r25
	
	READ_REG HD44780U_D3_DDR, r25
	SETRB r25, HD44780U_D3_bit
	WRITE_REG HD44780U_D3_DDR, r25
	
	READ_REG HD44780U_D4_DDR, r25
	SETRB r25, HD44780U_D4_bit
	WRITE_REG HD44780U_D4_DDR, r25
	
	READ_REG HD44780U_D5_DDR, r25
	SETRB r25, HD44780U_D5_bit
	WRITE_REG HD44780U_D5_DDR, r25
	
	READ_REG HD44780U_D6_DDR, r25
	SETRB r25, HD44780U_D6_bit
	WRITE_REG HD44780U_D6_DDR, r25
	
	READ_REG HD44780U_D7_DDR, r25
	SETRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25
	
	READ_REG HD44780U_RS_DDR, r25
	SETRB r25, HD44780U_RS_bit
	WRITE_REG HD44780U_RS_DDR, r25
	
	READ_REG HD44780U_RW_DDR, r25
	SETRB r25, HD44780U_RW_bit
	WRITE_REG HD44780U_RW_DDR, r25
	
	READ_REG HD44780U_E_DDR, r25
	SETRB r25, HD44780U_E_bit
	WRITE_REG HD44780U_E_DDR, r25
	
	
	HD44780U_Delay_15ms								; ждем более 15 мс
	ldi	r25, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; устанавливаем на инструкции
	_call HD44780U_Command							; HD44780U_SendInstruction.inc
	
	HD44780U_Delay_4_1ms							; ждем более 4,1 мс
	ldi	r16, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; устанавливаем на инструкции
	_call HD44780U_Command							; HD44780U_SendInstruction.inc
	
	HD44780U_Delay_100mks							; ждем более 100мкс
	ldi	r16, $30									; устанавливаем инструкцию
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; устанавливаем на инструкции
	_call HD44780U_Command							; HD44780U_SendInstruction.inc

	HD44780U_BF_Check								; проверяем состояние флага занятости
ret
