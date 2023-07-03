TempToTable:
	ldi xl, low(TempRange * 2)		; копируем младший регистр адреса TempRange в xl
	ldi xh, high(TempRange * 2)		; копируем старший регистр адреса TempRange в xh

	sub zl, xl						; находим смещение от начала массива
	sbc zh, xh

	_call SaveTemp
	_call ReadableTemperature
ret

SaveTemp:
		WRITE_REG TemtVar, zl		; записываем значение градусов в память
		;clr zl
		;WRITE_REG Temperature + 1, zl		; записываем значение десятков градусов в память
ret