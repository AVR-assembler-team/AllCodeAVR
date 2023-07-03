//////////////////////////////////////////////////
.macro OneWire_SingleDeviceTemperature
	OneWire_SingleDeviceTempPrepareToReading
	OneWire_SingleDeviceTempReadind
.endm
.macro OneWire_SingleDeviceTempPrepareToReading
	OneWire_SkipROM
	OneWire_ConvertTemperature
.endm 
.macro OneWire_SingleDeviceTempReadind
	OneWire_SkipROM
	OneWire_ReadScratchpad
.endm
//////////////////////////////////////////////////
; принимает один аргумени - метку в RAM по которой лежит ROM code
.macro OneWire_ROMDeviceTemperature
	OneWire_ROMDeviceTempPrepareToReading @0
	OneWire_ROMDeviceTempTempReadind @0
	OneWire_TemperatureDataConvertation
.endm
.macro OneWire_ROMDeviceTempPrepareToReading
	OneWire_MatchROM @0
	OneWire_ConvertTemperature
.endm
.macro OneWire_ROMDeviceTempTempReadind
	OneWire_MatchROM @0
	OneWire_ReadScratchpad
.endm

