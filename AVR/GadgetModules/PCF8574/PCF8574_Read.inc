.macro PCF8574_Read
	push r18
	ldi r18, @0
	_call PCF8574_Read_act
	WRITE_REG @1, r18					; записываем в память
	pop r18

.endm

 PCF8574_Read_act:

	TWSI_START									; Стартуем работу
	TWSI_SLA r18, 'R'							; Отправляем адрес и режим работы 

	READ_REG TWSI_Flags, r18					; Считываем регистр флагов
	sbrc r18, No_ACK							; Проверяем бит 
	_jump gotoPCF8574ReadLabels						; Если поднят, то переходим

	TWSI_Byte_Transmit							; больше не принимаем байты

	READ_REG TWDR, r18							; читаем данные с TWDR
	
	TWSI_ACK_Transmit							; отправляем ACK
		
	TWSI_STOP
	_jump PCF8574_Read_end

	gotoPCF8574ReadLabels:
		_call PCF8574_NoAck
		clr r18

	PCF8574_Read_end:
 ret

