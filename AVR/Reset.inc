STACKINIT		// Инициализация стэка
Modules_Inits
sei



Enable_INT_Interrupt INT0, AnyEdge
Disable_INT_Interrupt INT0
Enable_INT_Interrupt INT0, FallingEdge
Disable_INT_Interrupt INT0
Enable_INT_Interrupt INT0, RisingEdge
Disable_INT_Interrupt INT0

//Enable_INT_Interrupt INT1, AnyEdge
//Disable_INT_Interrupt INT1
//Enable_INT_Interrupt INT1, FallingEdge
//Disable_INT_Interrupt INT1
//Enable_INT_Interrupt INT1, RisingEdge
//Disable_INT_Interrupt INT1

//Enable_INT_Interrupt INT2, AnyEdge
//Disable_INT_Interrupt INT2
//Enable_INT_Interrupt INT2, FallingEdge
//Disable_INT_Interrupt INT2
//Enable_INT_Interrupt INT2, RisingEdge
//Disable_INT_Interrupt INT2

//Enable_INT_Interrupt INT3, AnyEdge
//Disable_INT_Interrupt INT3
//Enable_INT_Interrupt INT3, FallingEdge
//Disable_INT_Interrupt INT3
//Enable_INT_Interrupt INT3, RisingEdge
//Disable_INT_Interrupt INT3

//Enable_INT_Interrupt INT4, AnyEdge
//Disable_INT_Interrupt INT4
//Enable_INT_Interrupt INT4, FallingEdge
//Disable_INT_Interrupt INT4
//Enable_INT_Interrupt INT4, RisingEdge
//Disable_INT_Interrupt INT4

//Enable_INT_Interrupt INT5, AnyEdge
//Disable_INT_Interrupt INT5
//Enable_INT_Interrupt INT5, FallingEdge
//Disable_INT_Interrupt INT5
//Enable_INT_Interrupt INT5, RisingEdge
//Disable_INT_Interrupt INT5

//Enable_INT_Interrupt INT6, AnyEdge
//Disable_INT_Interrupt INT6
//Enable_INT_Interrupt INT6, FallingEdge
//Disable_INT_Interrupt INT6
//Enable_INT_Interrupt INT6, RisingEdge
//Disable_INT_Interrupt INT6

//Enable_INT_Interrupt INT7, AnyEdge
//Disable_INT_Interrupt INT7
//Enable_INT_Interrupt INT7, FallingEdge
//Disable_INT_Interrupt INT7
//Enable_INT_Interrupt INT7, RisingEdge
//Disable_INT_Interrupt INT7

Enable_PCINT 0
Enable_PCINT 1
Enable_PCINT 2
Enable_PCINT 3
Enable_PCINT 4
Enable_PCINT 5
Enable_PCINT 6
Enable_PCINT 7
Enable_PCINT 8
Enable_PCINT 9
Enable_PCINT 10
Enable_PCINT 11
Enable_PCINT 12
Enable_PCINT 13
Enable_PCINT 14
Enable_PCINT 15
Enable_PCINT 16
Enable_PCINT 17
Enable_PCINT 18
Enable_PCINT 19
Enable_PCINT 20
Enable_PCINT 21
Enable_PCINT 22
Enable_PCINT 23
Enable_PCINT 24
Enable_PCINT 25
Enable_PCINT 26
Enable_PCINT 27
Enable_PCINT 28
Enable_PCINT 29
Enable_PCINT 30
//Enable_PCINT 31

Disable_PCINT 0
Disable_PCINT 1
Disable_PCINT 2
Disable_PCINT 3
Disable_PCINT 4
Disable_PCINT 5
Disable_PCINT 6
Disable_PCINT 7
Disable_PCINT 8
Disable_PCINT 9
Disable_PCINT 10
Disable_PCINT 11
Disable_PCINT 12
Disable_PCINT 13
Disable_PCINT 14
Disable_PCINT 15
Disable_PCINT 16
Disable_PCINT 17
Disable_PCINT 18
Disable_PCINT 19
Disable_PCINT 20
Disable_PCINT 21
Disable_PCINT 22
Disable_PCINT 23
Disable_PCINT 24
Disable_PCINT 25
Disable_PCINT 26
Disable_PCINT 27
Disable_PCINT 28
Disable_PCINT 29
Disable_PCINT 30
//Disable_PCINT 31



//SETB EIMSK, INT6
//SETB EIMSK, INT7
/*ldi r16, $02
WRITE_REG PCF8575_Data, r16
inc r16
WRITE_REG PCF8575_Data + 1, r16

PCF8575_Write $42*/
ldi r16, $08
//WRITE_REG PCF8575_Data, r16
inc r16
//WRITE_REG PCF8575_Data + 1, r16

//PCF8575_Write $40
