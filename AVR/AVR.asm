/*
* AVR Modules
*/

.include "Main/Includes.inc"
///////////////////////////////////////////////////////////////////////
Reset:
.include "Reset.inc"

Proga:
// ������� README ����
// ���� ���������
	
rjmp Proga
ADCINTtt:
	READ_REG ADCL, r17
	READ_REG ADCH, r16

	WRITE_REG PORTK, r16
ret
