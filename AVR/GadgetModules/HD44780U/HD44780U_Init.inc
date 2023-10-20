/*
* ������������� �������
*/
.macro HD44780U_init
	HD44780U_Function_set
	HD44780U_Display_on_off_control
	HD44780U_Entry_mode_set
	HD44780U_Cursor_Display_shift
	.equ TWSI_Address = HD44780U_SLA_
	_call HD44780U_init_Act
.endm
//____________________________________________________________________________________
//____________________________________________________________________________________
#ifdef HD44780U_8_Wires				; ����������� ���������������� �� 8-�� �����
	HD44780U_init_Act:
		SETB HD44780U_D0_DDR, HD44780U_D0_bit			; ������������� ��� ���� �������� �������� �� �����
		SETB HD44780U_D1_DDR, HD44780U_D1_bit					  
		SETB HD44780U_D2_DDR, HD44780U_D2_bit					  
		SETB HD44780U_D3_DDR, HD44780U_D3_bit					  
		SETB HD44780U_D4_DDR, HD44780U_D4_bit					  
		SETB HD44780U_D5_DDR, HD44780U_D5_bit					  
		SETB HD44780U_D6_DDR, HD44780U_D6_bit					  
		SETB HD44780U_D7_DDR, HD44780U_D7_bit					 							
		SETB HD44780U_RS_DDR, HD44780U_RS_bit					  
		SETB HD44780U_RW_DDR, HD44780U_RW_bit					  
		SETB HD44780U_E_DDR, HD44780U_E_bit					  
												  
		HD44780U_Delay_15ms								; ���� ����� 15 ��
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_Delay_4_1ms							; ���� ����� 4,1 ��
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_Delay_100mks							; ���� ����� 100���
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_BF_Check								; ��������� ��������� ����� ���������
												  
		lds r16, HD44780U_Function_Set_byte				; ������ Function Set � r16
		HD44780U_Send_instruction r16					; ����������� ����������

		lds r16, HD44780U_Display_On_Off_Control_byte	; ������ Display On/Off Control � r16
		HD44780U_Send_instruction r16					; ����������� ����������
												  
		ldi r16, HD44780U_LCDClear						; ����������� ���������� Display clear
		HD44780U_Send_instruction r16					; ����������� ����������

		lds r16, HD44780U_Entry_Mode_Set_byte			; ������ Entry Mode Set � r16
		HD44780U_Send_instruction r16					; ����������� ����������

		lds r16, HD44780U_Cursor_or_display_shift		; ������ Cursor or display shift � r16
		HD44780U_Send_instruction r16					; ����������� ����������
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_4_Wires
	HD44780U_init_Act:
		SETB HD44780U_D4_DDR, HD44780U_D4_bit			; ������������� ��� ���� �������� �������� �� �����
		SETB HD44780U_D5_DDR, HD44780U_D5_bit					  
		SETB HD44780U_D6_DDR, HD44780U_D6_bit					  
		SETB HD44780U_D7_DDR, HD44780U_D7_bit					 							
		SETB HD44780U_RS_DDR, HD44780U_RS_bit					  
		SETB HD44780U_RW_DDR, HD44780U_RW_bit					  
		SETB HD44780U_E_DDR,  HD44780U_E_bit			; ����������� ���� �� �����
												  
		HD44780U_Delay_15ms								; ���� ����� 15 ��
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_Delay_4_1ms							; ���� ����� 4,1 ��
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_Delay_100mks							; ���� ����� 100���
		ldi	r16, $30									; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_BF_Check								; ��������� ��������� ����� ���������
												  
		ldi	r16, HD44780U_LCD_Function_Set				; ������������� ����������
		HD44780U_instr									; ����������� ����������
		HD44780U_BF_Check								; ��������� ��������� ����� ���������
																	  
		lds r16, HD44780U_Function_Set_byte				; ������ Function Set � r16
		HD44780U_Send_instruction r16					; ����������� ����������
		
		lds r16, HD44780U_Display_On_Off_Control_byte	; ������ Display On/Off Control � r16
		HD44780U_Send_instruction r16					; ����������� ����������
																	  
		ldi r16, HD44780U_LCDClear						; ����������� ���������� Display clear
		HD44780U_Send_instruction r16					; ����������� ����������
																	  
		lds r16, HD44780U_Entry_Mode_Set_byte			; ������ Entry Mode Set � r16
		HD44780U_Send_instruction r16					; ����������� ����������
		HD44780U_Delay_15ms								; ���� ����� 15 ��

		lds r16, HD44780U_Cursor_or_display_shift		; ������ Cursor or display shift � r16
		HD44780U_Send_instruction r16					; ����������� ����������
	ret
//____________________________________________________________________________________
//____________________________________________________________________________________
#elif defined HD44780U_TWSI
	HD44780U_init_Act:

		HD44780U_Delay_15ms											; ���� 15-40 ms
		TWSI_START										; �������� START (���������� ��� ������)
		ldi r16, TWSI_Address
		TWSI_SLA r16, 'W'

		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; ��������� ������ ���������� �������������	
		HD44780U_Send_instr_byte_high		 						; �������� ������� ������� ����� ����������

		HD44780U_Delay_4_1ms										; ���� ������ 4,1 ms

		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; ��������� ������ ���������� �������������
		HD44780U_Send_instr_byte_high								; �������� ������� ������� ����� ����������

		HD44780U_Delay_100mks										; ���� ������ 100 mks
		
		ldi	r16, (1<<HD44780U_LCD_D4) | (1<<HD44780U_LCD_D5)		; ��������� ������ ���������� �������������
		HD44780U_Send_instr_byte_high								; �������� ������� ������� ����� ����������
		
		ldi	r16, (1<<HD44780U_LCD_D5)								; ��������� ��������� ���������� �������������
		HD44780U_Send_instr_byte_high								; �������� ������� ������� ����� ����������

		HD44780U_BF_Check											; �������� ��������� LCD

		lds r16, HD44780U_Function_Set_byte				; ������ Function Set � r16
		HD44780U_Send_instruction r16					; ����������� ����������
		HD44780U_BF_Check								; �������� ��������� LCD

		lds r16, HD44780U_Display_On_Off_Control_byte	; ������ Display On/Off Control � r16
		
		HD44780U_Delay_100mks							; ���� ������ 100 mks
		HD44780U_Send_instruction r16					; �������� ���� ����������
		HD44780U_BF_Check								; �������� ��������� LCD

		ldi	r16, HD44780U_LCDClear						; LCD_Clear
		HD44780U_Delay_100mks							; ���� ������ 100 mks
		HD44780U_Send_instruction r16					; �������� ���� ����������
		HD44780U_BF_Check								; �������� ��������� LCD

		lds r16, HD44780U_Entry_Mode_Set_byte			; ������ Entry Mode Set � r16
		
		HD44780U_Delay_100mks							; ���� ������ 100 mks
		HD44780U_Send_instruction r16					; �������� ���� ����������

		lds r16, HD44780U_Cursor_or_display_shift		; ������ Cursor or display shift � r16
		HD44780U_Send_instruction r16					; ����������� ����������

		TWSI_STOP										; �������� ������� STOP
	ret													; ����� �� ������������
#endif
