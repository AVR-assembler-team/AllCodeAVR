/*
* Отправка инструкций дисплею
* Использует регистр r25
*/

HD44780U_Send_instruction:
	cbi HD44780U_RS_PORT, HD44780U_RS_bit	; устанавливаем на инструкции
	_call HD44780U_Command					; r25
	_call HD44780U_BF_Check					; r25
ret											; выход из подпрограммы
