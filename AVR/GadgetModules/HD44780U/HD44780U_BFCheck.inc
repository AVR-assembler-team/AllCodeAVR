/*
* ������ ������ ��������� ���� ��������� �������
*/
.macro HD44780U_BF_Check
	_call HD44780U_BF_Check_act	; ���������
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires
	HD44780U_BF_Check_act:								; �������� ��������� ����� ���������
		
		// ���� �� ����
		CLRB HD44780U_D0_DDR, HD44780U_D0_bit
		CLRB HD44780U_D1_DDR, HD44780U_D1_bit
		CLRB HD44780U_D2_DDR, HD44780U_D2_bit
		CLRB HD44780U_D3_DDR, HD44780U_D3_bit
		CLRB HD44780U_D4_DDR, HD44780U_D4_bit
		CLRB HD44780U_D5_DDR, HD44780U_D5_bit
		CLRB HD44780U_D6_DDR, HD44780U_D6_bit
		CLRB HD44780U_D7_DDR, HD44780U_D7_bit

		cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ����������� �� ����������
		sbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� + (������)

	HD44780U_Read_bit:
		sbi	HD44780U_E_PORT, HD44780U_E_bit				; �������� ������
		HD44780U_Delay_5mks								; �������� 5 ���
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; ��������� ��������� ���� ��� D7
			rjmp HD44780U_Busy_Flag_End					; ���� ����� ���, �� ���������

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
		HD44780U_Delay_5mks								; �������� 5 ���
		rjmp HD44780U_Read_bit							; ���� ������� ��� ��� D7 �� ������������ � ������

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� ����� (������)
		
		// ���� �� �����
		SETB HD44780U_D0_DDR, HD44780U_D0_bit
		SETB HD44780U_D1_DDR, HD44780U_D1_bit
		SETB HD44780U_D2_DDR, HD44780U_D2_bit
		SETB HD44780U_D3_DDR, HD44780U_D3_bit
		SETB HD44780U_D4_DDR, HD44780U_D4_bit
		SETB HD44780U_D5_DDR, HD44780U_D5_bit
		SETB HD44780U_D6_DDR, HD44780U_D6_bit
		SETB HD44780U_D7_DDR, HD44780U_D7_bit

	ret													; ����� �� ������������
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_BF_Check_act:
		
		// ���� �� ����
		CLRB HD44780U_D4_DDR, HD44780U_D4_bit
		CLRB HD44780U_D5_DDR, HD44780U_D5_bit
		CLRB HD44780U_D6_DDR, HD44780U_D6_bit
		CLRB HD44780U_D7_DDR, HD44780U_D7_bit

		cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ����������� �� ����������
		sbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� + (������)

	HD44780U_Read_bit:
		sbi	HD44780U_E_PORT, HD44780U_E_bit				; �������� ������
		HD44780U_Delay_5mks								; �������� 5 ���
		sbis HD44780U_D7_PIN, HD44780U_D7_bit			; ��������� ��������� ���� ��� D7
			rjmp HD44780U_Busy_Flag_End					; ���� ����� ���, �� ���������

	HD44780U_Busy_Flag_Again:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
		HD44780U_Delay_5mks								; �������� 5 ���
		rjmp HD44780U_Read_bit							; ���� ������� ��� ��� D7 �� ������������ � ������

	HD44780U_Busy_Flag_End:
		cbi	HD44780U_E_PORT, HD44780U_E_bit				; ����������� ������
		cbi HD44780U_RW_PORT, HD44780U_RW_bit			; ������������ RW �� ����� (������)
		
		// ���� �� �����
		SETB HD44780U_D4_DDR, HD44780U_D4_bit
		SETB HD44780U_D5_DDR, HD44780U_D5_bit
		SETB HD44780U_D6_DDR, HD44780U_D6_bit
		SETB HD44780U_D7_DDR, HD44780U_D7_bit

		HD44780U_Delay_4_1ms							; �������� 4,1 ��

	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_BF_Check_act:								; ������������ ��������� ���� ���������
	
		push r16										; ���������� r16 � STACK
		push r17										; ���������� r17 � STACK

		ldi		r16, 0xFA								; ������ ��������� LCD � RW �� +5, � � ���� DB4-DB7 ��������� �� +5 (���������� ������ �� LCD)
		WRITE_REG TWDR, r16								; ���������� � ���� �������
		; 0.0259985
		TWSI_Byte_Transmit								; ���������� TWDR �� ����
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����

		TWSI_STOP

		TWSI_START 										; �������� START (���������� ��� ������)
		; 
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'R'

	HD44780U_BF_Check_act_1:

		READ_REG TWDR, r17								; ������ ���� �� I2C � r17
		sbrc	r17, 7									; ���� ������� ��� ����� 0, �� ���������� ���� ������
			rjmp	HD44780U_BF_Check_act_1				; ��������� �� �����
		
		//TWSI_Byte_Transmit								; ������ �� ��������� �����
		
		TWSI_STOP										; ������ �� ��������� �����
		TWSI_START										; �������� START (���������� ��� ������)
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'W'

		ldi		r16, 0x08								; ��������� ������ ��������� LCD
		WRITE_REG TWDR, r16								; ���������� � ���� �������
		TWSI_Byte_Transmit								; ���������� TWDR �� ����
		TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����


		pop r17											; ����������� r17 �� STACK
		pop r16											; ����������� r16 �� STACK
	ret													; ����� �� ������������
#endif
