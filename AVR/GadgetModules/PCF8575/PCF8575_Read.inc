.macro PCF8575Read

	TWSI_START									; Стартуем работу
	ldi r25, @0
	TWSI_SLA r25, 'R'							; Отправляем адрес и режим работы 

	_call PCF8575Read_act

.endm

 PCF8575Read_act:


	READ_REG TWSI_Flags, r25					; Считываем регистр флагов
	sbrc r25, No_ACK							; Проверяем бит 
	_jump gotoPCF8575ReadLabels						; Если поднят, то переходим

	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r25							; читаем данные с TWDR
	WRITE_REG PCF8575Bytes, r25
	
	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r25							; читаем данные с TWDR
	WRITE_REG PCF8575Bytes + 1, r25

	TWSI_Byte_Transmit							; больше не принимаем байты
	
	_jump PCF8575Read_end

gotoPCF8575ReadLabels:
	_call PCF8575_NoAck
	WRITE_BYTE PCF8575Bytes, $00
	WRITE_BYTE PCF8575Bytes + 1, $00

	PCF8575Read_end:
	TWSI_STOP

 ret

