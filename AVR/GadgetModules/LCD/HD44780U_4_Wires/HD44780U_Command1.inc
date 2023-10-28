/*
* Отправка инструкций дисплею
* Использует регистр r25
*/
HD44780U_Command1:
	cbi HD44780U_RW_PORT, HD44780U_RW_bit						; опрокидываем RW на землю (запись)
		
	// Устанавливаем биты
	sbrs r25, 7
		cbi HD44780U_D7_PORT, HD44780U_D7_bit
	sbrc r25, 7
		sbi HD44780U_D7_PORT, HD44780U_D7_bit
  
	sbrs r25, 6
		cbi HD44780U_D6_PORT, HD44780U_D6_bit
	sbrc r25, 6
		sbi HD44780U_D6_PORT, HD44780U_D6_bit
	
	sbrs r25, 5
		cbi HD44780U_D5_PORT, HD44780U_D5_bit
	sbrc r25, 5
		sbi HD44780U_D5_PORT, HD44780U_D5_bit 
	
	sbrs r25, 4
		cbi HD44780U_D4_PORT, HD44780U_D4_bit
	sbrc r25, 4
		sbi HD44780U_D4_PORT, HD44780U_D4_bit	

	sbi	HD44780U_E_PORT, HD44780U_E_bit							; начинаем запись
	HD44780U_Delay_5mks											; задержка 5 мкс
	cbi	HD44780U_E_PORT, HD44780U_E_bit							; заканчиваем запись
ret																; выход из подпрограммы
