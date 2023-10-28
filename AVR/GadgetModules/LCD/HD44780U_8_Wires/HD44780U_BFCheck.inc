/*
* Данный макрос проверяет флаг занятости дисплея
* Использует регистр r25
*/

HD44780U_BF_Check:								; проверка состояния флага занятости
		
	READ_REG HD44780U_D7_DDR, r25
	CLRRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25

	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; уставливаем на инструкции
	sbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на + (чтение)

HD44780U_Read_bit:
	sbi	HD44780U_E_PORT, HD44780U_E_bit				; начинаем чтение
	HD44780U_Delay_5mks								; задержка 5 мкс
	sbis HD44780U_D7_PIN, HD44780U_D7_bit			; проверяем состояние бита для D7
		_jump HD44780U_Busy_Flag_End					; если флага нет, то переходим

HD44780U_Busy_Flag_Again:
	cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
	HD44780U_Delay_5mks								; задержка 5 мкс
	_jump HD44780U_Read_bit							; если поднять бит для D7 то возвращаемся к чтению

HD44780U_Busy_Flag_End:
	cbi	HD44780U_E_PORT, HD44780U_E_bit				; заканчиваем чтение
	cbi HD44780U_RW_PORT, HD44780U_RW_bit			; опрокидываем RW на землю (запись)
		
	READ_REG HD44780U_D7_DDR, r25
	SETRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25
	
ret													; выход из подпрограммы
