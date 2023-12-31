
HD44780U_Initialization:

	push r25

	// ������������� ��� ���� �������� �������� �� �����
	SETB HD44780U_D4_DDR, HD44780U_D4_bit	
	SETB HD44780U_D5_DDR, HD44780U_D5_bit	
	SETB HD44780U_D6_DDR, HD44780U_D6_bit	
	SETB HD44780U_D7_DDR, HD44780U_D7_bit	
	SETB HD44780U_RS_DDR, HD44780U_RS_bit	
	SETB HD44780U_RW_DDR, HD44780U_RW_bit	
	SETB HD44780U_E_DDR, HD44780U_E_bit
												  
	HD44780U_Delay_15ms									; ���� ����� 15 ��
	ldi	r25, $30										; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; ������������� �� ����������
	_call HD44780U_Command1								; r25

	HD44780U_Delay_4_1ms								; ���� ����� 4,1 ��
	ldi	r25, $30										; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; ������������� �� ����������
	_call HD44780U_Command1								; r25

	HD44780U_Delay_100mks								; ���� ����� 100���
	ldi	r25, $30										; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; ������������� �� ����������
	_call HD44780U_Command1								; r25

	_call HD44780U_BF_Check								; r25 ��������� ��������� ����� ���������
												  
	ldi	r25, HD44780U_LCD_Function_Set					; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit				; ������������� �� ����������
	_call HD44780U_Command1								; r25

	_call HD44780U_BF_Check								; r25 ��������� ��������� ����� ���������
																		  
	READ_REG HD44780U_Function_Set_byte, r25			; ������ Function Set � r25
	_call HD44780U_Send_instruction						; r25 ����������� ����������
		
	READ_REG HD44780U_Display_On_Off_Control_byte, r25	; ������ Display On/Off Control � r16
	_call HD44780U_Send_instruction						; r25 ����������� ����������
																		  
	ldi r25, HD44780U_LCDClear							; ����������� ���������� Display clear
	_call HD44780U_Send_instruction						; r25 ����������� ����������
																		  
	READ_REG HD44780U_Entry_Mode_Set_byte, r25			; ������ Entry Mode Set � r16
	_call HD44780U_Send_instruction						; r25 ����������� ����������
	HD44780U_Delay_15ms									; ���� ����� 15 ��

	READ_REG HD44780U_Cursor_or_display_shift, r25		; ������ Cursor or display shift � r16
	_call HD44780U_Send_instruction						; r25 ����������� ����������

	pop r25

ret
