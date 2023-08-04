STACKINIT		// Инициализация стэка
Modules_Inits
sei





//SETB EIMSK, INT6
//SETB EIMSK, INT7
/*ldi r16, $02
WRITE_REG PCF8575_Data, r16
inc r16
WRITE_REG PCF8575_Data + 1, r16

PCF8575_Write $42*/
ldi r16, $08
//WRITE_REG PCF8575_Data, r16
inc r16
//WRITE_REG PCF8575_Data + 1, r16

//PCF8575_Write $40
