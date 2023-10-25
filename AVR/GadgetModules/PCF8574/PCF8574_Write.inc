/*
* Записывает байт в чип
*/

.macro PCF8574Write
	TWSI_START										; Стартуем работу
	TWSI_SLA @0, 'W'								; Отправляем адрес и режим работы

	_call PCF8574_Write_act
.endm

PCF8574_Write_act:
	
	READ_REG TWSI_Flags, r25						; Считываем регистр флагов
	sbrc r25, No_ACK								; Проверяем бит 
	_jump gotoPCF8574WriteLabels					; Если поднят, то переходим

	READ_REG PCF8574Bytes, r25
	WRITE_REG TWDR, r25								; Вталкиваем в дата регистр

	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r25						; Считываем регистр флагов
	sbrc r25, No_ACK								; Проверяем бит 
		_jump gotoPCF8574WriteLabels				; Если поднят, то переходим
		_jump PCF8574_Write_end

gotoPCF8574WriteLabels:
	_call PCF8574_NoAck

PCF8574_Write_end:
	TWSI_STOP
ret
