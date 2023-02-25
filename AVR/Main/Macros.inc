.macro _call
	.if ctlr == 8 || ctlr == 48 || ctlr == 88 || ctlr == 8515 || ctlr == 8535
		rcall @0
	.else
		call @0
	.endif
.endm
//________________________________
.macro _jump
	.if ctlr == 8 || ctlr == 48 || ctlr == 88 || ctlr == 8515 || ctlr == 8535
		rjmp @0
	.else
		jmp @0
	.endif
.endm
//________________________________
.macro Bits_set_or_clear
	sbrs @0, @1
		cbi @2, @3
	sbrc @0, @1
		sbi @2, @3
.endm



.macro	STACKINIT
	.if	RAMEND>0x0000

		ldi	r16, Low(RAMEND)
		.ifdef SPL
		out	SPL, r16
		.else
		out	SP,	r16
		.endif

		.ifdef SPH
		ldi	r16, High(RAMEND)
		out	SPH, r16
		.endif

	.else
		.warning "This device have not SRAM. Can not initialize Stack!"
	.endif
.endm
//________________________________
.macro WDTOFF
	wdr

	in r16, MCUSR
	andi r16, (0xff & (0<<WDRF))
	out MCUSR, r16

	ldi r16, WDTCSR
	ori   r16, (1<<WDCE) | (1<<WDE)
	sts WDTCSR, r16

	ldi   r16, (0<<WDE)
	sts WDTCSR, r16
.endm
//________________________________
.macro	WRITE_BYTE
	push r16
		ldi	r16, @1
	.if	@0 < 0x40
		out	@0, r16
	.else
		sts	@0, r16
	.endif
	pop r16
.endm
//________________________________
.macro	WRITE_REG
	.if	@0 < 0x40
		out	@0, @1
	.else
		sts	@0, @1
	.endif
.endm
//________________________________
.macro READ_REG
	.if	@0 < 0x40
		in @1, @0
	.else
		lds	@1, @0
	.endif
.endm
//________________________________
.macro PUSHF
	push r16
	in	r16, SREG
	push r16
.endm
.macro POPF
	pop	r16
	out	SREG, r16
	pop	r16
.endm
//________________________________
.macro	SETB
	push r16
	.if	@0 < 0x20
		sbi	@0,	@1
	.elif @0 < 0x40
		in	r16, @0
		ori	r16, 1<<@1
		out	@0,	r16
	.else
		lds	r16, @0
		ori	r16, 1<<@1
		sts	@0,	r16
	.endif
	pop r16
.endm
//________________________________
.macro	CLRB
	push r16
	.if	@0 < 0x20
		cbi	@0,	@1
	.elif	@0 < 0x40
		in	r16, @0
		andi r16, ~(1<<@1)
		out	@0,	r16
	.else
		lds	r16, @0
		andi r16, ~(1<<@1)
		sts	@0,	r16
	.endif
	pop r16
.endm
//________________________________
.macro SETRB
	sbr @0, (1<<@1)
.endm
//________________________________
.macro CLRRB
	cbr @0, (1<<@1)
.endm
//________________________________
.macro	INVB
	.if	@0 < 0x40
		in	r16, @0
		ldi	r17, 1<<@1
		eor	r16, r17
		out	@0,	r16
	.else
		lds	r16, @0
		ldi	r17, 1<<@1
		eor	r16, r17
		sts	@0,	r16
	.endif
.endm
//________________________________
.macro	STOREB
	.if	@0 < 0x40
		in	r16, @0
		bst	r16, @1
	.else
		lds	r16, @0
		bst	r16, @1
	.endif
.endm
//________________________________
.macro	LOADB
	.if	@0 < 0x40
		in	r16, @0
		bld	r16, @1
		out	@0,	r16
	.else
		lds	r16, @0
		bld	r16, @1
		sts	@0,	r16
	.endif
.endm
//________________________________
.macro	SETBM 
	.if	@0 < 0x20
		sbi	@0,	@1
	.elif	@0 < 0x40
		push R17
		in	R17, @0
		ori	R17, 1<<@1
		out	@0,	R17
		pop	R17
	.else
		push R17
		lds	R17, @0
		ori	R17, 1<<@1
		sts	@0,	R17
		pop	R17
	.endif
.endm
//________________________________
.macro	CLRBM
	.if	@0 < 0x20
		cbi	@0,	@1
	.elif @0 < 0x40
		push R17
		in	R17, @0
		andi R17,	~(1<<@1)
		out	@0,	R17
		pop	R17
	.else
		push R17
		lds	R17, @0
		andi R17, ~(1<<@1)
		sts	@0,	R17
		pop	R17
	.endif
.endm
//________________________________
.macro	INVBM
	.if	@0 < 0x40
		push R16
		push R17
		in	R16, @0
		ldi	R17, 1<<@1
		eor	R17, R16
		out	@0,	R17
		pop	R17
		pop	R16
	.else
		push R16
		push R17
		lds	R16, @0
		ldi	R17, 1<<@1
		eor	R17, R16
		sts	@0,	R17
		pop	R17
		pop	R16
	.endif
.endm
//________________________________
.macro	STOREBM
	push R16
	.if	@0 < 0x40
		in	R16, @0
		bst	R16, @1
	.else
		lds	R16, @0
		bst	R16, @1
	.endif
	pop	R16
.endm
//________________________________
.macro	LOADBM
	push R16
	.if	@0 < 0x40
		in	R16, @0
		bld	R16, @1
		out	@0,	R16
	.else
		lds	R16, @0
		bld	R16, @1
		sts	@0,	R16
	.endif
	pop R16
.endm
//________________________________
.macro	INC8M
	lds	R16, @0
	subi R16, (-1)
	sts	@0,	R16
.endm
//________________________________
.macro	DEC8M
	lds	R16, @0
	subi R16, (1)
	sts	@0,	R16
.endm
//________________________________
.macro	CLR8M
	clr	R16
	sts	@0,	R16
.endm
