.macro CountersInterruptCounter5
	.if @0 == CaptureEvent
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK5, ICIE5
			.elif @1 == Disable
				CLRB TIMSK5, ICIE5
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == Overflow
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK5, TOIE5
			.elif @1 == Disable
				CLRB TIMSK5, TOIE5
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatch
		.error "Compare Match is not supporting by counter 5 of this controller!"
	.elif @0 == CompareMatchA
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK5, OCIE5A
				WRITE_BYTE OCR5AH, high(@2)
				WRITE_BYTE OCR5AL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK5, OCIE5A
				WRITE_BYTE OCR5AH, $00
				WRITE_BYTE OCR5AL, $00
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchB
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK5, OCIE5B
				WRITE_BYTE OCR5BH, high(@2)
				WRITE_BYTE OCR5BL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK5, OCIE5B
				WRITE_BYTE OCR5BH, $00
				WRITE_BYTE OCR5BL, $00
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchC
		.if Ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK5, OCIE5C
				WRITE_BYTE OCR5CH, high(@2)
				WRITE_BYTE OCR5CL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK5, OCIE5C
				WRITE_BYTE OCR5CH, $00
				WRITE_BYTE OCR5CL, $00
			.endif
		.else
			.error "Counter 5 is not supporting by your controller!"
		.endif
	.endif
.endm
