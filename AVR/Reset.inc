STACKINIT		// Инициализация стэка
Modules_Inits
sei

//OneWire_ReadROM
OneWire_SingleDeviceTemperature
//OneWire_SingleDeviceTempPrepareToReading     ;
//OneWire_SingleDeviceTempReadind
OneWire_TemperatureDataConvertation
//OneWire_ConvertTemperature
; HD44780U
	//TWSI_START										; отсылаем START (рестартуем для записи)
	//ldi r16, TWSI_Address
	//TWSI_SLA r16, 'W'
	//HD44780U_LCD_Clear

	//HD44780U_LCD_Clear
	//HD44780U_Set_Cursor 3, 20
	//HD44780U_Write_Symbol 'g'
	//HD44780U_Write_Symbol 'W'
	//HD44780U_Write_Symbol 'W'
	//TWSI_STOP



; InternalInterrupts
	//Enable_INT_Interrupt INT4, FallingEdge
	//Enable_INT_Interrupt INT5, FallingEdge

; PCF8575
	//ldi r16, $08
	//ldi r17, $09
	//PCF8575_Write $40, r16, r17

; PCF8574
	//ldi r16, $7f
	//PCF8574_Write $70, r16
