/*
* Данный макрос проверяет флаг занятости дисплея
*/

HD44780U_BF_Check:

	CLRB HD44780U_D7_DDR, HD44780U_D7_bit

	cbi HD44780U_RS_PORT, HD44780U_RS_bit	; уставливаем на инструкции
	sbi HD44780U_RW_PORT, HD44780U_RW_bit	; опрокидываем RW на + (чтение)

HD44780U_Read_bit:
	sbi	HD44780U_E_PORT, HD44780U_E_bit		; начинаем чтение
	HD44780U_Delay_5mks						; задержка 5 мкс
	sbis HD44780U_D7_PIN, HD44780U_D7_bit	; проверяем состояние бита для D7
		_jump HD44780U_Busy_Flag_End		; если флага нет, то переходим

HD44780U_Busy_Flag_Again:
	cbi	HD44780U_E_PORT, HD44780U_E_bit		; заканчиваем чтение
	HD44780U_Delay_5mks						; задержка 5 мкс
	_jump HD44780U_Read_bit					; если поднять бит для D7 то возвращаемся к чтению

HD44780U_Busy_Flag_End:
	cbi	HD44780U_E_PORT, HD44780U_E_bit		; заканчиваем чтение
	cbi HD44780U_RW_PORT, HD44780U_RW_bit	; опрокидываем RW на землю (запись)

	SETB HD44780U_D7_DDR, HD44780U_D7_bit

	HD44780U_Delay_4_1ms					; задержка 4,1 мс

ret
