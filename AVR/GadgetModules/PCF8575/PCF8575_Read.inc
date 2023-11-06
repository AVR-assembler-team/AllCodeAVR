.macro PCF8575Read
	
	push r24
	ldi r24, @0

	TWSI_START									; Стартуем работу
	TWSI_SLA r24, 'R'							; Отправляем адрес и режим работы 

	_call PCF8575Read_act

	pop r24

.endm

 PCF8575Read_act:

	push r25

	READ_REG TWSI_Flags, r25					; Считываем регистр флагов
	sbrc r25, No_ACK							; Проверяем бит 
	_jump gotoPCF8575ReadLabels					; Если поднят, то переходим

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
	clr r25
	WRITE_REG PCF8575Bytes, r25
	WRITE_REG PCF8575Bytes + 1, r25

	PCF8575Read_end:
	TWSI_STOP

	pop r25

 ret

