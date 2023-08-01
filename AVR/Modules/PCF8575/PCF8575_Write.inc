/*
* Записывает 2 байта в чип
*/

.macro PCF8575_Write
	push r18
	ldi r18, @0
	_call PCF8575_Write_act
	pop r18
.endm

PCF8575_Write_act:

	TWSI_START										; Стартуем работу
	TWSI_SLA r18, 'W'								; Отправляем адрес и режим работы
	
	READ_REG TWSI_Flags, r18						; Считываем регистр флагов
	sbrc r18, No_ACK								; Проверяем бит 
	_jump gotoWriteLabels							; Если поднят, то переходим

	READ_REG PCF8575_Data, r18
	WRITE_REG TWDR, r18								; Вталкиваем в дата регистр
	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r18						; Считываем регистр флагов
	sbrc r18, No_ACK								; Проверяем бит 
	_jump gotoWriteLabels							; Если поднят, то переходим

	READ_REG PCF8575_Data + 1, r18
	WRITE_REG TWDR, r18								; вталкиваем в дата регистр
	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r18						; Считываем регистр флагов
	sbrc r18, No_ACK								; Проверяем бит 
	_jump gotoWriteLabels							; Если поднят, то переходим
	
	TWSI_STOP
	_jump PCF8575_Write_end

	gotoWriteLabels:
		TWSI_STOP
		_call PCF8575_NoAck

	PCF8575_Write_end:
ret
