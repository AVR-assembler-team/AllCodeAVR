/*
* Проверка занятости девайса
* Принимает аргумент - команда на:
*					1. Конвертацию теспература
*					2. Копирование scretch pad
* Вл время выполнения проверяет байта флагов (бит OneWireExternalPower)
*/
.macro OneWire_DeviceBusy
	push r16
	push r17

	.if @0 == OneWireConvertTemperatureCommand
		ldi r16, $01
	.else
		clr r16
	.endif

	READ_REG OneWireFlags, r17								; копируем регистр SREG в r17
	sbrc r17, OneWireExternalPower							; проверяем флат отсутствия
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
	push r16											; вталкиваем r16 в STACK

	OneWireDeviceBusy_act_1:
		READ_REG OneWireFlags, r16						; копируем регистр
		sbrc r16, OneWireDeviceNotDetected				; проверяем флат присутствия
			_jump OneWireDeviceBusy_act_finish
		OneWireReadBit									; считываем бит	(записывается в SREG (Т))
		READ_REG SREG, r16								; копируем регистр
		sbrs r16, 6										; проверяем флаг Т
			_jump OneWireDeviceBusy_act_1

OneWireDeviceBusy_act_finish:
	pop r16												; выталкиваем r16 из STACK
ret
//-----------------------------------------------------
OneWire_ParasiteCopyScratchpad_act:
	push r16											; вталкиваем r16 в STACK
	
	SETB OneWireMOSFET_DDR, OneWireMOSFET_bit			; устанавливаем ногу на выход
	SETB OneWireMOSFET_PORT, OneWireMOSFET_bit			; +5 на ногу с мосфетом
	OneWire_DelayD										; задержка
	ldi r16, 75											
	OneWire_Parasite_1:
		OneWire_Delay_10ms
		dec r16
		brne OneWire_Parasite_1

	CLRB OneWireMOSFET_PORT, OneWireMOSFET_bit			; 0 на ногу с мосфетом
	CLRB OneWireMOSFET_DDR, OneWireMOSFET_bit			; устанавливаем ногу на вход 
	pop r16
ret
//-----------------------------------------------------
OneWire_ParasiteConvertTemperature_act:
	SETB OneWireMOSFET_DDR, OneWireMOSFET_bit			// устанавливаем ногу на выход
	SETB OneWireMOSFET_PORT, OneWireMOSFET_bit			// устанавливаем на ноге +
	OneWire_Delay_750ms
	CLRB OneWireMOSFET_PORT, OneWireMOSFET_bit			// роняем ногу на 0
	CLRB OneWireMOSFET_DDR, OneWireMOSFET_bit			// устанавливаем ногу на вход 
ret
