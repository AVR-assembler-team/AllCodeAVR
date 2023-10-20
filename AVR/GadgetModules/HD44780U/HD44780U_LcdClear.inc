/*
* ������ ������ ������������ ��� ������� ������� (������� �������� � ��������� 1, 1)
*/
.macro HD44780U_LCD_Clear
	
	push r16						; ���������� r16 � STACK

	ldi	r16, 0x01					; ���������� 1 � r16
	HD44780U_Send_instruction r16	; �������� ����������

	pop r16							; ����������� r16 �� STACK
	HD44780U_Set_Cursor 4, 20
	HD44780U_Write_Symbol ' '

.endm