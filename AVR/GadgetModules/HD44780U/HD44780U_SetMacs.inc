/*
* В данном файле лежать макросы, работающие на файл HD44780U_config, для первоначальных настроек 
* работы дисплея
*/
;------------------------------------
.macro HD44780U_RSpin
	.if @0 == 'A'
		.equ HD44780U_RS_DDR	= DDRA	
		.equ HD44780U_RS_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_RS_DDR	= DDRB	
		.equ HD44780U_RS_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_RS_DDR	= DDRC	
		.equ HD44780U_RS_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_RS_DDR	= DDRD	
		.equ HD44780U_RS_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_RS_DDR	= DDRE	
		.equ HD44780U_RS_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_RS_DDR	= DDRF	
		.equ HD44780U_RS_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_RS_DDR	= DDRG	
		.equ HD44780U_RS_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_RS_DDR	= DDRH	
		.equ HD44780U_RS_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_RS_DDR	= DDRJ	
		.equ HD44780U_RS_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_RS_DDR	= DDRK	
		.equ HD44780U_RS_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_RS_DDR	= DDRL	
		.equ HD44780U_RS_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_RS_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_RS_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_RS_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_RS_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_RS_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_RS_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_RS_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_RS_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_RWpin
	.if @0 == 'A'
		.equ HD44780U_RW_DDR	= DDRA	
		.equ HD44780U_RW_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_RW_DDR	= DDRB	
		.equ HD44780U_RW_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_RW_DDR	= DDRC	
		.equ HD44780U_RW_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_RW_DDR	= DDRD	
		.equ HD44780U_RW_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_RW_DDR	= DDRE	
		.equ HD44780U_RW_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_RW_DDR	= DDRF	
		.equ HD44780U_RW_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_RW_DDR	= DDRG	
		.equ HD44780U_RW_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_RW_DDR	= DDRH	
		.equ HD44780U_RW_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_RW_DDR	= DDRJ	
		.equ HD44780U_RW_PORT   = PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_RW_DDR	= DDRK	
		.equ HD44780U_RW_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_RW_DDR	= DDRL	
		.equ HD44780U_RW_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_RW_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_RW_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_RW_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_RW_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_RW_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_RW_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_RW_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_RW_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_Epin
	.if @0 == 'A'
		.equ HD44780U_E_DDR		= DDRA	
		.equ HD44780U_E_PORT	= PORTA
	.elif @0 == 'B'	  
		.equ HD44780U_E_DDR		= DDRB	
		.equ HD44780U_E_PORT	= PORTB
	.elif @0 == 'C'	  
		.equ HD44780U_E_DDR		= DDRC	
		.equ HD44780U_E_PORT	= PORTC
	.elif @0 == 'D'	  
		.equ HD44780U_E_DDR		= DDRD	
		.equ HD44780U_E_PORT	= PORTD
	.elif @0 == 'E'	  
		.equ HD44780U_E_DDR		= DDRE	
		.equ HD44780U_E_PORT	= PORTE
	.elif @0 == 'F'	  
		.equ HD44780U_E_DDR		= DDRF	
		.equ HD44780U_E_PORT	= PORTF
	.elif @0 == 'G'	  
		.equ HD44780U_E_DDR		= DDRG	
		.equ HD44780U_E_PORT	= PORTG
	.elif @0 == 'H'	  
		.equ HD44780U_E_DDR		= DDRH	
		.equ HD44780U_E_PORT	= PORTH
	.elif @0 == 'J'	  
		.equ HD44780U_E_DDR		= DDRJ	
		.equ HD44780U_E_PORT	= PORTJ
	.elif @0 == 'K'	  
		.equ HD44780U_E_DDR		= DDRK	
		.equ HD44780U_E_PORT	= PORTK
	.elif @0 == 'L'	  
		.equ HD44780U_E_DDR		= DDRL	
		.equ HD44780U_E_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_E_bit = 0
	.elif @1 == 1   
		.equ HD44780U_E_bit = 1
	.elif @1 == 2   
		.equ HD44780U_E_bit = 2
	.elif @1 == 3   
		.equ HD44780U_E_bit = 3
	.elif @1 == 4   
		.equ HD44780U_E_bit = 4
	.elif @1 == 5   
		.equ HD44780U_E_bit = 5
	.elif @1 == 6   
		.equ HD44780U_E_bit = 6
	.elif @1 == 7   
		.equ HD44780U_E_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_LIGHTpin
	.if @0 == 'A'
		.equ HD44780U_LIGHT_DDR		= DDRA	
		.equ HD44780U_LIGHT_PORT	= PORTA
	.elif @0 == 'B'	  
		.equ HD44780U_LIGHT_DDR		= DDRB	
		.equ HD44780U_LIGHT_PORT	= PORTB
	.elif @0 == 'C'	  
		.equ HD44780U_LIGHT_DDR		= DDRC	
		.equ HD44780U_LIGHT_PORT	= PORTC
	.elif @0 == 'D'	  
		.equ HD44780U_LIGHT_DDR		= DDRD	
		.equ HD44780U_LIGHT_PORT	= PORTD
	.elif @0 == 'E'	  
		.equ HD44780U_LIGHT_DDR		= DDRE	
		.equ HD44780U_LIGHT_PORT	= PORTE
	.elif @0 == 'F'	  
		.equ HD44780U_LIGHT_DDR		= DDRF	
		.equ HD44780U_LIGHT_PORT	= PORTF
	.elif @0 == 'G'	  
		.equ HD44780U_LIGHT_DDR		= DDRG	
		.equ HD44780U_LIGHT_PORT	= PORTG
	.elif @0 == 'H'	  
		.equ HD44780U_LIGHT_DDR		= DDRH	
		.equ HD44780U_LIGHT_PORT	= PORTH
	.elif @0 == 'J'	  
		.equ HD44780U_LIGHT_DDR		= DDRJ	
		.equ HD44780U_LIGHT_PORT	= PORTJ
	.elif @0 == 'K'	  
		.equ HD44780U_LIGHT_DDR		= DDRK	
		.equ HD44780U_LIGHT_PORT	= PORTK
	.elif @0 == 'L'	  
		.equ HD44780U_LIGHT_DDR		= DDRL	
		.equ HD44780U_LIGHT_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_LIGHT_bit = 0
	.elif @1 == 1   
		.equ HD44780U_LIGHT_bit = 1
	.elif @1 == 2   
		.equ HD44780U_LIGHT_bit = 2
	.elif @1 == 3   
		.equ HD44780U_LIGHT_bit = 3
	.elif @1 == 4   
		.equ HD44780U_LIGHT_bit = 4
	.elif @1 == 5   
		.equ HD44780U_LIGHT_bit = 5
	.elif @1 == 6   
		.equ HD44780U_LIGHT_bit = 6
	.elif @1 == 7   
		.equ HD44780U_LIGHT_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D0pin
	.if @0 == 'A'
		.equ HD44780U_D0_DDR	= DDRA	
		.equ HD44780U_D0_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D0_DDR	= DDRB	
		.equ HD44780U_D0_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D0_DDR	= DDRC	
		.equ HD44780U_D0_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D0_DDR	= DDRD	
		.equ HD44780U_D0_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D0_DDR	= DDRE	
		.equ HD44780U_D0_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D0_DDR	= DDRF	
		.equ HD44780U_D0_PORT   = PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D0_DDR	= DDRG	
		.equ HD44780U_D0_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D0_DDR	= DDRH	
		.equ HD44780U_D0_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D0_DDR	= DDRJ	
		.equ HD44780U_D0_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D0_DDR	= DDRK	
		.equ HD44780U_D0_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D0_DDR	= DDRL	
		.equ HD44780U_D0_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D0_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D0_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D0_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D0_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D0_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D0_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D0_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D0_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D1pin
	.if @0 == 'A'
		.equ HD44780U_D1_DDR	= DDRA	
		.equ HD44780U_D1_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D1_DDR	= DDRB	
		.equ HD44780U_D1_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D1_DDR	= DDRC	
		.equ HD44780U_D1_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D1_DDR	= DDRD	
		.equ HD44780U_D1_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D1_DDR	= DDRE	
		.equ HD44780U_D1_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D1_DDR	= DDRF	
		.equ HD44780U_D1_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D1_DDR	= DDRG	
		.equ HD44780U_D1_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D1_DDR	= DDRH	
		.equ HD44780U_D1_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D1_DDR	= DDRJ	
		.equ HD44780U_D1_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D1_DDR	= DDRK	
		.equ HD44780U_D1_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D1_DDR	= DDRL	
		.equ HD44780U_D1_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D1_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D1_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D1_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D1_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D1_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D1_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D1_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D1_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D2pin
	.if @0 == 'A'
		.equ HD44780U_D2_DDR	= DDRA	
		.equ HD44780U_D2_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D2_DDR	= DDRB	
		.equ HD44780U_D2_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D2_DDR	= DDRC	
		.equ HD44780U_D2_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D2_DDR	= DDRD	
		.equ HD44780U_D2_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D2_DDR	= DDRE	
		.equ HD44780U_D2_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D2_DDR	= DDRF	
		.equ HD44780U_D2_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D2_DDR	= DDRG	
		.equ HD44780U_D2_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D2_DDR	= DDRH	
		.equ HD44780U_D2_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D2_DDR	= DDRJ	
		.equ HD44780U_D2_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D2_DDR	= DDRK	
		.equ HD44780U_D2_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D2_DDR	= DDRL	
		.equ HD44780U_D2_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D2_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D2_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D2_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D2_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D2_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D2_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D2_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D2_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D3pin
	.if @0 == 'A'
		.equ HD44780U_D3_DDR	= DDRA	
		.equ HD44780U_D3_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D3_DDR	= DDRB	
		.equ HD44780U_D3_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D3_DDR	= DDRC	
		.equ HD44780U_D3_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D3_DDR	= DDRD	
		.equ HD44780U_D3_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D3_DDR	= DDRE	
		.equ HD44780U_D3_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D3_DDR	= DDRF	
		.equ HD44780U_D3_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D3_DDR	= DDRG	
		.equ HD44780U_D3_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D3_DDR	= DDRH	
		.equ HD44780U_D3_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D3_DDR	= DDRJ	
		.equ HD44780U_D3_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D3_DDR	= DDRK	
		.equ HD44780U_D3_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D3_DDR	= DDRL	
		.equ HD44780U_D3_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D3_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D3_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D3_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D3_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D3_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D3_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D3_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D3_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D4pin
	.if @0 == 'A'
		.equ HD44780U_D4_DDR	= DDRA	
		.equ HD44780U_D4_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D4_DDR	= DDRB	
		.equ HD44780U_D4_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D4_DDR	= DDRC	
		.equ HD44780U_D4_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D4_DDR	= DDRD	
		.equ HD44780U_D4_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D4_DDR	= DDRE	
		.equ HD44780U_D4_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D4_DDR	= DDRF	
		.equ HD44780U_D4_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D4_DDR	= DDRG	
		.equ HD44780U_D4_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D4_DDR	= DDRH	
		.equ HD44780U_D4_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D4_DDR	= DDRJ	
		.equ HD44780U_D4_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D4_DDR	= DDRK	
		.equ HD44780U_D4_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D4_DDR	= DDRL	
		.equ HD44780U_D4_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D4_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D4_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D4_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D4_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D4_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D4_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D4_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D4_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D5pin
	.if @0 == 'A'
		.equ HD44780U_D5_DDR	= DDRA	
		.equ HD44780U_D5_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D5_DDR	= DDRB	
		.equ HD44780U_D5_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D5_DDR	= DDRC	
		.equ HD44780U_D5_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D5_DDR	= DDRD	
		.equ HD44780U_D5_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D5_DDR	= DDRE	
		.equ HD44780U_D5_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D5_DDR	= DDRF	
		.equ HD44780U_D5_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D5_DDR	= DDRG	
		.equ HD44780U_D5_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D5_DDR	= DDRH	
		.equ HD44780U_D5_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D5_DDR	= DDRJ	
		.equ HD44780U_D5_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D5_DDR	= DDRK	
		.equ HD44780U_D5_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D5_DDR	= DDRL	
		.equ HD44780U_D5_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D5_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D5_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D5_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D5_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D5_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D5_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D5_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D5_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D6pin
	.if @0 == 'A'
		.equ HD44780U_D6_DDR	= DDRA	
		.equ HD44780U_D6_PORT	= PORTA
	.elif @0 == 'B'	   
		.equ HD44780U_D6_DDR	= DDRB	
		.equ HD44780U_D6_PORT	= PORTB
	.elif @0 == 'C'	   
		.equ HD44780U_D6_DDR	= DDRC	
		.equ HD44780U_D6_PORT	= PORTC
	.elif @0 == 'D'	   
		.equ HD44780U_D6_DDR	= DDRD	
		.equ HD44780U_D6_PORT	= PORTD
	.elif @0 == 'E'	   
		.equ HD44780U_D6_DDR	= DDRE	
		.equ HD44780U_D6_PORT	= PORTE
	.elif @0 == 'F'	   
		.equ HD44780U_D6_DDR	= DDRF	
		.equ HD44780U_D6_PORT	= PORTF
	.elif @0 == 'G'	   
		.equ HD44780U_D6_DDR	= DDRG	
		.equ HD44780U_D6_PORT	= PORTG
	.elif @0 == 'H'	   
		.equ HD44780U_D6_DDR	= DDRH	
		.equ HD44780U_D6_PORT	= PORTH
	.elif @0 == 'J'	   
		.equ HD44780U_D6_DDR	= DDRJ	
		.equ HD44780U_D6_PORT	= PORTJ
	.elif @0 == 'K'	   
		.equ HD44780U_D6_DDR	= DDRK	
		.equ HD44780U_D6_PORT	= PORTK
	.elif @0 == 'L'	   
		.equ HD44780U_D6_DDR	= DDRL	
		.equ HD44780U_D6_PORT	= PORTL
	.endif
	.if @1 == 0
		.equ HD44780U_D6_bit = 0
	.elif @1 == 1	   
		.equ HD44780U_D6_bit = 1
	.elif @1 == 2	   
		.equ HD44780U_D6_bit = 2
	.elif @1 == 3	   
		.equ HD44780U_D6_bit = 3
	.elif @1 == 4	   
		.equ HD44780U_D6_bit = 4
	.elif @1 == 5	   
		.equ HD44780U_D6_bit = 5
	.elif @1 == 6	   
		.equ HD44780U_D6_bit = 6
	.elif @1 == 7	   
		.equ HD44780U_D6_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_D7pin
	.if @0 == 'A'
		.equ HD44780U_D7_DDR	= DDRA	
		.equ HD44780U_D7_PORT	= PORTA
		.equ HD44780U_D7_PIN	= PINA
	.elif @0 == 'B'	   
		.equ HD44780U_D7_DDR	= DDRB	
		.equ HD44780U_D7_PORT	= PORTB
		.equ HD44780U_D7_PIN	= PINB
	.elif @0 == 'C'	   
		.equ HD44780U_D7_DDR	= DDRC	
		.equ HD44780U_D7_PORT	= PORTC
		.equ HD44780U_D7_PIN	= PINC
	.elif @0 == 'D'	   
		.equ HD44780U_D7_DDR	= DDRD	
		.equ HD44780U_D7_PORT	= PORTD
		.equ HD44780U_D7_PIN	= PIND
	.elif @0 == 'E'	   
		.equ HD44780U_D7_DDR	= DDRE	
		.equ HD44780U_D7_PORT	= PORTE
		.equ HD44780U_D7_PIN	= PINE
	.elif @0 == 'F'	   
		.equ HD44780U_D7_DDR	= DDRF	
		.equ HD44780U_D7_PORT	= PORTF
		.equ HD44780U_D7_PIN	= PINF
	.elif @0 == 'G'
		.equ HD44780U_D7_DDR	= DDRG	
		.equ HD44780U_D7_PORT	= PORTG
		.equ HD44780U_D7_PIN	= PING
	.elif @0 == 'H'   
		.equ HD44780U_D7_DDR	= DDRH	
		.equ HD44780U_D7_PORT	= PORTH
		.equ HD44780U_D7_PIN	= PINH
	.elif @0 == 'J'	   
		.equ HD44780U_D7_DDR	= DDRJ	
		.equ HD44780U_D7_PORT	= PORTJ
		.equ HD44780U_D7_PIN	= PINJ
	.elif @0 == 'K'	   
		.equ HD44780U_D7_DDR	= DDRK	
		.equ HD44780U_D7_PORT	= PORTK
		.equ HD44780U_D7_PIN	= PINK
	.elif @0 == 'L'	   
		.equ HD44780U_D7_DDR	= DDRL	
		.equ HD44780U_D7_PORT	= PORTL
		.equ HD44780U_D7_PIN	= PINL
	.endif
	.if @1 == 0
		.equ HD44780U_D7_bit = 0
	.elif @1 == 1     
		.equ HD44780U_D7_bit = 1
	.elif @1 == 2     
		.equ HD44780U_D7_bit = 2
	.elif @1 == 3     
		.equ HD44780U_D7_bit = 3
	.elif @1 == 4     
		.equ HD44780U_D7_bit = 4
	.elif @1 == 5     
		.equ HD44780U_D7_bit = 5
	.elif @1 == 6     
		.equ HD44780U_D7_bit = 6
	.elif @1 == 7     
		.equ HD44780U_D7_bit = 7
	.endif
.endm
;------------------------------------
.macro HD44780U_SLA_Address
	.equ HD44780U_SLA_ = @0	
.endm
