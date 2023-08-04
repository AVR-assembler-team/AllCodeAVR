STACKINIT		// Инициализация стэка
Modules_Inits
sei


//HD44780U_Write_Symbol 'W'

//SETB EIMSK, INT6
//SETB EIMSK, INT7
/*ldi r16, $02
WRITE_REG PCF8575_Data, r16
inc r16
WRITE_REG PCF8575_Data + 1, r16

PCF8575_Write $42*/
//ldi r16, $08
//WRITE_REG PCF8574_Data, r16
//inc r16
//WRITE_REG PCF8575_Data + 1, r16

//PCF8574_Write $70 //$40
