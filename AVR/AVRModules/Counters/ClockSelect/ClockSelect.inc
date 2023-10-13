/*
*	@0 - номер счетчика (Counter0 как пример)
*	@1 - претделитель	(Prescaller8 как пример)
*/

.macro ClockSelect
	.if @0 == Counter0
		ClockSelectCounter0 @1
	.elif @0 == Counter1
		ClockSelectCounter1 @1
	.elif @0 == Counter2
		ClockSelectCounter2 @1
	.elif @0 == Counter3
		ClockSelectCounter3 @1
	.elif @0 == Counter4
		ClockSelectCounter4 @1
	.elif @0 == Counter5
		ClockSelectCounter5 @1
	.endif
.endm
