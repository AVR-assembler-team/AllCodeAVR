
ReadADC:
	ldi r24, $7d			; ADC low    
	ldi r25, $02			; ADC high
ret
Result:
	
	// ����������� � STECK
	push r16
	push r17
	push r18
	push r19
	push r20	
	push r21
	push r22
	push r23
	push r24	; ������� ���� ADC
	push r25	; ������� ���� ADC
	push xh
	push xl
	push yl
	push zh
	push zl

	
	_call ReadADC	; ������ ADC � ���������� r24 � r25
			
	// ���������� ������� ������� �� ����������� ��������� ADC
	Begin:
		// ���������� ������ ������ T0 � �1 � ������ � ��������� �� � ������� ��� ���
		// ���� ���������� �� �������, �� �������� ��� � ������ � ����������� ������
		// ���� � ��� ����������� ��� ������������ �����������, �� ���������� � ������ � ����������� ������
		
		// ����� ����� ������ �������
		ldi zh, high(TempRange * 2)
		ldi zl, low(TempRange * 2)

		// ���������� ������ ������ ������� � ������
		WRITE_REG T0, zl
		WRITE_REG T0 + 1, zh
	
		// ������ ��� ����� �� ������ �������
		lpm r16, z+
		lpm r17, z
		
		// ����� ����� ����� �������
		ldi zh, high((TempRange * 2) + TempRangeMax)
		ldi zl, low((TempRange * 2) + TempRangeMax)

		// ���������� ������ ����� ������� � ������
		WRITE_REG T1, zl
		WRITE_REG T1 + 1, zh

		// ������� ������ �� ADC � ������� ������ �������
		_call Calculation2		
		
		// �������, ��� ��������

		// ���������� � $00 ($00 - ������ ������ ADC ������ ������ ������ �������)
		cpi r16, $00
		// ���� �� ������, �� ���������
		brne NotLess

		// ���� ���-���� ������, �� ���������� � Temperature $00ff � ��������� � ����� ���������
		clr zl
		WRITE_REG Temperature, zl
		ldi zl, $ff
		WRITE_REG Temperature + 1, zl
		_jump Result_end				

	NotLess:
		// ���������� � $02 ($02 - ������ ������ ADC ������ ������ ������ �������)
		cpi r16, $02
		// ���� ������, �� ���������
		breq Maximun

		// ���� ������ ADC ����� ������ ������ �������, �� ���������� � Temperature $0000 � ������� �� ���������
		clr zl
		WRITE_REG Temperature, zl
		WRITE_REG Temperature + 1, zl
		_jump Result_end


	Maximun:
		// ������ ��� ����� �� ����� �������
		lpm r16, z+
		lpm r17, z
		
		// ������� ������ �� ADC � ������� ����� �������
		_call Calculation2

		// ���������� � $02 ($02 - ������ ������ ADC ������ ������ ����� �������)
		cpi r16, $02
		// ���� �� ������, �� ���������
		brne NotMore

		// ���� ������, �� ���������� � Temperature $ff00 � ��������� � ����� ���������
		ldi zl, $ff
		WRITE_REG Temperature, zl
		clr zl
		WRITE_REG Temperature +1, zl
		_jump Result_end
	
	NotMore:
		// ���������� � $00 ($00 - ������ ������ ADC ������ ������ ����� �������)
		cpi r16, $00
		// ���� ���-���� ������, �� ���������
		breq Calculation1
		
		// ���� ������ ADC ����� ������ ����� �������, �� ���������� � Temperature $f000 � ������� �� ���������
		ldi zl, $f0
		WRITE_REG Temperature, zl
		clr zl
		WRITE_REG Temperature + 1, zl
		_jump Result_end


	// ������� ��� ������� � ������� ����� ���� ��������
	Calculation1:	
		// ������������ �������� �� ������� �� ����������� ��������� ADC � ��������� ���������� 
		// ���������� (� 2 �) � ������� ����� ���� �������� ADC
		// ���������� � ������ ����� ������ ������ � ���� ������ ������� � ������� �� �������, �� 
		// ���������� � ������ ����������� �� �������. 
		// ����� ���� ��� ������� ������� ����������, �� ����� �������� ������ � ������� ����� 2 ������� �� �
		
		// ����� ����� ����� �0
		READ_REG T0, r18
		READ_REG T0 + 1, r19

		// ����� ����� ����� �1
		READ_REG T1, r16
		READ_REG T1 + 1, r17	
		
		// ������� ������� ����� �������� �0 � �1
		sub r16, r18
		sbc r17, r19

		// ������� ����� ���������� ����� �������� �0 � �1 ����� ������� ��������� (�������� � ���������� �� 2)
		lsr r17
		ror r16
		lsr r17
		ror r16
		lsl r16
		rol r17

		// ���� ���������� ����� �0 � �1 ����� ���� ������� (������ ������� ���� 0), �� ��������� �� �����
		cpi r16, $00
		breq Calculation3
		
		// ���������� ��������� ���������� ������� �� �0 �� �������� ���������� �� �1 � ���������� � ������ �0
		add r18, r16
		adc r19, r17
		
		// ������ ������ �� ������ ���� � ���������� ���� ����� � Z
		movw zl:zh, r18:r19
		lpm r16, z+
		lpm r17, z
		movw zl:zh, r18:r19
		
		// ������� ������ �� ADC � ������� ����� �������
		_call Calculation2

		// ���������� � $01 ($01 - ������ ������ ADC ����� ������ �� �������)
		cpi r16, $01
		// ���������, ���� ������ ADC ����� ������ �� �������
		breq Calc1Equal
		// // ���������, ���� ������ ADC ������ ������ �� �������
		brlo Calc1Less

	Calc1More:
		// ��� ��� ������ ADC ������ ������ �� �������, �� ������� ����� ����� �0 �� ����� ������ �� �������
		// � ������������ �� �����
		WRITE_REG T0, zl
		WRITE_REG T0 + 1, zh
		_jump Calculation1

	Calc1Less:
		// ��� ��� ������ ADC ������ ������ �� �������, �� ������� ����� ����� �1 �� ����� ������ �� �������
		// � ������������ �� �����
		WRITE_REG T1, zl
		WRITE_REG T1 + 1, zh
		_jump Calculation1

	Calc1Equal:
		// ��� ��� ������ ADC ����� ������ �� �������, �� ���������� ������ ����������� � Temperature
		// � ��������� ������ ���������
		_call TempToTable
		_jump Result_end
		




	// �������� � ��� ����� ������ ��� � �������� � ������� ���
	Calculation3:
		
		// ������ ������� ���� ������ ����� �0
		READ_REG T0, xl
		
		// ������ ������� ���� ������ ������ �������
		ldi yl, low(TempRange * 2)

		// ������� �������� ����� �0 �� ������ ������� (������ �������� ����������� � ��������)
		sub xl, yl
		// ���������� � ������
		WRITE_REG TemtVar, xl
		_call ReadableTemperature

		// ������ ����� ����� �0
		READ_REG T0, zl
		READ_REG T0 + 1, zh 
		// ������ 2 ����� �� ����� �0
		lpm r16, z+
		lpm r17, z
		// ���������� � ������ � Temperature0
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// ������ ����� ����� �1
		READ_REG T1, zl
		READ_REG T1 + 1, zh 
		// ������ 2 ����� �� ����� �0
		lpm r18, z+
		lpm r19, z
		// ���������� � ������ � Temperature1
		WRITE_REG Temperature1, r18
		WRITE_REG Temperature1 + 1, r19

		// �������� �� Temperature1 Temperature0 � ������ ������� ��� � ���� ���������� 2 �������
		sub r18, r16
		sbc r19, r17
		// ����� �� 2 ��� �������
		mov r20, r18
		lsr r18
		sub r20, r18

		// �������� �������� �������������� ������� � ���� 2 �������
		add r16, r18
		clr r19
		adc r17, r19

		// ������� ������ �� ADC � ������� ����� �������
		_call Calculation2

		// ������� ��������� �� �������� ������� �������
		cpi r18, $0a
		// ���� ������ ��������, �� ���������
		brsh Desiatki

		// ���� �� ������, �� ����� ������ ����� �������
		_jump TselieGradysi
	
	// ������ �������� ��������	
	Desiatki:

		// ��������� ������ ADC ����� �� ������ �������������� ������?
		cpi r16, $01
		// ���� ������ ADC ����� ������ �������������� ������
		breq DesiatkiEqual
		// ���� ������ �� ���������
		brlo DesiatkiLess
		
	// �������� ���� ������
	DesiatkiMore:

		// ����������� ����������� � ������ ����������� �� ������
		_call DegInc

		// ������ �� ���������� ������ �������� ������� 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		
		// ��������� ���������� ��� ��������������� �������� �� ���� ������ �� ��������
		add r16, r18
		adc r17, r19

		// ���������� � ����������
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// ����� ���������� ��� �������� ���������� �� 2 
		lsr r20

		// ��������� � ������ �������������� �������
		add r16, r20
		adc r17, r19

		// �������� ������ �������� � ������� r18
		mov r18, r20

		// ��������� �� �����
		_jump DesiatkiPolGradusa

	DesiatkiLess:

		// ������ �� ���������� ������ �������� �������
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		// �������� ���������� ��� �������� ���������� (������ �������� ���� �������)
		sub r16, r20
		sbc r17, r19
		
		// ���������� � ����������
		WRITE_REG Temperature1, r16
		WRITE_REG Temperature1 + 1, r17

		// ������ �� ���������� ������ �������� ������� 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17

		// ����� ���������� ��� �������� ���������� �� 2
		lsr r18

		// ���������� � ������ �������� ������� (������� ������ �������� �������)
		add r16, r18
		adc r17, r19

		// ���������
		_jump DesiatkiPolGradusa

	DesiatkiEqual:

		// ����������� ����������� � ������ ����������� �� ������
		_call DegInc

		// ������� �� ���������
		_jump Result_end
	
	DesiatkiPolGradusa:
		
		// ������� ������ �� ADC � ������� ����� �������
		_call Calculation2

		// ��������� ������ ADC ����� �� ������ �������������� ������?
		cpi r16, $01

		// ��������� ��� ���������
		breq DesiatkiPolGradusaEqual

		// ��������� ���� ������
		brlo DesiatkiGradusaLessHalf

	// �������� ���� ������
	DesiatkiGradusaMoreHalf:
	
		// ���������� ��� ������� � ������
		ldi r20, $05
		WRITE_REG Temperature + 1, r20

		// ������ �� ���������� ������ �������� ������� 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		
		// ���������� �������� �������� �������
		add r16, r18
		adc r17, r19
		
		// ��������� � ����������
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// ���������
		_jump DesiatkiPolGradusaPoDesiatke

	DesiatkiGradusaLessHalf:

		// ������ �� ���������� ������ �������� �������
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		// �������� ������ �������� �������
		sub r16, r18
		sbc r17, r19
		
		// ��������� � ����������
		WRITE_REG Temperature1, r16
		WRITE_REG Temperature1 + 1, r17

		// ������� ������� �������
		ldi r20, $00
		WRITE_REG Temperature + 1, r20

		// ���������
		_jump DesiatkiPolGradusaPoDesiatke
	
	DesiatkiPolGradusaEqual:

		// ���������� ��� ������� � ������
		ldi r20, $05
		WRITE_REG Temperature + 1, r20

		// ������� �� ���������
		_jump Result_end


	DesiatkiPolGradusaPoDesiatke:

		// ����������� ������� ������� �� 1
		_call DesiatkiDegInc

		// ���������� 5 � �������
		ldi r20, $05

		// ������� ������� �� ���������� ��� 0,5 ������� �� 5 ��� �������, ��� ���?
		// � r19 ����� �����, � r18 ������� �� ������� �� 5
		���������� ��� �����. 
		PoDesiatkeCalc:
			inc r19
			sub r18, r20
			brpl PoDesiatkeCalc
			dec r19
			R18 � ����� ����� �������� �� 10 � ����� ������ �� 5
			add r18, r20
			mov r20, r18

		Raschet:

			// ������ �� ���������� ������ �������� ������� 
			READ_REG Temperature0, r16
			READ_REG Temperature0 + 1, r17

			// ���������� � ������� �������
			add r16, r19
			clr r21
			adc r17, r21

			// ��������� �������� ��������, � ���� ��� ����� ��� ������ 10, �� ���������� �������� 0,1 ������� ��� ���
			add r20, r18
			cpi r20, $0a
			brlo Raschet1
			add r16, r19
			clr r21
			adc r17, r21
			mov r20, r18
			
			// ��������� � ����������
			WRITE_REG Temperature0, r16
			WRITE_REG Temperature0 + 1, r17

		Raschet1:

			// ������� ������ �� ADC � ������� ����� �������
			_call Calculation2

			// ��������� ������ ADC ����� �� ������ �������������� ������?
			cpi r16, $01

			// ���������, ���� �����
			breq RaschetEqual

			// ���������, ���� ������
			brlo RaschetLess

			// ��������, ���� ������
			RaschetMore:

				// ����������� ������� ������� �� 1
				_call DesiatkiDegInc

				// ������� �������� �� 10 � ���������� � ��������� �������?
				cpi r16, $0a

				// ���� ��, �� ���������
				breq PlusGradus

				// ����� ��������� �� �����
				_jump Raschet

				PlusGradus:

					// ����������� ����������� �� ������
					_call DegInc

					// ������� ������� �������
					clr r16
					WRITE_REG Temperature + 1, r16

			RaschetLess:
			RaschetEqual:

				// ����������� ���������
				_jump Result_end

