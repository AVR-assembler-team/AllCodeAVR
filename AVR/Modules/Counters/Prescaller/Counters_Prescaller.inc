/*
*	@0 - номер счетчика (Counter0 как пример)
*	@1 - претделитель	(Prescaller8 как пример)
*/

.macro CountersPrescaller
	.if @0 == Counter0
		TimersPrescallerCounter0 @1
	.elif @0 == Counter1
		TimersPrescallerCounter1 @1
	.elif @0 == Counter2
		TimersPrescallerCounter2 @1
	.elif @0 == Counter3
		TimersPrescallerCounter3 @1
	.elif @0 == Counter4
		TimersPrescallerCounter4 @1
	.elif @0 == Counter5
		TimersPrescallerCounter5 @1
	.endif
.endm
