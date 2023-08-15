.macro PCF8575_Read
	push r18
	push r19
	ldi r18, @0
	_call PCF8575_Read_act
	WRITE_REG @1, r18					; записываем в память
	WRITE_REG @2, r19					; записываем в память
	pop r19
	pop r18

.endm

 PCF8575_Read_act:

	TWSI_START									; Стартуем работу
	TWSI_SLA r18, 'R'							; Отправляем адрес и режим работы 

	READ_REG TWSI_Flags, r18					; Считываем регистр флагов
	sbrc r18, No_ACK							; Проверяем бит 
	_jump gotoPCF8575ReadLabels						; Если поднят, то переходим

	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r18							; читаем данные с TWDR
	
	
	TWSI_ACK_Transmit							; отправляем ACK

	READ_REG TWDR, r19							; читаем данные с TWDR
	

	TWSI_Byte_Transmit							; больше не принимаем байты
	
	TWSI_STOP
	_jump PCF8575_Read_end

	gotoPCF8575ReadLabels:
		_call PCF8575_NoAck
		clr r18
		clr r19

	PCF8575_Read_end:
 ret

