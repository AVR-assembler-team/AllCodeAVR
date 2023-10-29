/*
* ���������� ������� r25
*/
HD44780U_Initialization:
	// ������������� ��� ���� �������� �������� �� �����
	READ_REG HD44780U_D0_DDR, r25
	SETRB r25, HD44780U_D0_bit
	WRITE_REG HD44780U_D0_DDR, r25

	READ_REG HD44780U_D1_DDR, r25
	SETRB r25, HD44780U_D1_bit
	WRITE_REG HD44780U_D1_DDR, r25
	
	READ_REG HD44780U_D2_DDR, r25
	SETRB r25, HD44780U_D2_bit
	WRITE_REG HD44780U_D2_DDR, r25
	
	READ_REG HD44780U_D3_DDR, r25
	SETRB r25, HD44780U_D3_bit
	WRITE_REG HD44780U_D3_DDR, r25
	
	READ_REG HD44780U_D4_DDR, r25
	SETRB r25, HD44780U_D4_bit
	WRITE_REG HD44780U_D4_DDR, r25
	
	READ_REG HD44780U_D5_DDR, r25
	SETRB r25, HD44780U_D5_bit
	WRITE_REG HD44780U_D5_DDR, r25
	
	READ_REG HD44780U_D6_DDR, r25
	SETRB r25, HD44780U_D6_bit
	WRITE_REG HD44780U_D6_DDR, r25
	
	READ_REG HD44780U_D7_DDR, r25
	SETRB r25, HD44780U_D7_bit
	WRITE_REG HD44780U_D7_DDR, r25
	
	READ_REG HD44780U_RS_DDR, r25
	SETRB r25, HD44780U_RS_bit
	WRITE_REG HD44780U_RS_DDR, r25
	
	READ_REG HD44780U_RW_DDR, r25
	SETRB r25, HD44780U_RW_bit
	WRITE_REG HD44780U_RW_DDR, r25
	
	READ_REG HD44780U_E_DDR, r25
	SETRB r25, HD44780U_E_bit
	WRITE_REG HD44780U_E_DDR, r25
	
	HD44780U_Delay_15ms								; ���� ����� 15 ��
	ldi	r25, $30									; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ������������� �� ����������
	_call HD44780U_Command							; HD44780U_SendInstruction.inc
	
	HD44780U_Delay_4_1ms							; ���� ����� 4,1 ��
	ldi	r25, $30									; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ������������� �� ����������
	_call HD44780U_Command							; HD44780U_SendInstruction.inc
	
	HD44780U_Delay_100mks							; ���� ����� 100���
	ldi	r25, $30									; ������������� ����������
	cbi HD44780U_RS_PORT, HD44780U_RS_bit			; ������������� �� ����������
	_call HD44780U_Command							; HD44780U_SendInstruction.inc

	_call HD44780U_BF_Check								; ��������� ��������� ����� ���������

	READ_REG HD44780U_Function_Set_byte, r25				; ������ Function Set � r16
	_call HD44780U_Send_instruction					; ����������� ����������

	READ_REG HD44780U_Display_On_Off_Control_byte, r25	; ������ Display On/Off Control � r16
	_call HD44780U_Send_instruction					; ����������� ����������
												  
	ldi r25, HD44780U_LCDClear						; ����������� ���������� Display clear
	_call HD44780U_Send_instruction					; ����������� ����������

	READ_REG HD44780U_Entry_Mode_Set_byte, r25			; ������ Entry Mode Set � r16
	_call HD44780U_Send_instruction					; ����������� ����������

	READ_REG HD44780U_Cursor_or_display_shift, r25		; ������ Cursor or display shift � r16
	_call HD44780U_Send_instruction					; ����������� ����������
ret