/*
* ������ ������ ���� �� ������� � ������ ��� �� ���� T
*/

.macro OneWireReadBit
	_call OneWireReadBit_act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
OneWireReadBit_act:
	cli								; ��������� ����������
	SETB OneWire_DDR, OneWire_bit	; ����� �� �����
	CLRB OneWire_PORT, OneWire_bit	; ������ ���� �� 0
	OneWire_DelayA					; �������� �
	CLRB OneWire_DDR, OneWire_bit	; ����� �� ����
	OneWire_DelayE					; �������� �
	sbis OneWire_PIN, OneWire_bit	; ��������� ����� �� +
	clt								; �������� ���� T
	sbic OneWire_PIN, OneWire_bit	; ��������� ����� �� -
	set								; ������������� ���� T
	OneWire_DelayF					; �������� F
	sei								; ��������� ����������
ret
