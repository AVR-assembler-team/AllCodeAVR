.macro CountersInterruptCounter3
	.if @0 == CaptureEvent
		.if ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == enabled
				SETB ETIMSK, TICIE3
			.elif @1 == disabled
				CLRB ETIMSK, TICIE3
			.endif
		.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == enabled
				SETB TIMSK3, ICIE3
			.elif @1 == disabled
				CLRB TIMSK3, ICIE3
			.endif
		.else
			.error "Counter 3 is not supporting by your controller!"
		.endif
	.elif @0 == Overflow
		.if ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == enabled
				SETB ETIMSK, TOIE3
			.elif @1 == disabled
				CLRB ETIMSK, TOIE3
			.endif
		.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == enabled
				SETB TIMSK3, TOIE3
			.elif @1 == disabled
				CLRB TIMSK3, TOIE3
			.endif
		.else
			.error "Counter 3 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatch
		.error "Compare Match is not supporting by counter 3 of this controller!"
	.elif @0 == CompareMatchA
		.if ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == enabled
				SETB ETIMSK, OCIE3A
				WRITE_BYTE OCR3AH, high(@2)
				WRITE_BYTE OCR3AL, low(@2)
			.elif @1 == disabled
				CLRB ETIMSK, OCIE3A
				WRITE_BYTE OCR3AH, $00
				WRITE_BYTE OCR3AL, $00
			.endif
		.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == enabled
				SETB TIMSK3, OCIE3A
				WRITE_BYTE OCR3AH, high(@2)
				WRITE_BYTE OCR3AL, low(@2)
			.elif @1 == disabled
				CLRB TIMSK3, OCIE3A
				WRITE_BYTE OCR3AH, $00
				WRITE_BYTE OCR3AL, $00
			.endif
		.else
			.error "Counter 3 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == enabled
				SETB ETIMSK, OCIE3B
				WRITE_BYTE OCR3BH, high(@2)
				WRITE_BYTE OCR3BL, low(@2)
			.elif @1 == disabled
				CLRB ETIMSK, OCIE3B
				WRITE_BYTE OCR3BH, $00
				WRITE_BYTE OCR3BL, $00
			.endif
		.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == enabled
				SETB TIMSK3, OCIE3B
				WRITE_BYTE OCR3BH, high(@2)
				WRITE_BYTE OCR3BL, low(@2)
			.elif @1 == disabled
				CLRB TIMSK3, OCIE3B
				WRITE_BYTE OCR3BH, $00
				WRITE_BYTE OCR3BL, $00
			.endif
		.else
			.error "Counter 3 is not supporting by your controller!"
		.endif
	.elif @0 == CompareMatchC
		.if ctrl == 64 || ctrl == 128
			.if @1 == enabled
				SETB ETIMSK, OCIE3C
				WRITE_BYTE OCR3CH, high(@2)
				WRITE_BYTE OCR3CL, low(@2)
			.elif @1 == disabled
				CLRB ETIMSK, OCIE3C
				WRITE_BYTE OCR3CH, $00
				WRITE_BYTE OCR3CL, $00
			.endif
		.elif ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561
			.if @1 == enabled
				SETB TIMSK3, OCIE3C
				WRITE_BYTE OCR3CH, high(@2)
				WRITE_BYTE OCR3CL, low(@2)
			.elif @1 == disabled
				CLRB TIMSK3, OCIE3C
				WRITE_BYTE OCR3CH, $00
				WRITE_BYTE OCR3CL, $00
			.endif
		.elif ctrl == 162 || ctrl == 1284
			.error "Compare Match C is not supporting by counter 3 of this controller!"
		.else
			.error "Counter 3 is not supporting by your controller!"
		.endif
	.endif
.endm
