/*
* !!!!!!!!!!!!!!!!!!!!!.....НИЧЕГО ТУТ НЕ ТРОГАТЬ.....!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
* Для упрощения работы библиотек при выборе микроконтроллера
*/

#if defined _M8ADEF_INC_ || _M8DEF_INC_ || _M8HVADEF_INC_ || _M8U2DEF_INC_
	.equ ctlr = 8
#elif defined _M16DEF_INC_ || _M16ADEF_INC_ || _M16HVADEF_INC_ ||_M16HVBDEF_INC_ || _M16HVBREVBDEF_INC_ || _M16M1DEF_INC_ || _M16U2DEF_INC_ || _M16U4DEF_INC_
	.equ ctlr = 16
#elif defined _M32ADEF_INC_ || _M32C1DEF_INC_ || _M32DEF_INC_ || _M32HVBDEF_INC_ || _M32HVBREVBDEF_INC_ || _M32M1DEF_INC_ || _M32U2DEF_INC_ || _M32U4DEF_INC_
	.equ ctlr = 32
#elif defined _M48ADEF_INC_ || _M48DEF_INC_ || _M48PADEF_INC_ || _M48PBDEF_INC_ || _M48PDEF_INC_
	.equ ctlr = 48
#elif defined _M64ADEF_INC_ || _M64C1DEF_INC_ || _M64DEF_INC_ || _M64HVE2DEF_INC_ || _M64M1DEF_INC_ || _M64RFR2DEF_INC_
	.equ ctlr = 64
#elif defined _M88ADEF_INC_ || _M88DEF_INC_ || _M88PADEF_INC_ || _M88PBDEF_INC_ || _M88PDEF_INC_
	.equ ctlr = 88
#elif defined _M128ADEF_INC_ || _M128DEF_INC_ || _M128RFA1DEF_INC_ || _M128RFR2DEF_INC_
	.equ ctlr = 128
#elif defined _M162DEF_INC_
	.equ ctlr = 162
#elif defined _M164ADEF_INC_ || _M164PADEF_INC_ || _M164PDEF_INC_
	.equ ctlr = 164
#elif defined _M165ADEF_INC_ || _M165PADEF_INC_ ||_M165PDEF_INC_
	.equ ctlr = 165
#elif defined _M168ADEF_INC_ || _M168DEF_INC_ || _M168PADEF_INC_ || _M168PBDEF_INC_ || _M168PDEF_INC_
	.equ ctlr = 168
#elif defined _M169ADEF_INC_ || _M169PADEF_INC_ || _M169PDEF_INC_
	.equ ctlr = 169
#elif defined _M324ADEF_INC_ || _M324PADEF_INC_ || _M324PBDEF_INC_ || _M324PDEF_INC_
	.equ ctlr = 324
#elif defined _M325ADEF_INC_ || _M325DEF_INC_ || _M325PADEF_INC_ || _M325PDEF_INC_
	.equ ctlr = 325
#elif defined _M328DEF_INC_ || _M328PBDEF_INC_ || _M328PDEF_INC_
	.equ ctlr = 328
#elif defined _M329ADEF_INC_ || _M329DEF_INC_ || _M329PADEF_INC_ || _M329PDEF_INC_
	.equ ctlr = 329
#elif defined _M406DEF_INC_
	.equ ctlr = 406
#elif defined _M640DEF_INC_
	.equ ctlr = 640
#elif defined _M644ADEF_INC_ || _M644DEF_INC_ || _M644PADEF_INC_ || _M644PDEF_INC_ || _M644RFR2DEF_INC_
	.equ ctlr = 644
#elif defined _M645ADEF_INC_ || _M645DEF_INC_ || _M645PDEF_INC_
	.equ ctlr = 645
#elif defined _M649ADEF_INC_ || _M649DEF_INC_ || _M649PDEF_INC_
	.equ ctlr = 649
#elif defined _M808DEF_INC_
	.equ ctlr = 808
#elif defined _M809DEF_INC_
	.equ ctlr = 809
#elif defined _M1280DEF_INC_
	.equ ctlr = 1280
#elif defined _M1281DEF_INC_
	.equ ctlr = 1281
#elif defined _M1284DEF_INC_ || _M1284PDEF_INC_ || _M1284RFR2DEF_INC_
	.equ ctlr = 1284
#elif defined _M1608DEF_INC_
	.equ ctlr = 1608
#elif defined _M1609DEF_INC_
	.equ ctlr = 1609
#elif defined _M2560DEF_INC_
	.equ ctlr = 2560
#elif defined _M2561DEF_INC_
	.equ ctlr = 2561
#elif defined _M2564RFR2DEF_INC_
	.equ ctlr = 2564
#elif defined _M3208DEF_INC_
	.equ ctlr = 3208
#elif defined _M3209DEF_INC_
	.equ ctlr = 3209
#elif defined _M3250ADEF_INC_ || _M3250DEF_INC_ || _M3250PADEF_INC_ || _M3250PDEF_INC_
	.equ ctlr = 3250
#elif defined _M3290ADEF_INC_ || _M3290DEF_INC_ || _M3290PADEF_INC_ || _M3290PDEF_INC_
	.equ ctlr = 3290
#elif defined _M4808DEF_INC_
	.equ ctlr = 4808
#elif defined _M4809DEF_INC_
	.equ ctlr = 4809
#elif defined _M6450ADEF_INC_ || _M6450DEF_INC_ || _M6450PDEF_INC_
	.equ ctlr = 6450
#elif defined _M6490ADEF_INC_ || _M6490DEF_INC_ || _M6490PDEF_INC_
	.equ ctlr = 6490
#elif defined _M8515DEF_INC_
	.equ ctlr = 8515
#elif _M8535DEF_INC_
	.equ ctlr = 8535
#endif


