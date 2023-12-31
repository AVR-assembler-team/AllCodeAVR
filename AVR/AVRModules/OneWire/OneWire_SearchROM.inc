/*
* ��������� ���� �������� - OneWireSearchROMCommand ��� OneWireAlarmSearchCommand
* ����� ������� ���������� ROM ��� ALARM �������� �� ����� ROMCodeNormal ��� ROMCodeAlarm
*/

.macro OneWireROMSearching
	push r20											; ���������� r20 � STACK
	ldi r20, @0
	_call OneWireROMSearching_act
	pop r20												; ����������� r20 �� STACK
.endm 
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireROMSearching_act:
	
	push zh												; ���������� zh � STACK
	push zl												; ���������� zl � STACK
	push r16											; ���������� r16 � STACK
	push r17											; ���������� r17 � STACK
	push r18											; ���������� r18 � STACK

	WRITE_BYTE OneWireFlags, $00						; �������� ���������� ROM ������
	
OneWireMainLoop:
	READ_REG OneWireFlags, r16						; �������� ������� ������ � r16
	sbrc r16, OneWireDeviceNotDetected				; ��������� ���� ����������� �� ����
		_jump OneWireROMSearching_act_fihish	; ����������� �����
	
	cpi r20, OneWireSearchROMCommand
	brne AlarmSearchROMString
	ldi zh, high(OneWireROMCode)			; �������� ������� ���� ������ OneWireROMCode
	ldi zl, low(OneWireROMCode)				; �������� ������� ���� ������ OneWireROMCode
	_jump DevicesIs

AlarmSearchROMString:
	ldi zh, high(OneWireAlarmROMCode)		; �������� ������� ���� ������ OneWireAlarmROMCode
	ldi zl, low(OneWireAlarmROMCode)		; �������� ������� ���� ������ OneWireAlarmROMCode

DevicesIs:
	// ��������� �������� ��� ������� ��� ���
	READ_REG OneWireFlags, r16
	sbrc r16, OneWireLastDevice
		_jump OneWireROMSearching_act_fihish	; ��������� ���� ������

	WRITE_BYTE OneWireZeroFork, $ff					; ����� 255 � ����������
	WRITE_BYTE OneWireStep, $00						; �������� ����������

	cpi r20, OneWireSearchROMCommand
	brne AlarmSearch
	OneWireSendCommand OneWireSearchROMCommand		; ����������� ������ �����
	_jump TwoBitsRead

AlarmSearch:
	OneWireSendCommand OneWireAlarmSearchCommand

TwoBitsRead:
	OneWireReadBit							; ������ ������ ���
	READ_REG SREG, r16						; ������� ���� �
	READ_REG OneWireFlags, r17				; ��������� ���� ������ ������ ROM
	sbrs r16, 6
		cbr r17, (1<<OneWireSlaveBit)		; ������� ���� ������� ����
	sbrc r16, 6
		sbr r17, (1<<OneWireSlaveBit)		; ������������� ���� ������� ����
	WRITE_REG OneWireFlags, r17				; ���������� ���� ������ � ������
	OneWireReadBit							; ������ ������ ��� � ��������� ��� � SREG T

TwoBitsMatch:
	// ���������� ��� ���� � ���������
	READ_REG SREG, r16						; ������� ���� �
	READ_REG OneWireFlags, r17				; ��������� ���� ������ ������ ROM
	// ��������� ��������� ���������� 2-� �����
	sbrc r17, OneWireSlaveBit				; ��������� ��������� �����
		_jump OneWireSlaveBit1				; ��������� ���� ������

OneWireSlaveBit0:
	sbrc r16, 6								; ��������� ��������� ����� �
		_jump BitsNotAqual					; ��������� ���� ������
		_jump BitsAqual						; ��������� ���� ������

OneWireSlaveBit1:
	sbrc r16, 6
		_jump BitsAqual						; ��������� ���� ������
		_jump BitsNotAqual					; ��������� ���� ������

BitsAqual:
	READ_REG OneWireFlags, r17				; ��������� ���� ������ ������ ROM
	sbrc r17, OneWireSlaveBit				; ���� SlaveBit ����� 0, �� ���������� ���� ������
		_jump OneWire_SearchROMError		; ��������� ���� ������

StepMatchLastFork1:
	READ_REG OneWireStep, r16				; ������ Step
	READ_REG OneWireLastFork, r17			; ������ LastFork
	cp r16, r17								; ���������� Step � LastFork
	brne StepMatchLastFork2					; ���� �� �����, �� ���������

MasterBitSet1:
	SETB OneWireFlags, OneWireMasterBit		; ������������� MasterBit � 1
	_jump ROMVarAddBit						; �������������

StepMatchLastFork2:
	cp r16, r17								; ���������� r16 � r17
	brlo MasterBitSetLastROMBit				; ���� ������ �� ���������
	CLRB OneWireFlags, OneWireMasterBit		; ������������� MasterBit � 0
	_jump MasterBitCheck					; �������������

