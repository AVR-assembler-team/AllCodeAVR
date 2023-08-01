.macro PCF8575Write
	push r16
	TWSI_START @0, 'W'
	READ_REG PCF8575_2_bytes, r16
	TWSI_Sending_byte r16
	READ_REG PCF8575_2_bytes + 1, r16
	TWSI_Sending_byte r16
	TWSI_STOP
	pop r16
.endm
