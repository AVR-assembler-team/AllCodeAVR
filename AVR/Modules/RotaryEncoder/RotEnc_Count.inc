.macro RotaryEncoderCount
	_call CountEncoder
.endm

CountEncoder:
	
	push r16

	sbis Encoder_CLK_PIN, Encoder_CLK_bit
		_jump Encoder_CLK_bit_negative
		_jump Encoder_CLK_bit_positive

		Encoder_CLK_bit_positive:
			sbis Encoder_DT_PIN, Encoder_DT_bit
				_jump Increment
				_jump Decrement
		Encoder_CLK_bit_negative:
			sbis Encoder_DT_PIN, Encoder_DT_bit
				_jump Decrement
				_jump Increment

	Increment:
		READ_REG RotaryEncoder_byte, r16
		cpi r16, $ff
		brne Plus
		_jump CountEncoderCompete
		Plus:
			inc r16
			WRITE_REG RotaryEncoder_byte, r16
			_jump CountEncoderCompete

	Decrement:
		READ_REG RotaryEncoder_byte, r16
		cpi r16, $00
		brne Minus
		_jump CountEncoderCompete
		Minus:
			dec r16
			WRITE_REG RotaryEncoder_byte, r16
	
	CountEncoderCompete:
	pop r16

ret