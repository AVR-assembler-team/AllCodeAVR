.macro OneWire_TemperatureDataConvertation

	push r16													; ���������� r16 � STACK
	push r17													; ���������� r17 � STACK
	push r18													; ���������� r18 � STACK
	push zh														; ���������� zh � STACK
	push zl														; ���������� zl � STACK

	_call OneWireTemperatureConversation_act
	
	pop zl														; ����������� zl �� STACK
	pop zh														; ����������� zh �� STACK
	pop r18														; ����������� r18 �� STACK
	pop r17														; ����������� r17 �� STACK
	pop r16														; ����������� r16 �� STACK

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireTemperatureConversation_act:

	READ_REG OneWireFlags, r16							; �������� ������� ������ � r16
	sbrc r16, OneWireDeviceNotDetected					; ��������� ���� ����������� �� ����
		_jump OneWireTemperatureConversation_act_finish	; �������������
	READ_REG OneWireScratchpad + 1, r16					; �������� ������� ���� �����������
	READ_REG OneWireScratchpad, r17						; �������� ������� ���� �����������

	lsl r17												; ����� �����
	rol r16												; ����� �����

	lsl r17												; ����� �����
	rol r16												; ����� �����

	lsl r17												; ����� �����
	rol r16												; ����� �����

	lsl r17												; ����� �����
	rol r16												; ����� �����

	sbrs r16, 7											; ��������� ��� ����� �����������
		_jump IsPlus									; ��������� �� ����

IsMinus:
	SETB OneWireFlags, OneWireNegativeTemperature		; ��������� ���� ������
	com r16												; ������ �������� �������� �������� �����
	com r17												; ������ �������� �������� �������� �����
	_jump Is1											; ������������� ������

IsPlus:
	CLRB OneWireFlags, OneWireNegativeTemperature		; ������� ���� ������

Is1:
	swap r17											; ������ ������� ������� �������� �����
	WRITE_REG OneWireTemperature + 1, r17				; ��������� ��������� ����������� ����� ������� 

DegreesCalc:
	ldi r17, $64										; ���������� � r17 �������� 100
	CLRB OneWireFlags, OneWireOneHundredDegrees			; ������� ���� 100 ��������

loop_100:								
	sub r16, r17										; �������� �� r16 r17
	brmi loop_100_finish								; ���� ��������� -, �� ���������
	SETB OneWireFlags, OneWireOneHundredDegrees			; ������������� ���� 100 ��������
	_jump loop_100										; ������������� �� �����

loop_100_finish:
	add r16, r17										; ��������� � r16 r17
	clr r18												; ������� r18
	ldi r17, $0a										; ���������� � r17 �������� 10

loop_10:
	sub r16, r17										; �������� �� r16 r17
	brmi loop_10_finish									; ���� ��������� -, �� ���������
	inc r18												; ����������� r18 �� 1
	_jump loop_10										; ������������� �� �����
		
loop_10_finish:
	add r16, r17										; ��������� � r16 r17
	swap r16											; ������ ������� r16

	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	WRITE_REG OneWireTemperature, r18					; ��������� ����� �������� ����������� � ������

AfterDotCalc:
	ldi zh, high(TempTable * 2)							; ���������� ������� ���� ������ �����
	ldi zl, low(TempTable * 2)							; ���������� ������� ���� ������ �����
	READ_REG OneWireTemperature + 1, r16				; ��������� ��������� ����� ����� � r16
	add zl, r16											; ��������� r16 � �������� �������� ������ �������
	clr r16												; ������� r16
	adc zh, r16											; ��������� � ��������� r16 � �������� �������� ������ �������

	lpm r16, z											; �������� ���� �� �������
	clr r18												; ������� r18
	ldi r17, $0a										; ���������� � r17 �������� 10

loop_10th:
	sub r16, r17										; �������� �� r16 r17
	brmi loop_10th_finish								; ���� ��������� -, �� ���������
	inc r18												; ����������� r18 �� 1
	_jump loop_10th										; ������������� �� �����
		
loop_10th_finish:
	add r16, r17										; ��������� � r16 r17
	swap r16
	
	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	lsl r16												; ����� �����
	rol r18												; ����� �����
	WRITE_REG OneWireTemperature + 1, r18				; ��������� �������� ����������� ����� ������� � ������

OneWireTemperatureConversation_act_finish:
	
ret

TempTable: .db $00, $06, $0c, $13, $19, $1f, $26, $2c, $32, $38, $3f, $45, $4b, $51, $58, $5e
	// $00 ; .00
	// $06 ; .06
	// $0c ; .13
	// $13 ; .19
	// $19 ; .25
	// $1f ; .31
	// $26 ; .38
	// $2c ; .44
	// $32 ; .50
	// $38 ; .56
	// $3f ; .63
	// $45 ; .69
	// $4b ; .75
	// $51 ; .81
	// $58 ; .88
	// $5e ; .94
		