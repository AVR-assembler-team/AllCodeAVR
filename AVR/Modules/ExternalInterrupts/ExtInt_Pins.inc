
.macro PinsSet
	.if @0 == enabled
		SETB @1, @2
		SETB @3, @4
	.elif @0 == disabled
		CLRB @1, @2
		CLRB @3, @4
	.else
		.error "You have to choose 'enabled' or 'disabled'"
	.endif
.endm

.macro ExtInterPins
	.if ctlr == 8 ||ctlr == 16 || ctlr == 32 || ctlr == 64 || ctlr == 128 || ctlr == 8515 || ctlr == 8535
		.error "Any External Interrupt pins are not available!"
	.elif ctlr == 162
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, GICR, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, GICR, PCIE1
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 164 || ctlr == 324 || ctlr == 644 || ctlr == 1284
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT16
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT17
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT18
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT19
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT20
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT21
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT22
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT23
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT24
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT25
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT26
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT27
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT28
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT29
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT30
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.elif @0 == PCINT31
			PinsSet @1, PCMSK3, @0, PCICR, PCIE3
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 165 || ctlr == 169
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 325 || ctlr == 645 || ctlr == 329 || ctlr == 649
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 3250 || ctlr == 6450 || ctlr == 3290 || ctlr == 6490
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, EIMSK, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, EIMSK, PCIE1
		.elif @0 == PCINT16
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT17
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT18
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT19
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT20
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT21
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT22
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT23
			PinsSet @1, PCMSK2, @0, EIMSK, PCIE2
		.elif @0 == PCINT24
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT25
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT26
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT27
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT28
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT29
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT30
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.elif @0 == PCINT31
			PinsSet @1, PCMSK3, @0, EIMSK, PCIE3
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 328 || ctlr == 48 || ctlr == 88 || ctlr == 168
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT16
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT17
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT18
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT19
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT20
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT21
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT22
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT23
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.else
			.error "External Interrupt pin not available!"
		.endif
	.elif ctlr == 640 || ctlr == 1280 || ctlr == 1281 || ctlr == 2560 || ctlr == 2561
		.if @0 == PCINT0
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT1
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT2
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT3
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT4
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT5
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT6
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT7
			PinsSet @1, PCMSK0, @0, PCICR, PCIE0
		.elif @0 == PCINT8
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT9
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT10
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT11
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT12
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT13
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT14
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT15
			PinsSet @1, PCMSK1, @0, PCICR, PCIE1
		.elif @0 == PCINT16
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT17
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT18
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT19
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT20
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT21
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT22
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.elif @0 == PCINT23
			PinsSet @1, PCMSK2, @0, PCICR, PCIE2
		.else
			.error "External Interrupt pin not available!"
		.endif
	.endif
.endm