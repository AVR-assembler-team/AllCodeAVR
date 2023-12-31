/*
* �������� ��������� �������
* ��������� �������� - ������� ��:
*					1. ����������� �����������
*					2. ����������� scretch pad
* �� ����� ���������� ��������� ����� ������ (��� OneWireExternalPower)
*/
.macro OneWire_DeviceBusy
	push r16
	push r17

	.if @0 == OneWireConvertTemperatureCommand
		ldi r16, $01
	.else
		clr r16
	.endif

	READ_REG OneWireFlags, r17								; �������� ������� SREG � r17
	sbrc r17, OneWireExternalPower							; ��������� ���� ����������
		OneWire_ExternalPowerDeviceBusy
		OneWire_ParasitePowerDeviceBusy
	
	pop r17
	pop r16
.endm

.macro OneWire_ExternalPowerDeviceBusy
	_call OneWire_ExternalPowerDeviceBusy_act
.endm
.macro OneWire_ParasitePowerDeviceBusy
	_call OneWire_ParasitePowerDeviceBusy_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWire_ParasitePowerDeviceBusy_act:
	cpi r16, $01
	breq Temp
	brne Scre

	Temp:
		_call OneWire_ParasiteConvertTemperature_act

	Scre:
		_call OneWire_ParasiteCopyScratchpad_act
ret
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWire_ExternalPowerDeviceBusy_act:
	push r16											; ���������� r16 � STACK

	OneWireDeviceBusy_act_1:
		READ_REG OneWireFlags, r16						; �������� �������
		sbrc r16, OneWireDeviceNotDetected				; ��������� ���� �����������
			_jump OneWireDeviceBusy_act_finish
		OneWireReadBit									; ��������� ���	(������������ � SREG (�))
		READ_REG SREG, r16								; �������� �������
		sbrs r16, 6										; ��������� ���� �
			_jump OneWireDeviceBusy_act_1

OneWireDeviceBusy_act_finish:
	pop r16												; ����������� r16 �� STACK
ret
//-----------------------------------------------------
OneWire_ParasiteCopyScratchpad_act:
	push r16											; ���������� r16 � STACK
	
	SETB OneWireMOSFET_DDR, OneWireMOSFET_bit			; ������������� ���� �� �����
	SETB OneWireMOSFET_PORT, OneWireMOSFET_bit			; +5 �� ���� � ��������
	OneWire_DelayD										; ��������
	ldi r16, 75											
	OneWire_Parasite_1:
		OneWire_Delay_10ms
		dec r16
		brne OneWire_Parasite_1

	CLRB OneWireMOSFET_PORT, OneWireMOSFET_bit			; 0 �� ���� � ��������
	CLRB OneWireMOSFET_DDR, OneWireMOSFET_bit			; ������������� ���� �� ���� 
	pop r16
ret
//-----------------------------------------------------
OneWire_ParasiteConvertTemperature_act:
	SETB OneWireMOSFET_DDR, OneWireMOSFET_bit			// ������������� ���� �� �����
	SETB OneWireMOSFET_PORT, OneWireMOSFET_bit			// ������������� �� ���� +
	OneWire_Delay_750ms
	CLRB OneWireMOSFET_PORT, OneWireMOSFET_bit			// ������ ���� �� 0
	CLRB OneWireMOSFET_DDR, OneWireMOSFET_bit			// ������������� ���� �� ���� 
ret
