.macro CountersInterruptCounter4
	.if @0 == CaptureEvent
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK4, ICIE4
			.elif @1 == Disable
				CLRB TIMSK4, ICIE4
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == Overflow
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK4, TOIE4
			.elif @1 == Disable
				CLRB TIMSK4, TOIE4
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatch
		.error "Compare Match is not supporting by counter 4 of this controller!"
	.elif @0 == CompareMatchA
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK4, OCIE4A
				WRITE_BYTE OCR4AH, high(@2)
				WRITE_BYTE OCR4AL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK4, OCIE4A
				WRITE_BYTE OCR4AH, $00
				WRITE_BYTE OCR4AL, $00
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchB
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK4, OCIE4B
				WRITE_BYTE OCR4BH, high(@2)
				WRITE_BYTE OCR4BL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK4, OCIE4B
				WRITE_BYTE OCR4BH, $00
				WRITE_BYTE OCR4BL, $00
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchC
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK4, OCIE4C
				WRITE_BYTE OCR4CH, high(@2)
				WRITE_BYTE OCR4CL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK4, OCIE4C
				WRITE_BYTE OCR4CH, $00
				WRITE_BYTE OCR4CL, $00
			.endif
		.else
			.error "Counter 4 is not supporting by your controller!"
		.endif
	.endif
.endm
