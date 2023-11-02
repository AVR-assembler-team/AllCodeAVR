/*
* Записывает 2 байта в чип
*/

.macro PCF8575Write

	TWSI_START										; Стартуем работу
	TWSI_SLA @0, 'W'								; Отправляем адрес и режим работы

	_call PCF8575Write_act
.endm

PCF8575Write_act:
	
	READ_REG TWSI_Flags, r25						; Считываем регистр флагов
	sbrc r25, No_ACK								; Проверяем бит 
	_jump gotoPCF8575WriteLabels					; Если поднят, то переходим
	
	READ_REG PCF8575Bytes, r25
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр

	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r25						; Считываем регистр флагов
	sbrc r25, No_ACK								; Проверяем бит 
	_jump gotoPCF8575WriteLabels							; Если поднят, то переходим
	
	READ_REG PCF8575Bytes + 1, r25
	WRITE_REG TWDR, r25								; вталкиваем в дата регистр

	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r25						; Считываем регистр флагов
	sbrc r25, No_ACK								; Проверяем бит 
		_jump gotoPCF8575WriteLabels				; Если поднят, то переходим
		_jump PCF8575Write_end

gotoPCF8575WriteLabels:
	_call PCF8575_NoAck

PCF8575Write_end:
	TWSI_STOP
ret
