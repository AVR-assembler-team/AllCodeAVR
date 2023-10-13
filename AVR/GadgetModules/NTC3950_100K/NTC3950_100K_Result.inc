
ReadADC:
	ldi r24, $7d			; ADC low    
	ldi r25, $02			; ADC high
ret
Result:
	
	// Заталкиваем в STECK
	push r16
	push r17
	push r18
	push r19
	push r20	
	push r21
	push r22
	push r23
	push r24	; младший байт ADC
	push r25	; старший байт ADC
	push xh
	push xl
	push yl
	push zh
	push zl

	
	_call ReadADC	; читаем ADC и записываем r24 и r25
			
	// Производим перебор массива по результатам измерения ADC
	Begin:
		// записываем адреса флагов T0 и Т1 в память и проверяем мы в массиве или нет
		// если вывалились из массива, то помечаем это в памяти и заканчиваем работу
		// если у нас минимальная или максимальная температура, то записываем в память и заканчиваем работу
		
		// Берем адрес начала массива
		ldi zh, high(TempRange * 2)
		ldi zl, low(TempRange * 2)

		// Записываем адреса начала массива в память
		WRITE_REG T0, zl
		WRITE_REG T0 + 1, zh
	
		// Читаем два байта из начала массива
		lpm r16, z+
		lpm r17, z
		
		// Берем адрес конца массива
		ldi zh, high((TempRange * 2) + TempRangeMax)
		ldi zl, low((TempRange * 2) + TempRangeMax)

		// Записываем адреса конца массива в память
		WRITE_REG T1, zl
		WRITE_REG T1 + 1, zh

		// Сверяем данные из ADC и данными начала массива
		_call Calculation2		
		
		// Мсотрим, что получили

		// Сравниваем с $00 ($00 - значит данные ADC меньше данных начала массива)
		cpi r16, $00
		// Если не меньше, то переходим
		brne NotLess

		// Если все-таки меньше, то записываем в Temperature $00ff и переходим к концу программы
		clr zl
		WRITE_REG Temperature, zl
		ldi zl, $ff
		WRITE_REG Temperature + 1, zl
		_jump Result_end				

	NotLess:
		// Сравниваем с $02 ($02 - значит данные ADC больше данных начала массива)
		cpi r16, $02
		// Если больше, то переходим
		breq Maximun

		// Если данные ADC равны данным начала массива, то записываем в Temperature $0000 и выходим из программы
		clr zl
		WRITE_REG Temperature, zl
		WRITE_REG Temperature + 1, zl
		_jump Result_end


	Maximun:
		// Читаем два байта из конца массива
		lpm r16, z+
		lpm r17, z
		
		// Сверяем данные из ADC и данными конца массива
		_call Calculation2

		// Сравниваем с $02 ($02 - значит данные ADC больше данных конца массива)
		cpi r16, $02
		// Если не больше, то переходим
		brne NotMore

		// Если больше, то записываем в Temperature $ff00 и переходим к концу программы
		ldi zl, $ff
		WRITE_REG Temperature, zl
		clr zl
		WRITE_REG Temperature +1, zl
		_jump Result_end
	
	NotMore:
		// Сравниваем с $00 ($00 - значит данные ADC меньше данных конца массива)
		cpi r16, $00
		// Если все-таки меньше, то переходим
		breq Calculation1
		
		// Если данные ADC равны данным конца массива, то записываем в Temperature $f000 и выходим из программы
		ldi zl, $f0
		WRITE_REG Temperature, zl
		clr zl
		WRITE_REG Temperature + 1, zl
		_jump Result_end


	// Находим шаг массива в котором лежит наше значение
	Calculation1:	
		// Производится проверка по массиву по результатам измерения ADC и находится промежуток 
		// температур (в 2 С) в котором лежит наше значение ADC
		// записывает в память новые адреса флагов и если данные совпали с данными из таблицы, то 
		// записывает в память температуру из таблицы. 
		// После того как перебор массива завершится, то будет выполнен перехд к расчету между 2 градуса по С
		
		// Берем адрес флага Т0
		READ_REG T0, r18
		READ_REG T0 + 1, r19

		// Берем адрес флага Т1
		READ_REG T1, r16
		READ_REG T1 + 1, r17	
		
		// Находим разницу между адресами Т0 и Т1
		sub r16, r18
		sbc r17, r19

		// Находим адрес посередине между адресами Т0 и Т1 путем сдвигов регистров (делением и умножением на 2)
		lsr r17
		ror r16
		lsr r17
		ror r16
		lsl r16
		rol r17

		// Если расстояние между Т0 и Т1 равно шагу массива (тоесть расчеты дали 0), то переходим по метке
		cpi r16, $00
		breq Calculation3
		
		// Прибавляем найденное количество сдвигов от Т0 до серидины расстояния до Т1 и прибавляем к адресу Т0
		add r18, r16
		adc r19, r17
		
		// Читаем данные по эдресу выше и записываем этот адрес в Z
		movw zl:zh, r18:r19
		lpm r16, z+
		lpm r17, z
		movw zl:zh, r18:r19
		
		// Сверяем данные из ADC и данными конца массива
		_call Calculation2

		// Сравниваем с $01 ($01 - значит данные ADC равны данным из массива)
		cpi r16, $01
		// Переходим, если данные ADC равны данным из массива
		breq Calc1Equal
		// // Переходим, если данные ADC меньше данных из массива
		brlo Calc1Less

	Calc1More:
		// Так как данные ADC больше данных из массива, то смещаем адрес флага Т0 на адрес данных из массива
		// И возвращаемся по метке
		WRITE_REG T0, zl
		WRITE_REG T0 + 1, zh
		_jump Calculation1

	Calc1Less:
		// Так как данные ADC меньше данных из массива, то смещаем адрес флага Т1 на адрес данных из массива
		// И возвращаемся по метке
		WRITE_REG T1, zl
		WRITE_REG T1 + 1, zh
		_jump Calculation1

	Calc1Equal:
		// Так как данные ADC равны данным из массива, то записываем данную температура в Temperature
		// И завершаем работу программы
		_call TempToTable
		_jump Result_end
		




	// Выясняем у нас целый градус или с десятыми и находим его
	Calculation3:
		
		// Читаем младший байт адреса флага Т0
		READ_REG T0, xl
		
		// Читаем младший байт адреса начала массива
		ldi yl, low(TempRange * 2)

		// находим смещение флага Т0 от начала массива (тоесть значение температуры в градусах)
		sub xl, yl
		// Записываем в память
		WRITE_REG TemtVar, xl
		_call ReadableTemperature

		// Читаем адрес флага Т0
		READ_REG T0, zl
		READ_REG T0 + 1, zh 
		// Читаем 2 байта из флага Т0
		lpm r16, z+
		lpm r17, z
		// Записываем в память в Temperature0
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// Читаем адрес флага Т1
		READ_REG T1, zl
		READ_REG T1 + 1, zh 
		// Читаем 2 байта из флага Т0
		lpm r18, z+
		lpm r19, z
		// Записываем в память в Temperature1
		WRITE_REG Temperature1, r18
		WRITE_REG Temperature1 + 1, r19

		// Отнимаем от Temperature1 Temperature0 и узнаем сколько бит в шаге измеряемых 2 градуса
		sub r18, r16
		sbc r19, r17
		// Делим на 2 без остатка
		mov r20, r18
		lsr r18
		sub r20, r18

		// Получаем значения промежуточного градуса в шаге 2 градуса
		add r16, r18
		clr r19
		adc r17, r19

		// Сверяем данные из ADC и данными конца массива
		_call Calculation2

		// Смотрим получится ли измерить десятые градуса
		cpi r18, $0a
		// Если сможем измерить, то переходим
		brsh Desiatki

		// Если не сможем, то будут только целые градусы
		_jump TselieGradysi
	
	// Подчет десятков градусов	
	Desiatki:

		// Проверяем данные ADC равны ли данным промежуточного радуса?
		cpi r16, $01
		// Если данные ADC равны данным промежуточного радуса
		breq DesiatkiEqual
		// Если меньше то переходим
		brlo DesiatkiLess
		
	// Остаемся если больше
	DesiatkiMore:

		// Увеличиваем сохраненную в памяти температуру на градус
		_call DegInc

		// Читаем из переменной данные меньшего градуса 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		
		// Добавляем количество бит соответствующих смещению на один градус от меньшего
		add r16, r18
		adc r17, r19

		// Записываем в переменную
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// Делим количество бит большего промежутка на 2 
		lsr r20

		// Добавляем к данным промежуточного градуса
		add r16, r20
		adc r17, r19

		// Копируем данное смещение в регистр r18
		mov r18, r20

		// Переходим по метке
		_jump DesiatkiPolGradusa

	DesiatkiLess:

		// Читаем из переменной данные большего градуса
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		// Отнимаем количество бит большего промежутка (данные середины шага массива)
		sub r16, r20
		sbc r17, r19
		
		// Записываем в переменную
		WRITE_REG Temperature1, r16
		WRITE_REG Temperature1 + 1, r17

		// Читаем из переменной данные меньшего градуса 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17

		// Делим количество бит меньшего промежутка на 2
		lsr r18

		// Прибавляем к данным меньшего градуса (находим данные половины градуса)
		add r16, r18
		adc r17, r19

		// Переходим
		_jump DesiatkiPolGradusa

	DesiatkiEqual:

		// Увеличиваем сохраненную в памяти температуру на градус
		_call DegInc

		// Выходим из программы
		_jump Result_end
	
	DesiatkiPolGradusa:
		
		// Сверяем данные из ADC и данными конца массива
		_call Calculation2

		// Проверяем данные ADC равны ли данным промежуточного радуса?
		cpi r16, $01

		// Переходим при равенстве
		breq DesiatkiPolGradusaEqual

		// Переходим есди меньше
		brlo DesiatkiGradusaLessHalf

	// Остаемся если больше
	DesiatkiGradusaMoreHalf:
	
		// Записываем пол градуса в память
		ldi r20, $05
		WRITE_REG Temperature + 1, r20

		// Читаем из переменной данные меньшего градуса 
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		
		// Прибавляем значения половины градуса
		add r16, r18
		adc r17, r19
		
		// Сохраняем в переменную
		WRITE_REG Temperature0, r16
		WRITE_REG Temperature0 + 1, r17

		// Переходим
		_jump DesiatkiPolGradusaPoDesiatke

	DesiatkiGradusaLessHalf:

		// Читаем из переменной данные большего градуса
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		// Отнимаем данные половины градуса
		sub r16, r18
		sbc r17, r19
		
		// Сохраняем в переменную
		WRITE_REG Temperature1, r16
		WRITE_REG Temperature1 + 1, r17

		// Очищаем десятки градуса
		ldi r20, $00
		WRITE_REG Temperature + 1, r20

		// Переходим
		_jump DesiatkiPolGradusaPoDesiatke
	
	DesiatkiPolGradusaEqual:

		// Записываем пол градуса в память
		ldi r20, $05
		WRITE_REG Temperature + 1, r20

		// Выходим из программы
		_jump Result_end


	DesiatkiPolGradusaPoDesiatke:

		// Увеличиваем десятки градуса на 1
		_call DesiatkiDegInc

		// Записываем 5 в регистр
		ldi r20, $05

		// Смотрим делится ли количество бит 0,5 градуса на 5 без остатка, или нет?
		// В r19 целые части, в r18 десятки от деления на 5
		Переделать как нужно. 
		PoDesiatkeCalc:
			inc r19
			sub r18, r20
			brpl PoDesiatkeCalc
			dec r19
			R18 в конце нужно умножить на 10 и потом делить на 5
			add r18, r20
			mov r20, r18

		Raschet:

			// Читаем из переменной данные меньшего градуса 
			READ_REG Temperature0, r16
			READ_REG Temperature0 + 1, r17

			// прибавляем к нижнему пределу
			add r16, r19
			clr r21
			adc r17, r21

			// Проверяем сложение остатков, и если они равны или больше 10, то прибавляем смещение 0,1 градуса еще раз
			add r20, r18
			cpi r20, $0a
			brlo Raschet1
			add r16, r19
			clr r21
			adc r17, r21
			mov r20, r18
			
			// Сохраняем в переменную
			WRITE_REG Temperature0, r16
			WRITE_REG Temperature0 + 1, r17

		Raschet1:

			// Сверяем данные из ADC и данными конца массива
			_call Calculation2

			// Проверяем данные ADC равны ли данным промежуточного радуса?
			cpi r16, $01

			// Переходим, если равно
			breq RaschetEqual

			// Переходим, если меньше
			brlo RaschetLess

			// Остаемся, если больше
			RaschetMore:

				// Увеличиваем десятки градуса на 1
				_call DesiatkiDegInc

				// Смотрим получили ли 10 в переменной с десятками градуса?
				cpi r16, $0a

				// Если да, то переходим
				breq PlusGradus

				// Иначе переходим по метке
				_jump Raschet

				PlusGradus:

					// Увеличиваем температуру на градус
					_call DegInc

					// Очищаем десятки градуса
					clr r16
					WRITE_REG Temperature + 1, r16

			RaschetLess:
			RaschetEqual:

				// Заканчиваем программу
				_jump Result_end

