.dseg
OneWireROMCode:					.byte 8
OneWireAlarmROMCode:			.byte 8
OneWireScratchpad:				.byte 9
OneWireTemperature:				.byte 2

OneWireFlags:					.byte 1
OneWireZeroFork:				.byte 1
OneWireStep:					.byte 1
OneWireLastFork:				.byte 1
OneWireROMVar:					.byte 1

.cseg

// OneWireFlags
.equ OneWireDeviceNotDetected	= 0
.equ OneWireROMCodeCRCInvalid	= 1
.equ OneWireNegativeTemperature = 2
.equ OneWireOneHundredDegrees	= 3
.equ OneWireLastDevice			= 4
.equ OneWireSlaveBit			= 5
.equ OneWireMasterBit			= 6
.equ OneWireExternalPower		= 7

// ROM Commands
.equ OneWireReadROMCommand = $33
.equ OneWireMachROMCommand = $55
.equ OneWireSearchROMCommand = $f0
.equ OneWireAlarmSearchCommand = $ec
.equ OneWireSkipROMCommand = $cc

// Function Commands
.equ OneWireConvertTemperatureCommand = $44
.equ OneWireCopyScratchpadCommand = $48
.equ OneWireWriteScratchpadCommand = $4e
.equ OneWireReadScreatchpadCommand = $be
.equ OneWireRecallCommand = $b8
.equ OneWirePowerSupplyCommand = $b4

.equ OneWireCRC_polynom = $8c

.equ DS1820 = 0
.equ DS18S20 = 0
.equ DS18B20 = 1
.equ DS1822 = 1

.equ ExternalPower = 0
.equ ParasitePower = 1
