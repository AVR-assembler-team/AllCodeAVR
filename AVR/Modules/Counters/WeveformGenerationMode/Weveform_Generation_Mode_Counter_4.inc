.macro WeveformGenerationModeCounter4
	.if @0 == 0
		CLRB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define NormalMode
	.elif @0 == 1
		SETB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 2
		CLRB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 3
		SETB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 4
		CLRB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define CTCMode
	.elif @0 == 5
		SETB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define FastPWMMode
	.elif @0 == 6
		CLRB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define FastPWMMode
	.elif @0 == 7
		SETB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		CLRB TCCR4B, WGM43
		#define FastPWMMode
	.elif @0 == 8
		CLRB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 9
		SETB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 10
		CLRB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 11
		SETB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		CLRB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define PWMPhaseCorrectMode
	.elif @0 == 12
		CLRB TCCR4A, WGM40
		CLRB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define CTCMode
	.elif @0 == 13
		.error "This Mode Number is reserved for this controller!"
	.elif @0 == 14
		CLRB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define FastPWMMode
	.elif @0 == 15
		SETB TCCR4A, WGM40
		SETB TCCR4A, WGM41
		SETB TCCR4B, WGM42
		SETB TCCR4B, WGM43
		#define FastPWMMode
	.else
		.error "This Mode Number is not supporting by this controller!"
	.endif
.endm