Result_end:

	ldi r16, $01
	add r24, r16
	clr r16
	adc r25, r16

	_jump Begin

	pop zl
	pop zh
	pop yl
	pop xl
	pop xh
	pop r25		; старший байт ADC
	pop r24		; младший байт ADC
	pop r23
	pop r22
	pop r21
	pop r20
	pop r19
	pop r18
	pop r17
	pop r16

ret





//////////////////////////////////////////////////////////////////////////////////
Calculation2:
	// Использует r16, r17, r24, r25
	// Производит сравнение данных и находит положение нашего значения в массиве
	// Положение больше или меньше относительно проверяемого значения
	// На выходе будет 0, 1 или 2 в регистре r16
	// 0 - меньше
	// 1 - равно
	// 2 - больше
	cp r17, r25				; Сравниваем r17 с r25
	breq HighEqual			; Если равны
	brlo HighOver			; Если r17 меньше
	
	HighLess:
		clr r16
		ret

	HighOver:				; Если r17 больше
		ldi r16, $02
		ret

	HighEqual:
		cp r16, r24
		breq LowEqual
		brlo LowOver

	LowLess:
		clr r16
		ret
	
	LowOver:
		ldi r16, $02
		ret

	LowEqual:
		ldi r16, $01
		ret
//////////////////////////////////////////////////////////
TselieGradysi:
	
		cpi r16, $01
		breq TselieGradysiEqual
		brlo TselieGradysiLess
		

	TselieGradysiMore:
		_call DegInc
		READ_REG Temperature1, r16
		READ_REG Temperature1 + 1, r17

		sub r16, r20						; вычитаем без переноса
		sbc r17, r19						; вычитаем с переносом

		lsr r20								; сдвигаем вправо на 1 (делим на 2 без остатка)

		add r16, r20						; суммируем без переноса
		adc r17, r19						; суммируем с переносом

		_jump TselieGradysiPolGradusa

	TselieGradysiLess:
		READ_REG Temperature0, r16
		READ_REG Temperature0 + 1, r17
		lsr r18								; сдвигаем вправо на 1 (делим на 2 без остатка)
		add r16, r18						; суммируем без переноса
		clr r19								; очищаем r18
		adc r17, r19						; суммируем с переносом
		_jump TselieGradysiPolGradusa

	TselieGradysiEqual:
		_call DegInc
		_jump Result_end
	
	TselieGradysiPolGradusa:
		// Производим сравнение значений для вычисления положения проверяемого значения в массиве
		_call Calculation2
	
		cpi r16, $01
		brlo TselieGradysiPolGradusaLess

	TselieGradysiPolGradusaEqualMore:
		_call DegInc
		_jump Result_end
		
	TselieGradysiPolGradusaLess:
		_jump Result_end
///////////////////////////////////////////////
DegInc:
	// Делаем градус на 1 больше
	READ_REG TemtVar, r16
	inc r16
	WRITE_REG TemtVar, r16	; сделали пол градуса в переменной
	_call ReadableTemperature
ret
///////////////////////////////////////////////
DesiatkiDegDec:
	READ_REG Temperature + 1, r16
	dec r16
	WRITE_REG Temperature + 1, r16	; сделали пол градуса в переменной
ret
///////////////////////////////////////////////
DesiatkiDegInc:
	READ_REG Temperature + 1, r16
	inc r16
	WRITE_REG Temperature + 1, r16	; сделали пол градуса в переменной
ret
///////////////////////////////////////////////
ReadableTemperature:
	READ_REG TemtVar, xl
	clr xh
	ldi r22, $0a
ReadableTemperatureLoop:
	inc xh
	sub xl, r22
	brpl ReadableTemperatureLoop
	dec xh
	add xl, r22
	swap xh
	or xh, xl
	WRITE_REG Temperature, xh
ret