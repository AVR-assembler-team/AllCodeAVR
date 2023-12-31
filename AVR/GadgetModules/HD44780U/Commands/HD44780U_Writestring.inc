/*
* ������ ������ ������������ ��� ������ �� ������� ������ �� ���������� ������
* �� �������� ������ �������� �������� � ������������ � ASCII
*/
.macro HD44780U_Write_cseg_String
	
	push zh
	push zl
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif

	ldi	zh, high(@0*2)						; ���������� ������� ���� ������ @0 � zh
	ldi	zl, low(@0*2)						; ���������� ������� ���� ������ @0 � zl

	_call HD44780U_Write_cseg_String_act	; ���������

	pop r24
	pop zl
	pop zh

.endm
//------------------------------------------------------------------------------------
.macro HD44780U_Write_dseg_String
	
	push zh
	push zl
	push r24

	#ifdef HD44780U_TWSI
		ldi r24, @1
	#endif
	
	ldi	zh, high(@0)						; ���������� ������� ���� ������ @0 � zh
	ldi	zl, low(@0)							; ���������� ������� ���� ������ @0 � zl

	_call HD44780U_Write_dseg_String_act	; ���������

	pop r24
	pop zl
	pop zh

.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
HD44780U_Write_cseg_String_act:

	push r22
	push r25

	lpm	r22, z+									; ��������� ���� �� z � ����-����������� � r22

	Typing_cseg_String:
		lpm	r25, z+								; ��������� ���� �� z � ����-����������� � r25
		_call HD44780U_Send_data				; r23, r24, r25 �������� ������
		_call HD44780U_Address_DDRAM_Increment	; r23, r24, r25  ��������� �� ��������� ������
		dec	r22									; ��������� r22 �� 1
		brne Typing_cseg_String					; ���� �� ����� 0, �� ���������

	pop r25
	pop r22

ret												; ����� �� ������������
//------------------------------------------------------------------------------------
HD44780U_Write_dseg_String_act:

	push r22
	push r25

	ld	r22, z+									; ��������� ���� �� z � ����-����������� � r22

	Typing_dseg_String:
		ld	r25, z+								; ��������� ���� �� z � ����-����������� � r25
		_call HD44780U_Send_data				; r23, r24, r25 �������� ������
		_call HD44780U_Address_DDRAM_Increment	; r23, r24, r25 ��������� �� ��������� ������
		dec	r22									; ��������� r22 �� 1
		brne Typing_dseg_String					; ���� �� ����� 0, �� ���������

	pop r25
	pop r22

ret												; ����� �� ������������
