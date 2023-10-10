.macro CountersOffMode
	.if @0 == Counter0
		CountersOffModeCounter0
	.elif @0 == Counter1
		CountersOffModeCounter1
	.elif @0 == Counter2
		CountersOffModeCounter2
	.elif @0 == Counter3
		CountersOffModeCounter3
	.elif @0 == Counter4
		CountersOffModeCounter4
	.elif @0 == Counter5
		CountersOffModeCounter5
	.endif
.endm
