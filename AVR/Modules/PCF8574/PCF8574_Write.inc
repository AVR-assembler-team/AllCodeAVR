/*
* Записывает байт в чип
*/

.macro PCF8574_Write
	push r18
	push r19
	ldi r18, @0
	mov r19, @1
	_call PCF8574_Write_act
	pop r19
	pop r18
.endm

PCF8574_Write_act:

	TWSI_START										; Стартуем работу
	TWSI_SLA r18, 'W'								; Отправляем адрес и режим работы
	
	READ_REG TWSI_Flags, r18						; Считываем регистр флагов
	sbrc r18, No_ACK								; Проверяем бит 
	_jump gotoPCF8574WriteLabels							; Если поднят, то переходим

	WRITE_REG TWDR, r19								; Вталкиваем в дата регистр

	TWSI_Byte_Transmit								; Отправляем TWDR по шине
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; Проверяем получен ли ответ

	READ_REG TWSI_Flags, r18						; Считываем регистр флагов
	sbrc r18, No_ACK								; Проверяем бит 
	_jump gotoPCF8574WriteLabels							; Если поднят, то переходим

	TWSI_STOP
	_jump PCF8574_Write_end

	gotoPCF8574WriteLabels:
		TWSI_STOP
		_call PCF8574_NoAck

	PCF8574_Write_end:

ret
