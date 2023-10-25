/*
* ѕередаем модулю TWSI адрес чипа, читать или записывать
* ѕринимает два аргумента
* @0 - јдрес чипа TWSI
* @1 - 'W'-запись / 'R'-чтение

* ѕосле проверки в регистре флагов (TWSI_Flags) будет установлено соответственное 
* состо€ние бита (Address_No_ACK)
* 0 - все хорошо
* 1 - ответа нет
*/
.macro TWSI_SLA

	.if @1 == 'W'
		mov	r25, @0
	.elif @1 == 'R'
		mov	r25, @0
		sbr	r25, 1
	.endif
		
	WRITE_REG TWDR, r25						; вталкиваем в дата регистр
	TWSI_Byte_Transmit

	.if @1 == 'W'
		TWSI_ACK_Check MT_SLA_W_ACK, MT_SLA_W_NOT_ACK					; ѕровер€ем получен ли ответ
	.elif @1 == 'R'
		TWSI_ACK_Check MT_SLA_R_ACK, MT_SLA_R_NOT_ACK					; ѕровер€ем получен ли ответ
	.endif

.endm
