/*
* ���������� ������� r25
*/

HD44780U_Send_data_byte_high:																			
	push	r25						; ���������� � ����
	andi	r25, $f0				; �������� ������ 4 ����
	push	r25						; ���������� � ����
		
	SETRB r25, HD44780U_LCD_RS
	SETRB r25, HD44780U_LCD_E
	SETRB r25, HD44780U_LCD_LIGHT

	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����	
	pop		r25										; ��������� �� �����
		
	SETRB r25, HD44780U_LCD_RS
	SETRB r25, HD44780U_LCD_LIGHT
		
	WRITE_REG TWDR, r25								; ���������� � ���� �������
	TWSI_Byte_Transmit								; ���������� TWDR �� ����
	TWSI_ACK_Check MT_DATA_ACK, MT_DATA_NOT_ACK		; ��������� ������� �� �����	
	pop		r25						; ��������� �� �����
ret									; ����� �� ������������
