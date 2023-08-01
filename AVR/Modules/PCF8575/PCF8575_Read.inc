.macro PCF8575Read
	
	push r16
	TWSI_START @0, 'R'
	TWSI_Reading_byte r18
	TWSI_Reading_byte r19
	TWSI_NACK
	TWSI_STOP
	pop r16

.endm
 
