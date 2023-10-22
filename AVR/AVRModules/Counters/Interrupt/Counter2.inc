.macro CountersInterruptCounter2
	.if @0 == CompareMatch
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == Enable
				SETB TIMSK, OCIE2
				WRITE_BYTE OCR2, @2
			.elif @1 == Disable
				CLRB TIMSK, OCIE2
				WRITE_BYTE OCR2, $00
			.endif
		.else
			.error "Compare Match Interrupt is not supporting by counter 2 of this controller!"
		.endif
	.elif @0 == Overflow
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
			.if @1 == Enable
				SETB TIMSK, TOIE2
			.elif @1 == Disable
				CLRB TIMSK, TOIE2
			.endif
		.elif ctrl == 8515 || ctrl == 8535
			.error "Overflow Interrupt is not supporting by counter 2 of this controller!"
		.else
			.if @1 == Enable
				SETB TIMSK2, TOIE2
			.elif @1 == Disable
				CLRB TIMSK2, TOIE2
			.endif
		.endif
	.elif @0 == CaptureEvent
		.error "Capture Event Interrupt is not supporting by counter 2 of this controller!"
	.elif @0 == CompareMatchA
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.error "Compare Match A Interrupt is not supporting by counter 2 of this controller!"
		.else
			.if @1 == Enable
				SETB TIMSK2, OCIE2A
				WRITE_BYTE OCR2A, @2
			.elif @1 == Disable
				CLRB TIMSK2, OCIE2A
				WRITE_BYTE OCR2A, $00
			.endif
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 8 || ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			.error "Compare Match B Interrupt is not supporting by counter 2 of this controller!"
		.else
			.if @1 == Enable
				SETB TIMSK2, OCIE2B
				WRITE_BYTE OCR2B, @2
			.elif @1 == Disable
				CLRB TIMSK2, OCIE2B
				WRITE_BYTE OCR2B, $00
			.endif
		.endif
	.elif @0 == CompareMatchC
		.error "Compare Match C Interrupt is not supporting by counter 2 of this controller!"
	.endif
.endm
