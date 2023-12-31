/*
* ������ ������ ������������ ��� ���������� ������� ��������� �������
*/

.macro HD44780U_LCD_LED

	#if defined HD44780U_8_Wires || HD44780U_4_Wires

		.if @0 == On
			SETB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.elif @0 == Off
			CLRB HD44780U_LIGHT_PORT, HD44780U_LIGHT_bit
		.endif

	#elif defined HD44780U_TWSI

		push r25
		push r24

		ldi r24, @1

		TWSI_START										; �������� START (���������� ��� ������)
		TWSI_SLA r24, 'W'						; 
	
		.if @0 == On
			ldi r25, (1<<HD44780U_LCD_LIGHT)			; ������������� � r25 ��� HD44780U_LCD_LIGHT � 1
		.elif @0 == Off
			clr r25										; ������� r25
		.endif
		
		WRITE_REG TWDR, r25								; ���������� � ���� �������
		TWSI_Byte_Transmit								; ���������� TWDR �� ����
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

		TWSI_STOP										; 

		pop r24
		pop r25

	#endif


.endm
