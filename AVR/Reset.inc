STACKINIT		// Инициализация стэка
Modules_Inits
sei

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
	Enable_INT_Interrupt INT5, FallingEdge

; PCF8575
	//ldi r16, $08
	//WRITE_REG PCF8575_Data, r16
	//inc r16
	//WRITE_REG PCF8575_Data + 1, r16

	//PCF8575_Write $40

; PCF8574
	//ldi r16, $e7
	//WRITE_REG PCF8574_Data, r16
	//PCF8574_Write $70
