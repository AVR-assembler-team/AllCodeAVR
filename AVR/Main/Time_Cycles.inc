Time_Cycles:
	sbiw	xh:xl, 1 ;������� 1 �� �����				2
	brne	Time_Cycles ;���� �� ����� 0, �� ���������		2
ret