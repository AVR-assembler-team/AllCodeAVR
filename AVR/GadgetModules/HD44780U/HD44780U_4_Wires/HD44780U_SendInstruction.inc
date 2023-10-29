/*
* Отправка инструкций дисплею
* Использует регистр r25
*/

HD44780U_Send_instruction:
	cbi HD44780U_RS_PORT, HD44780U_RS_bit						; устанавливаем на инструкции
	_call HD44780U_Command1										; r25
	HD44780U_Delay_5mks											; задержка 5 мкс

	_call HD44780U_Command2										; r25
	HD44780U_Delay_20mks										; задержка 20 мкс
	HD44780U_Delay_20mks										; задержка 20 мкс
ret																; выход из подпрограммы