MasterBitSetLastROMBit:
	READ_REG OneWireFlags, r16				; �������� ���� ������ ROM
	READ_REG OneWireROMVar, r17				; �������� ���������� ROM
	sbrs r17, 7		
		cbr r16, (1<<OneWireMasterBit)		; ������� ������ ���
	sbrc r17, 7
		sbr r16, (1<<OneWireMasterBit)		; ������������� ������ ���
	WRITE_REG OneWireFlags, r16				; ���������� ��� ������ ROM � ������

MasterBitCheck:
	READ_REG OneWireFlags, r17				; �������� ���� ������ ROM
	READ_REG OneWireStep, r16				; �������� ���� �����
	sbrs r17, OneWireMasterBit				; ���� VasterBit ����� �������, �� ���������� ��������� ������
		WRITE_REG OneWireZeroFork, r16		; ���������� ������� � ������
	_jump ROMVarAddBit						; �������������

// ���� �� �����
BitsNotAqual:
	// ������������� MasterBit ����� �� ��� ��� SlaveBit
	READ_REG OneWireFlags, r17						; ��������� ���� ������ ������ ROM
	sbrs r17, OneWireSlaveBit
		cbr r17, (1<<OneWireMasterBit)
	sbrc r17, OneWireSlaveBit
		sbr r17, (1<<OneWireMasterBit)
	WRITE_REG OneWireFlags, r17						; ���������� ���� ������ � ������
		
// ���������� ��� � ���� ��� ������ � ������
ROMVarAddBit:
	READ_REG OneWireFlags, r17						; ��������� ���� ������ ������ ROM
	READ_REG OneWireROMVar, r16						; �������� ���������� ����� ROM � r16
	lsr r16											; �������� r16 ������ ��� ������ �������� ����
	// ��������� MasteBit � ���������� ����� ROM
	sbrs r17, OneWireMasterBit
		cbr r16, (1<<7)
	sbrc r17, OneWireMasterBit
		sbr r16, (1<<7)
	inc r17									; ����������� ���������� �������
	WRITE_REG OneWireROMVar, r16			; ���������� r16 � ���������� ����� ROM
	WRITE_REG OneWireFlags, r17				; ��������� ��������� ����
	// ��������� ���������� �� ����
	mov r18, r17							; �������� r17 � r18
	andi r18, $0f							; �������� ������� �������
	cpi r18, $08							; ���������� � 8
	brne MasterBitSending					; ���� �� �����, �� ���������
	st z+, r16								; ���������� � ������ � ����-�����������
	andi r17, $f0							; �������� ������� �������
	WRITE_REG OneWireFlags, r17				; ��������� ��������� ����

MasterBitSending:
	READ_REG OneWireFlags, r17				; ��������� ���� ������ ������ ROM
	// �������� MasterBit � ����
	sbrs r17, OneWireMasterBit
		OneWireWriteBit 0
	sbrc r17, OneWireMasterBit
		OneWireWriteBit 1

IncreaseStep:
	READ_REG OneWireStep, r17				; ������ ���� � ����������� �����
	inc r17									; ����������� r17 �� 1
	WRITE_REG OneWireStep, r17				; ���������� � ������

StepCheck:
	READ_REG OneWireStep, r17				; ������ ���� � ����������� �����
	cpi r17, 64								; ���������� ��� � 64
	brsh OneWireStepLoopContinue			; ��������� ���� ����� ��� ������
	// ���� ������, �� ������������ ��� ������ ��������� ���
	_jump TwoBitsRead						; �������������

OneWireStepLoopContinue:
	READ_REG OneWireZeroFork, r16			; �������� ���� �� ������
	WRITE_REG OneWireLastFork, r16			; ���������� ���� � ������
	cpi r16, $ff							; ���������� R16 � 255
	brne CheckCRC							; ��������� ���� �� �����
	SETB OneWireFlags, OneWireLastDevice	; ������������� ���� � �������� ������

CheckCRC:
	OneWireCRCCheck	8						; ��������� �������� CRC
	_call OneWire_ROM
	_jump OneWireMainLoop					; �������������

OneWireROMSearching_act_fihish:

	pop r18									; ����������� r18 �� STACK
	pop r17									; ����������� r17 �� STACK
	pop r16									; ����������� r16 �� STACK
	pop zl									; ����������� zl �� STACK
	pop zh									; ����������� zh �� STACK

ret

OneWire_SearchROMError:
	_call ReadROMError						; ��������� ���� ������
	_jump OneWireROMSearching_act_fihish

OneWire_ROM:
	cpi r20, OneWireSearchROMCommand		; ������,��� ���� Alarm ��� Normal ROM ����
	brne OneWire_ROMAlarm					; ���� Alarm, �� ��������� � OneWire_ROMAlarm
	_call ROMCodeNormal						; ��������� (��������� � OneWire_config.inc)
	ret
OneWire_ROMAlarm:
	_call ROMCodeAlarm						; ��������� (��������� � OneWire_config.inc)
	ret
