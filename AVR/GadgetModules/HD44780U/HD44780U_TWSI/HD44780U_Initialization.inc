
HD44780U_Initialization:

	push r25

	HD44780U_Delay_15ms										; ���� 15-40 ms
	TWSI_START												; �������� START (���������� ��� ������)
	TWSI_SLA r24, 'W'

	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; ��������� ������ ���������� �������������	
	_call HD44780U_Send_instr_byte_high		 				; �������� ������� ������� ����� ����������

	HD44780U_Delay_4_1ms									; ���� ������ 4,1 ms

	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; ��������� ������ ���������� �������������
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������

	HD44780U_Delay_100mks									; ���� ������ 100 mks
	
	ldi	r25, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)	; ��������� ������ ���������� �������������
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	
	ldi	r25, (1<<HD44780U_LCD_D5)							; ��������� ��������� ���������� �������������
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������

	_call HD44780U_BF_Check									; �������� ��������� LCD

	READ_REG HD44780U_Function_Set_byte, r25				; ������ Function Set � r25
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	_call HD44780U_Send_instr_byte_low						; �������� ������� ������� ����� ����������
	_call HD44780U_BF_Check									; �������� ��������� LCD

	READ_REG HD44780U_Display_On_Off_Control_byte, r25		; ������ Display On/Off Control � r16
		
	HD44780U_Delay_100mks									; ���� ������ 100 mks
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	_call HD44780U_Send_instr_byte_low						; �������� ������� ������� ����� ����������
	_call HD44780U_BF_Check									; �������� ��������� LCD

	ldi	r25, HD44780U_LCDClear								; LCD_Clear
	HD44780U_Delay_100mks									; ���� ������ 100 mks
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	_call HD44780U_Send_instr_byte_low						; �������� ������� ������� ����� ����������
	_call HD44780U_BF_Check									; �������� ��������� LCD

	READ_REG HD44780U_Entry_Mode_Set_byte, r25				; ������ Entry Mode Set � r25
	HD44780U_Delay_100mks									; ���� ������ 100 mks
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	_call HD44780U_Send_instr_byte_low						; �������� ������� ������� ����� ����������

	READ_REG HD44780U_Cursor_or_display_shift, r25			; ������ Cursor or display shift � r16
	_call HD44780U_Send_instr_byte_high						; �������� ������� ������� ����� ����������
	_call HD44780U_Send_instr_byte_low						; �������� ������� ������� ����� ����������

	TWSI_STOP												; �������� ������� STOP

	pop r25

ret															; ����� �� ������������
