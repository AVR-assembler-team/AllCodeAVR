.macro PCF8575_Read
	push r18
	ldi r18, @0
	_call PCF8575_Read_act
	pop r18

.endm

 PCF8575_Read_act:

	TWSI_START									; Стартуем работу
	TWSI_SLA r18, 'R'							; Отправляем адрес и режим работы 

	READ_REG TWSI_Flags, r18					; Считываем регистр флагов
	sbrc r18, No_ACK							; Проверяем бит 
	_jump gotoReadLabels						; Если поднят, то переходим

	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r18							; читаем данные с TWDR
	WRITE_REG PCF8575_Data, r18					; записываем в память
	
	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r18							; читаем данные с TWDR
	WRITE_REG PCF8575_Data + 1, r18				; записываем в память

	TWSI_Byte_Transmit							; больше не принимаем байты
	
	TWSI_STOP
	_jump PCF8575_Read_end

	gotoReadLabels:
		_call PCF8575_NoAck

	PCF8575_Read_end:
 ret

