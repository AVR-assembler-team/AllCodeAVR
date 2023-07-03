//=========================================================================================
//=========================================================================================

; ADC Prescaler selection

; �������� ����� 50kHz � 200kHz
; ����� ATmegaFREQ/50000 = ��������� �� ������� �������
; ����� ATmegaFREQ/200000 = ��������� �� ������� �������
; �������� ����� ���� 
; ������ - 2, 4, 8, 16, 32, 64, 128
; ��������������� ������ ���

//#define Prescaler_2
//#define Prescaler_4
//#define Prescaler_8
//#define Prescaler_16
//#define Prescaler_32
//#define Prescaler_64
#define Prescaler_128

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Reference Selection

; ������ - TurnedOff, AREFpin, Voltage_1_1, Voltage_2_56
; ��������������� ������ ���

//#define TurnedOff
#define AREFpin
//#define Voltage_1_1
//#define Voltage_2_56

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Left Adjust Result

; ������ - Left, Right as default

//#define Adjust_Left

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Input Channel Delections

; ������ 
;			Single Ended Input - ADC0 ... ADC15
;			Positive Differential input - ADC0 ... ADC15
;			Negative Differential input - ADC0 ... ADC2, ADC8 ... ADC10
;			Gain - 1, 10, 200
; ��������������� ������ ���

//#define SingleEndedInput_ADC0
//#define SingleEndedInput_ADC1
//#define SingleEndedInput_ADC2
//#define SingleEndedInput_ADC3
//#define SingleEndedInput_ADC4
//#define SingleEndedInput_ADC5
//#define SingleEndedInput_ADC6
//#define SingleEndedInput_ADC7
//#define SingleEndedInput_ADC8
//#define SingleEndedInput_ADC9
//#define SingleEndedInput_ADC10
//#define SingleEndedInput_ADC11
//#define SingleEndedInput_ADC12
//#define SingleEndedInput_ADC13
//#define SingleEndedInput_ADC14
//#define SingleEndedInput_ADC15
//#define SingleEndedInput_VBG
//#define SingleEndedInput_GND

#define PositiveDifferentialInput_ADC0
//#define PositiveDifferentialInput_ADC1
//#define PositiveDifferentialInput_ADC2
//#define PositiveDifferentialInput_ADC3
//#define PositiveDifferentialInput_ADC4
//#define PositiveDifferentialInput_ADC5
//#define PositiveDifferentialInput_ADC6
//#define PositiveDifferentialInput_ADC7
//#define PositiveDifferentialInput_ADC8
//#define PositiveDifferentialInput_ADC9
//#define PositiveDifferentialInput_ADC10
//#define PositiveDifferentialInput_ADC11
//#define PositiveDifferentialInput_ADC12
//#define PositiveDifferentialInput_ADC13
//#define PositiveDifferentialInput_ADC14
//#define PositiveDifferentialInput_ADC15

#define NegativeDifferentialInput_ADC0
//#define NegativeDifferentialInput_ADC1
//#define NegativeDifferentialInput_ADC2
//#define NegativeDifferentialInput_ADC8
//#define NegativeDifferentialInput_ADC9
//#define NegativeDifferentialInput_ADC10

//#define Gain_1
#define Gain_10
//#define Gain_200

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; ADC Free Running Select ��� ADC Auto Trigger

; ������:
;			null - Free Run Mode ��� ADC Auto Trigger Mode �������� (as default)
;			FreeRun - ADC Free Running Select ��� Free Running mode (� ����������� �� �����������)
;			AnComp - Analog Comparator
;			ExtIntReq0 - External Interrupt Request 0
;			TC0CompMatch - Timer/Counter0 Compare Match
;			TC0Overflow - Timer/Counter0 Overflow
;			TC1CompMatchB - Timer/Counter1 Compare Match B
;			TC1Overflow - Timer/Counter1 Overflow
;			TC1CaptEvent - Timer/Counter1 Capture Event
; ��������������� ������ ���

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

; ������ - Enabled, Disabled as default

#define ADCInterrupt_Enabled

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

; Digital Input Disable 

; �������������� �� ����, ������� �� ����� ���������

//#define Disable_ADC0D
//#define Disable_ADC1D
//#define Disable_ADC2D
//#define Disable_ADC3D
//#define Disable_ADC4D
//#define Disable_ADC5D
//#define Disable_ADC6D
//#define Disable_ADC7D
//#define Disable_ADC8D
//#define Disable_ADC9D
//#define Disable_ADC10D
//#define Disable_ADC11D
//#define Disable_ADC12D
//#define Disable_ADC13D
//#define Disable_ADC14D
//#define Disable_ADC15D