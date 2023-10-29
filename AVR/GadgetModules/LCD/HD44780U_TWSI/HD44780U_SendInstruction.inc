/*
* �������� ���������� �������
* ���������� ������� r25
*/
HD44780U_Send_instruction:
	push r25
	TWSI_START								; �������� START (���������� ��� ������)
	TWSI_SLA HD44780U_SLA_, 'W'
	pop r25
	_call HD44780U_Send_instr_byte_high			; ��������� �� �����
	_call HD44780U_Send_instr_byte_low			; ��������� �� �����
	TWSI_STOP								; �������� START (���������� ��� ������)
ret											; ����� �� ������������
;----------------------------------------------------------------
HD44780U_Send_instr_byte_high:			; �����
	push	r25								; ���������� � ����
	andi	r25, $f0						; �������� ������ 4 ����
	push	r25								; ���������� � ����
		
	SETRB r25, HD44780U_LCD_E
	SETRB r25, HD44780U_LCD_LIGHT

	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����	

	pop		r25										; ��������� �� �����
	SETRB r25, HD44780U_LCD_LIGHT
		HD44780U_Delay_5mks						; ��������

	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����
			
	pop		r25										; ��������� �� �����
ret													; ����� �� ������������
;--------------------------------------------------------------
HD44780U_Send_instr_byte_low:
	swap	r25										; ������ ������� �������
	andi	r25, 0xF0								; �������� ������ 4 ����
	push	r25										; ���������� � ����
		
	SETRB r25, HD44780U_LCD_E
	SETRB r25, HD44780U_LCD_LIGHT
	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����	

	pop		r25										; ��������� �� �����
	SETRB r25, HD44780U_LCD_LIGHT
		HD44780U_Delay_5mks						; ��������

	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����	
ret													; ����� �� ������������