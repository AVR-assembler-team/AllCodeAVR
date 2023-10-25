
WRITE_BYTE PCF8575Bytes, $25
WRITE_BYTE PCF8575Bytes + 1, $0f

PCF8575Write $40
PCF8575Read $40
//PCF8574Write $70, r16

//WRITE_BYTE PCF8574Bytes +2, $25
//PCF8574Write $70
//PCF8574Read $70
// Пример настройки счетчиков
;CountersPrescaller Counter0, Prescaller8
;CountersOffMode Counter0
;CountersPrescaller Counter1, Prescaller1024
;CountersOffMode Counter1
;CountersPrescaller Counter2, Prescaller8
;CountersOffMode Counter2
;CountersPrescaller Counter3, Prescaller8
;CountersOffMode Counter3
;CountersPrescaller Counter4, Prescaller1024
;CountersOffMode Counter4
;CountersPrescaller Counter5, Prescaller1024
;CountersOffMode Counter5

;CountersInterrupt Counter0, Overflow, enabled, $30
;CountersInterrupt Counter0, CompareMatch, enabled, $30
;CountersInterrupt Counter5, CompareMatchA, enabled, $395
;CountersInterrupt Counter5, CompareMatchB, enabled, $465
;CountersInterrupt Counter5, CompareMatchC, enabled, $578

;CountersInterrupt Counter5, CompareMatchA, disabled
;CountersInterrupt Counter5, CompareMatchB, disabled
;CountersInterrupt Counter5, CompareMatchC, disabled

;CountersInterrupt Counter5, CaptureEvent, enabled, $30
;CountersInterrupt Counter5, Overflow, enabled, $30
;CountersInterrupt Counter5, CompareMatch, enabled, $30
;CountersInterrupt Counter5, CompareMatchA, enabled, $30
;CountersInterrupt Counter5, CompareMatchB, enabled, $30
;CountersInterrupt Counter5, CompareMatchC, enabled, $30

;CountersWeveformGenerationMode Counter0, 2
;CountersWeveformGenerationMode Counter1, 2
;CountersWeveformGenerationMode Counter2, 2
;CountersWeveformGenerationMode Counter3, 2
;CountersWeveformGenerationMode Counter4, 2
;CountersWeveformGenerationMode Counter5, 12

;CountersCompareOutputMode Counter5, CompareMatchOutput, 3
;CountersCompareOutputMode Counter5, CompareMatchOutputC, 3
;CountersCompareOutputMode Counter5, CompareMatchOutputA, 3
;CountersCompareOutputMode Counter5, CompareMatchOutputB, 3

;CountersExternalClockSourceOnT0pin Counter0, FallingEdge
;CountersPrescaller Counter0, Prescaller1
;CountersExternalClockSourceOnT0pin Counter0, RisingEdge

;CountersExternalClockSourceOnT0pin Counter1, FallingEdge
;CountersPrescaller Counter1, Prescaller1
;CountersExternalClockSourceOnT0pin Counter1, RisingEdge

;CountersExternalClockSourceOnT0pin Counter2, FallingEdge
;CountersPrescaller Counter2, Prescaller1
;CountersExternalClockSourceOnT0pin Counter2, RisingEdge

;CountersExternalClockSourceOnT0pin Counter3, FallingEdge
;CountersPrescaller Counter3, Prescaller1
;CountersExternalClockSourceOnT0pin Counter3, RisingEdge

;CountersExternalClockSourceOnT0pin Counter4, FallingEdge
;CountersPrescaller Counter4, Prescaller1
;CountersExternalClockSourceOnT0pin Counter4, RisingEdge

;CountersExternalClockSourceOnT0pin Counter5, FallingEdge
;CountersPrescaller Counter5, Prescaller1
;CountersExternalClockSourceOnT0pin Counter5, RisingEdge


