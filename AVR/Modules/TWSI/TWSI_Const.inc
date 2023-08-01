/*
*  онстанты, используемые в работе модул€ TWSI
*/
.dseg
TWSI_Flags:				.byte 1

.cseg
.equ No_ACK		=	0


.equ START_ACK			=	$08
.equ MT_SLA_W_ACK		=	$18
.equ MT_SLA_W_NOT_ACK	=	$20
.equ MT_SLA_R_ACK		=	$40
.equ MT_SLA_R_NOT_ACK	=	$48
.equ MT_DATA_ACK		=	$28
.equ MT_DATA_NOT_ACK	=	$30
.equ MT_NACK			=	$58

.equ MR_DATA_ACK		=	$50
.equ MR_LASTDATA_ACK	=	$58
