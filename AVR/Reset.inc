STACKINIT		// Инициализация стэка
Modules_Inits
sei

ldi r16, $08
WRITE_REG PCF8575_2_bytes, r16
inc r16
WRITE_REG PCF8575_2_bytes + 1, r16

PCF8575Write $40

ldi r16, $02
WRITE_REG PCF8575_2_bytes, r16
inc r16
WRITE_REG PCF8575_2_bytes + 1, r16

PCF8575Write $42
