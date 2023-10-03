.macro TimersCounter0


	.if @0 == Overflow
		TimersPrescallerCounter0 Prescaller1
		.if ctrl == 8
			SETB TIMSK, TOV0
		.elif ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162 || ctrl == 8515 || ctrl == 8535
			SETB TIMSK, TOIE0
		.else
			SETB TIMSK0, TOIE0
		.endif



	.elif @0 == CompareMatch
		.if ctrl == 8|| ctrl == 48 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284 || ctrl == 8515 || ctrl == 8535
			.error "This Counter not supporting Compare Match !"
		.else
			.if @1 == mks1
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $01
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $01
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $02
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $02
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $04
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $04
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $01
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $01
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $02
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $02
						SETB TIMSK0, OCIE0A
					.endif
				.endif
			.elif @1 == mks10
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $0a
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $0a
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $14
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $14
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $05
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $05
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $0a
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $0a
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 16000000
					.if ctrl == 64 || ctrl == 128
						TimersPrescallerCounter0 Prescaller32
						.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
							WRITE_BYTE OCR0, $05
							SETB TIMSK, OCIE0
						.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
							WRITE_BYTE OCR0A, $05
							SETB TIMSK0, OCIE0A
						.endif
					.else
						TimersPrescallerCounter0 Prescaller8
						.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
							WRITE_BYTE OCR0, $14
							SETB TIMSK, OCIE0
						.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
							WRITE_BYTE OCR0A, $14
							SETB TIMSK0, OCIE0A
						.endif
					.endif
				.endif
			.elif @1 == mks25
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $19
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $19
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $32
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $32
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $64
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $64
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $19
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $19
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $32
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $32
						SETB TIMSK0, OCIE0A
					.endif
				.endif
			.elif @1 == mks100
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $64
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $64
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $19
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $19
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $32
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $32
						SETB TIMSK0, OCIE0A
					.endif
				.elif ATmegaFREQ == 8000000
					.if ctrl == 64 || ctrl == 128
						TimersPrescallerCounter0 Prescaller32
						.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
							WRITE_BYTE OCR0, $19
							SETB TIMSK, OCIE0
						.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
							WRITE_BYTE OCR0A, $19
							SETB TIMSK0, OCIE0A
						.endif
					.else
						TimersPrescallerCounter0 Prescaller8
						.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
							WRITE_BYTE OCR0, $64
							SETB TIMSK, OCIE0
						.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
							WRITE_BYTE OCR0A, $64
							SETB TIMSK0, OCIE0A
						.endif
					.endif
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller64
					.if ctrl == 16 || ctrl == 32 || ctrl == 64 || ctrl == 128 || ctrl == 162
						WRITE_BYTE OCR0, $19
						SETB TIMSK, OCIE0
					.elif ctrl == 165 || ctrl == 169 || ctrl == 325 || ctrl == 3250 || ctrl == 645 || ctrl == 6450 || ctrl == 329 || ctrl == 3290 || ctrl == 649 || ctrl == 6490
						WRITE_BYTE OCR0A, $19
						SETB TIMSK0, OCIE0A
					.endif
				.endif
			.endif
		.endif
	.elif @0 == CompareMatchA
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == mks1
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $01
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $02
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $04
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $01
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $02
				.endif
			.elif @1 == mks10
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $0a
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $14
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $05
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $0a
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $14
				.endif
			.elif @1 == mks25
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $19
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $32
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $64
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $19
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $32
				.endif
			.elif @1 == mks100
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0A, $64
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $19
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $32
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0A, $64
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller64
					WRITE_BYTE OCR0A, $19
				.endif
			.endif
		SETB TIMSK0, OCIE0A
		.else
			.error "This Counter not supporting Compare Match A!"
		.endif
	.elif @0 == CompareMatchB
		.if ctrl == 48 || ctrl == 88 || ctrl == 168 || ctrl == 164 || ctrl == 324 || ctrl == 644 || ctrl == 328 || ctrl == 640 || ctrl == 1280 || ctrl == 1281 || ctrl == 2560 || ctrl == 2561 || ctrl == 1284
			.if @1 == mks1
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $01
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $02
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $04
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $01
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $02
				.endif
			.elif @1 == mks10
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $0a
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $14
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $05
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $0a
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $14
				.endif
			.elif @1 == mks25
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $19
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $32
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $64
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $19
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $32
				.endif
			.elif @1 == mks100
				.if ATmegaFREQ == 1000000
					TimersPrescallerCounter0 Prescaller1
					WRITE_BYTE OCR0B, $64
				.elif ATmegaFREQ == 2000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $19
				.elif ATmegaFREQ == 4000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $32
				.elif ATmegaFREQ == 8000000
					TimersPrescallerCounter0 Prescaller8
					WRITE_BYTE OCR0B, $64
				.elif ATmegaFREQ == 16000000
					TimersPrescallerCounter0 Prescaller64
					WRITE_BYTE OCR0B, $19
				.endif
			.endif
		SETB TIMSK0, OCIE0B
		.else
			.error "This Counter not supporting Compare Match B!"
		.endif
	.endif
.endm