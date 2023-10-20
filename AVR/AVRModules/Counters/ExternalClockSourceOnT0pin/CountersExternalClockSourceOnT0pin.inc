.macro CountersExternalClockSourceOnT0pin
	.if @0 == Counter0
		CountersExternalClockSourceOnT0pinCounter0 @1
	.elif @0 == Counter1
		CountersExternalClockSourceOnT0pinCounter1 @1
	.elif @0 == Counter2
		CountersExternalClockSourceOnT0pinCounter2 @1
	.elif @0 == Counter3
		CountersExternalClockSourceOnT0pinCounter3 @1
	.elif @0 == Counter4
		CountersExternalClockSourceOnT0pinCounter4 @1
	.elif @0 == Counter5
		CountersExternalClockSourceOnT0pinCounter5 @1
	.endif
.endm
