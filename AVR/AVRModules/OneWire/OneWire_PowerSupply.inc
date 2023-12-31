/*
* ������ �� ����� ������� ��������� ������ (��� �������, ��� �� ���� �� ����)
* � ���������� ��������� � ������ OneWireFlags (OneWireExternalPower)
*/
.macro OneWire_PowerSupply
	OneWireSendCommand OneWirePowerSupplyCommand
	OneWireReadBit
	_call OneWireSingleDevicePowerSupply_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSingleDevicePowerSupply_act:
	push r16										; ���������� r16 � STACK
	READ_REG SREG, r16								; ������ SREG � r16

	sbrc r16, 6										; ���� ���� � ������, �� ���������� ���� ������
		_jump OneWireExternalPowerOn				; ��������� �� �����

	CLRB OneWireFlags, OneWireExternalPower			; ������� ���� �������� �������
	_jump OneWireSingleDevicePowerSupply_act_finish	; ��������� � ����� �������

OneWireExternalPowerOn:								; �����
	SETB OneWireFlags, OneWireExternalPower			; ������������� ���� �������� �������

OneWireSingleDevicePowerSupply_act_finish:			; �����
	pop r16											; ����������� r16 �� STACK
ret
