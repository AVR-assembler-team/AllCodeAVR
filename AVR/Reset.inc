STACKINIT		// Инициализация стэка
Modules_Inits
sei

	TWSI_START										; отсылаем START (рестартуем для записи)
	ldi r16, TWSI_Address
	TWSI_SLA r16, 'W'
	//HD44780U_LCD_Clear
	//HD44780U_Set_Cursor 3, 6
	;HD44780U_Write_Symbol 'W'
	//TWSI_STOP
//SETB EIMSK, INT6
//SETB EIMSK, INT7

//Enable_INT_Interrupt INT5, FallingEdge

//ldi r16, $08
//WRITE_REG PCF8575_Data, r16
//inc r16
//WRITE_REG PCF8575_Data + 1, r16

//PCF8575_Write $40
