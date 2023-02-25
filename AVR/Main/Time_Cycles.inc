Time_Cycles:
	sbiw	xh:xl, 1 ;вычесть 1 из слова				2
	brne	Time_Cycles ;если не равно 0, то переходим		2
ret