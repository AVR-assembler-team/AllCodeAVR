/*
*
*	@0	-	номер счетчика (Counter0 как пример)
*	@1	-	какое прерывание используется
*	@2	-	включить или выключить
*/
.macro CountersInterrupt
	.if @0 == Counter0
		CountersInterruptCounter0 @1, @2, @3
	.elif @0 == Counter1
		CountersInterruptCounter1 @1, @2, @3
	.elif @0 == Counter2
		CountersInterruptCounter2 @1, @2, @3
	.elif @0 == Counter3
		CountersInterruptCounter3 @1, @2, @3
	.elif @0 == Counter4
		CountersInterruptCounter4 @1, @2, @3
	.elif @0 == Counter5
		CountersInterruptCounter5 @1, @2, @3
	.endif
.endm

