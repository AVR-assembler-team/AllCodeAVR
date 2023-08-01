/*
* Ответ
*/
.macro TWSI_ACK_Transmit 
	push r16
	ldi r16, @0
	WRITE_REG TWSR, r16
	pop r16
.endm

