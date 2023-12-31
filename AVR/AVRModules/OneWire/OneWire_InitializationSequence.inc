/*
* ��� �������� ����������� ������� �� ���� 1Wire 
* �� ������ ��������� ����� �������� �� ���� �����������
*/

.macro OneWire_InitializationSequence
	_call OneWire_InitializationSequence_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWire_InitializationSequence_act:
	cli											; ��������� ����������
	SETB OneWire_DDR, OneWire_bit				; ����� �� �����
	CLRB OneWire_PORT, OneWire_bit				; ������ ���� �� 0
	OneWire_DelayH								; �������� �
	CLRB OneWire_DDR, OneWire_bit				; ����� �� ����
	OneWire_DelayI								; �������� �
	
	sbic OneWire_PIN, OneWire_bit				; ��������� ����� �� -
	_jump OneWireDeviceNotDetect				; ��������� ���� �� ���� + (��������� ���)

OneWireDeviceDetect:	
	CLRB OneWireFlags, OneWireDeviceNotDetected	; ������� ���� ���������� �� ����
	_jump OneWireInitializationSequenceFinish	; ���������

OneWireDeviceNotDetect:							; �����, ����� ���������� �� ����������
	SETB OneWireFlags, OneWireDeviceNotDetected	; ��������� ���� ���������� �� ����
	_call DeviceNotDetected						; ���������� ������� ����� ���������� �� ����������

OneWireInitializationSequenceFinish:			; �����
	OneWire_DelayJ								; �������� J
	sei											; ��������� ����������
ret
