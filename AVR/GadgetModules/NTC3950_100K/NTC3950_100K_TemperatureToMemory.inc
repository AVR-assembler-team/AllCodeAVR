TempToTable:
	ldi xl, low(TempRange * 2)		; �������� ������� ������� ������ TempRange � xl
	ldi xh, high(TempRange * 2)		; �������� ������� ������� ������ TempRange � xh

	sub zl, xl						; ������� �������� �� ������ �������
	sbc zh, xh

	_call SaveTemp
	_call ReadableTemperature
ret

SaveTemp:
		WRITE_REG TemtVar, zl		; ���������� �������� �������� � ������
		;clr zl
		;WRITE_REG Temperature + 1, zl		; ���������� �������� �������� �������� � ������
ret