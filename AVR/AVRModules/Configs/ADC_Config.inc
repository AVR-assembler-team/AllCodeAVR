





//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Reference Selection

; бывает - TurnedOff, AREFpin, Voltage_1_1, Voltage_2_56
; раскоментируйте нужный вам

//#define TurnedOff
#define AREFpin
//#define Voltage_1_1
//#define Voltage_2_56

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Left Adjust Result

; бывает - Left, Right as default

#define Adjust_Left

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; ADC Free Running Select или ADC Auto Trigger

; бывает:
;			null - Free Run Mode или ADC Auto Trigger Mode отключен (as default)
;			FreeRun - ADC Free Running Select или Free Running mode (в зависимости от контроллера)
;			AnComp - Analog Comparator
;			ExtIntReq0 - External Interrupt Request 0
;			TC0CompMatch - Timer/Counter0 Compare Match
;			TC0Overflow - Timer/Counter0 Overflow
;			TC1CompMatchB - Timer/Counter1 Compare Match B
;			TC1Overflow - Timer/Counter1 Overflow
;			TC1CaptEvent - Timer/Counter1 Capture Event
; раскоментируйте нужный вам

#define FreeRun
//#define AnComp
//#define ExtIntReq0
//#define TC0CompMatch
//#define TC0Overflow
//#define TC1CompMatchB
//#define TC1Overflow
//#define TC1CaptEvent

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; ADC Interrupt Enable

; бывает - Enabled, Disabled as default

#define ADCInterrupt_Enabled

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

