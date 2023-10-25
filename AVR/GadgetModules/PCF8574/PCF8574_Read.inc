.macro PCF8574Read
	TWSI_START									; Стартуем работу
	ldi r25, @0
	TWSI_SLA r25, 'R'							; Отправляем адрес и режим работы 

	_call PCF8574_Read_act
.endm

 PCF8574_Read_act:


	READ_REG TWSI_Flags, r25					; Считываем регистр флагов
	sbrc r25, No_ACK							; Проверяем бит 
	_jump gotoPCF8574ReadLabels					; Если поднят, то переходим

	TWSI_Byte_Transmit							; больше не принимаем байты

	READ_REG TWDR, r25							; читаем данные с TWDR
	WRITE_REG PCF8574Bytes, r25
	
	TWSI_ACK_Transmit							; отправляем ACK
		
	_jump PCF8574_Read_end

	gotoPCF8574ReadLabels:
		_call PCF8574_NoAck
		WRITE_BYTE PCF8574Bytes, $00

	PCF8574_Read_end:
	TWSI_STOP
 ret

