Button0:
	READ_REG PINB, r16
	sbrc r16, 2
		_jump CommandCreateAndS
		_jump CommandCreateAnd
ret

CommandCreateAndS:
ret
CommandCreateAnd:
ret