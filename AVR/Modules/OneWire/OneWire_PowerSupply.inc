/*
* Узнает на каком питании находится датчик (при условии, что он один на шине)
* и записывает результат в память OneWireFlags (OneWireExternalPower)
*/
.macro OneWire_PowerSupply
	OneWireSendCommand OneWirePowerSupplyCommand
	OneWireReadBit
	_call OneWireSingleDevicePowerSupply_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireSingleDevicePowerSupply_act:
	push r16										; вталкиваем r16 в STACK
	READ_REG SREG, r16								; читаем SREG в r16

	sbrc r16, 6										; если флаг Т поднят, то пропускаем след строку
		_jump OneWireExternalPowerOn				; переходим на метку

	CLRB OneWireFlags, OneWireExternalPower			; очищаем флаг внешнего питания
	_jump OneWireSingleDevicePowerSupply_act_finish	; переходим к концу функции

OneWireExternalPowerOn:								; метка
	SETB OneWireFlags, OneWireExternalPower			; устанавливаем флаг внешнего питания

OneWireSingleDevicePowerSupply_act_finish:			; метка
	pop r16											; выталкиваем r16 из STACK
ret