Result_end:

	ldi r16, $01
	add r24, r16
	clr r16
	adc r25, r16

	_jump Begin

	pop zl
	pop zh
	pop yl
	pop xl
	pop xh
	pop r25		; ������� ���� ADC
	pop r24		; ������� ���� ADC
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17
	pop r16

ret





//////////////////////////////////////////////////////////////////////////////////
Calculation2:
	// ���������� r16, r17, r24, r25
	// ���������� ��������� ������ � ������� ��������� ������ �������� � �������
	// ��������� ������ ��� ������ ������������ ������������ ��������
	// �� ������ ����� 0, 1 ��� 2 � �������� r16
	// 0 - ������
	// 1 - �����
	// 2 - ������
	cp r17, r25				; ���������� r17 � r25
	breq HighEqual			; ���� �����
	brlo HighOver			; ���� r17 ������
	
	HighLess:
		clr r16
		ret

	HighOver:				; ���� r17 ������
		ldi r16, $02
		ret

	HighEqual:
		cp r16, r24
		breq LowEqual
		brlo LowOver

	LowLess:
		clr r16
		ret
	
	LowOver:
		ldi r16, $02
		ret

	LowEqual:
		ldi r16, $01
		ret
//////////////////////////////////////////////////////////
TselieGradysi:
	
		cpi r16, $01
		breq TselieGradysiEqual
		brlo TselieGradysiLess
		

	TselieGradysiMore:
		_call DegInc
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		sub r16, r20						; �������� ��� ��������
		sbc r17, r19						; �������� � ���������

		lsr r20								; �������� ������ �� 1 (����� �� 2 ��� �������)

		add r16, r20						; ��������� ��� ��������
		adc r17, r19						; ��������� � ���������

		_jump TselieGradysiPolGradusa

	TselieGradysiLess:
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		lsr r18								; �������� ������ �� 1 (����� �� 2 ��� �������)
		add r16, r18						; ��������� ��� ��������
		clr r19								; ������� r18
		adc r17, r19						; ��������� � ���������
		_jump TselieGradysiPolGradusa

	TselieGradysiEqual:
		_call DegInc
		_jump Result_end
	
	TselieGradysiPolGradusa:
		// ���������� ��������� �������� ��� ���������� ��������� ������������ �������� � �������
		_call Calculation2
	
		cpi r16, $01
		brlo TselieGradysiPolGradusaLess

	TselieGradysiPolGradusaEqualMore:
		_call DegInc
		_jump Result_end
		
	TselieGradysiPolGradusaLess:
		_jump Result_end
///////////////////////////////////////////////
DegInc:
	// ������ ������ �� 1 ������
	READ_REG TemtVar, r16
	inc r16
	WRITE_REG TemtVar, r16	; ������� ��� ������� � ����������
	_call ReadableTemperature
ret
///////////////////////////////////////////////
DesiatkiDegDec:
	READ_REG Temperature + 1, r16
	dec r16
	WRITE_REG Temperature + 1, r16	; ������� ��� ������� � ����������
ret
///////////////////////////////////////////////
DesiatkiDegInc:
	READ_REG Temperature + 1, r16
	inc r16
	WRITE_REG Temperature + 1, r16	; ������� ��� ������� � ����������
ret
///////////////////////////////////////////////
ReadableTemperature:
	READ_REG TemtVar, xl
	clr xh
	ldi r22, $0a
ReadableTemperatureLoop:
	inc xh
	sub xl, r22
	brpl ReadableTemperatureLoop
	dec xh
	add xl, r22
	swap xh
	or xh, xl
	WRITE_REG Temperature, xh
ret