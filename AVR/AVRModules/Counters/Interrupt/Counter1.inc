.macro CountersInterruptCounter1
	.if @0 == CompareMatch
		.error "Compare Match is not supporting by counter 1 of this controller!"
	.elif @0 == Overflow
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == Enable
				SETB TIMSK, TOIE1
			.elif @1 == Disable
				CLRB TIMSK, TOIE1
			.endif
		.else
			.if @1 == Enable
				SETB TIMSK1, TOIE1
			.elif @1 == Disable
				CLRB TIMSK1, TOIE1
			.endif
		.endif
	.elif @0 == CaptureEvent
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == Enable
				SETB TIMSK, TICIE1
			.elif @1 == Disable
				CLRB TIMSK, TICIE1
			.endif
		.else
			.if @1 == Enable
				SETB TIMSK1, ICIE1
			.elif @1 == Disable
				CLRB TIMSK1, ICIE1
			.endif
		.endif
	.elif @0 == CompareMatchA
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == Enable
				SETB TIMSK, OCIE1A
				WRITE_BYTE OCR1AH, high(@2)
				WRITE_BYTE OCR1AL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK, OCIE1A
				WRITE_BYTE OCR1AH, $00
				WRITE_BYTE OCR1AL, $00
			.endif
		.else
			.if @1 == Enable
				SETB TIMSK1, OCIE1A
				WRITE_BYTE OCR1AH, high(@2)
				WRITE_BYTE OCR1AL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK1, OCIE1A
				WRITE_BYTE OCR1AH, $00
				WRITE_BYTE OCR1AL, $00
			.endif
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.if @1 == Enable
				SETB TIMSK, OCIE1B
				WRITE_BYTE OCR1BH, high(@2)
				WRITE_BYTE OCR1BL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK, OCIE1B
				WRITE_BYTE OCR1BH, $00
				WRITE_BYTE OCR1BL, $00
			.endif
		.else
			.if @1 == Enable
				SETB TIMSK1, OCIE1B
				WRITE_BYTE OCR1BH, high(@2)
				WRITE_BYTE OCR1BL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK1, OCIE1B
				WRITE_BYTE OCR1BH, $00
				WRITE_BYTE OCR1BL, $00
			.endif
		.endif
	.elif @0 == CompareMatchC
		.if ctrl == 64 || ctrl == 128 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == Enable
				SETB TIMSK1, OCIE1C
				WRITE_BYTE OCR1CH, high(@2)
				WRITE_BYTE OCR1CL, low(@2)
			.elif @1 == Disable
				CLRB TIMSK1, OCIE1C
				WRITE_BYTE OCR1CH, $00
				WRITE_BYTE OCR1CL, $00
			.endif
		.else
			.error "Compare Match C is not supporting by counter 1 of this controller!"
		.endif
	.endif
.endm
