.macro WeveformGenerationMode
	.if @0 == Counter0
		WeveformGenerationModeCounter0 @1
	.elif @0 == Counter1
		WeveformGenerationModeCounter1 @1
	.elif @0 == Counter2
		WeveformGenerationModeCounter2 @1
	.elif @0 == Counter3
	.elif @0 == Counter4
	.elif @0 == Counter5
	.endif
.endm
