.macro UBBR1
	.if @0 == 2400
		ldi r16, 25
	.elif @0 == 4800
		ldi r16, 12
	.elif @0 == 9600
		ldi r16, 6
	.elif @0 == 14400
		ldi r16, 3
	.elif @0 == 19200
		ldi r16, 2
	.elif @0 == 28800
		ldi r16, 1
	.elif @0 == 38400
		ldi r16, 1
	.elif @0 > 57600
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR2
	.if @0 == 2400
		ldi r16, 51
	.elif @0 == 4800
		ldi r16, 25
	.elif @0 == 9600
		ldi r16, 12
	.elif @0 == 14400
		ldi r16, 8
	.elif @0 == 19200
		ldi r16, 6
	.elif @0 == 28800
		ldi r16, 3
	.elif @0 == 38400
		ldi r16, 2
	.elif @0 == 57600
		ldi r16, 1
	.elif @0 == 76800
		ldi r16, 1
	.elif @0 > 115200
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR3
	.if @0 == 2400
		ldi r16, 103
	.elif @0 == 4800
		ldi r16, 51
	.elif @0 == 9600
		ldi r16, 25
	.elif @0 == 14400
		ldi r16, 16
	.elif @0 == 19200
		ldi r16, 12
	.elif @0 == 28800
		ldi r16, 8
	.elif @0 == 38400
		ldi r16, 6
	.elif @0 == 57600
		ldi r16, 3
	.elif @0 == 76800
		ldi r16, 2
	.elif @0 == 115200
		ldi r16, 1
	.elif @0 > 250000
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR4
	.if @0 == 2400
		ldi r16, 207
	.elif @0 == 4800
		ldi r16, 103
	.elif @0 == 9600
		ldi r16, 51
	.elif @0 == 14400
		ldi r16, 34
	.elif @0 == 19200
		ldi r16, 25
	.elif @0 == 28800
		ldi r16, 16
	.elif @0 == 38400
		ldi r16, 12
	.elif @0 == 57600
		ldi r16, 8
	.elif @0 == 76800
		ldi r16, 6
	.elif @0 == 115200
		ldi r16, 3
	.elif @0 == 230400
		ldi r16, 1
	.elif @0 == 250000
		ldi r16, 1
	.elif @0 > 500000
		.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
	.endif
.endm
.macro UBBR5
	.if @0 == 2400
		ldi r16, 160
		ldi r17, 1
	.elif @0 == 4800
		ldi r16, 207
	.elif @0 == 9600
		ldi r16, 103
	.elif @0 == 14400
		ldi r16, 68
	.elif @0 == 19200
		ldi r16, 51
	.elif @0 == 28800
		ldi r16, 34
	.elif @0 == 38400
		ldi r16, 25
	.elif @0 == 57600
		ldi r16, 16
	.elif @0 == 76800
		ldi r16, 12
	.elif @0 == 115200
		ldi r16, 8
	.elif @0 == 230400
		ldi r16, 3
	.elif @0 == 250000
		ldi r16, 3
	.elif @0 == 500000
		ldi r16, 1
	.endif
.endm
.macro UBBR6
	.if @0 == 2400
		ldi r16, 64
		ldi r17, 3
	.elif @0 == 4800
		ldi r16, 160
		ldi r17, 1
	.elif @0 == 9600
		ldi r16, 207
	.elif @0 == 14400
		ldi r16, 138
	.elif @0 == 19200
		ldi r16, 103
	.elif @0 == 28800
		ldi r16, 68
	.elif @0 == 38400
		ldi r16, 51
	.elif @0 == 57600
		ldi r16, 34
	.elif @0 == 76800
		ldi r16, 25
	.elif @0 == 115200
		ldi r16, 16
	.elif @0 == 230400
		ldi r16, 8
	.elif @0 == 250000
		ldi r16, 7
	.elif @0 == 500000
		ldi r16, 3
	.elif @0 == 1000000
		ldi r16, 1
	.endif
.endm


.macro USARTBaudRate
	
	clr r16
	clr r17

	.if ATmegaFREQ == 1000000
		.if @1 == Normal
			UBBR1 @2
		.elif @1 == Double
			UBBR2 @2
		.endif
	.elif ATmegaFREQ == 2000000
		.if @1 == Normal
			UBBR2 @2
		.elif @1 == Double
			UBBR3 @2
			.if @2 == 230400
				.error "Baud Rate not available for this ATmegaFREQ. Read DataSheet!"
			.endif
		.endif
	.elif ATmegaFREQ == 4000000
		.if @1 == Normal
			UBBR3 @2
		.elif @1 == Double
			UBBR4 @2
		.endif
	.elif ATmegaFREQ == 8000000
		.if @1 == Normal
			UBBR4 @2
		.elif @1 == Double
			UBBR5 @2
		.endif
	.elif ATmegaFREQ == 16000000
		.if @1 == Normal
			UBBR5 @2
		.elif @1 == Double
			UBBR6 @2
		.endif
	.endif


	.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 8515 || ctrl == 8535
		.if @0 == 0	
			WRITE_REG UBRRH, r17
			WRITE_REG UBRRL, r16
		.endif

	.elif ctrl == 48 || ctrl == 88 || ctrl == 168
		.if @0 == 0
			WRITE_REG UBRR0H, r17
			WRITE_REG UBRR0L, r16
		.endif

	.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 328 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
		.if @0 == 0
			WRITE_REG UBRR0H, r17
			WRITE_REG UBRR0L, r16
		.endif
	
	.elif ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 1284 
		.if @0 == 0
			WRITE_REG UBRR0H, r17
			WRITE_REG UBRR0L, r16
		.elif @0 == 1
			WRITE_REG UBRR1H, r17
			WRITE_REG UBRR1L, r16
		.endif

	.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
		.if @0 == 0
			WRITE_REG UBRR0H, r17
			WRITE_REG UBRR0L, r16
		.elif @0 == 1
			WRITE_REG UBRR1H, r17
			WRITE_REG UBRR1L, r16
		.elif @0 == 2
			WRITE_REG UBRR2H, r17
			WRITE_REG UBRR2L, r16
		.elif @0 == 3
			WRITE_REG UBRR3H, r17
			WRITE_REG UBRR3L, r16
		.endif

	.endif
.endm
