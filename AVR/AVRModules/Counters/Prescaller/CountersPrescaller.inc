/*
*	@0 - ����� �������� (Counter0 ��� ������)
*	@1 - ������������	(Prescaller8 ��� ������)
*/
.macro CountersPrescaller
	.if @0 == Counter0
		CountersPrescallerCounter0 @1
	.elif @0 == Counter1
		CountersPrescallerCounter1 @1
	.elif @0 == Counter2
		CountersPrescallerCounter2 @1
	.elif @0 == Counter3
		CountersPrescallerCounter3 @1
	.elif @0 == Counter4
		CountersPrescallerCounter4 @1
	.elif @0 == Counter5
		CountersPrescallerCounter5 @1
	.endif
.endm
