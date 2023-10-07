.macro CompareOutputModeCounter0
	.if ctrl == 8
		.error "Compare Output Mode is not supporting by counter 0 of this controller!"
	.elif ctrl == 2560
	.endif
.endm
