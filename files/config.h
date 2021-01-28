#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 通用头文件
****************************************************************/
#include <reg52.h>
#include <intrins.h>
#include <stdio.h>

#define MAIN_Fosc		11059200UL	//宏定义主时钟HZ

/****************************************************************
已有数据类型重新定义
****************************************************************/
typedef signed char int8;  //8位有符号型
typedef signed int  int16; //16位有符号型
typedef unsigned char uint8;  //8位无符号型
typedef unsigned char uchar;  //8位无符号型
typedef unsigned int  uint16; //16位无符号型
typedef unsigned int  uint; //16位无符号型
typedef unsigned long uint32; //32位无符号型

/****************************************************************
 硬件接口定义
****************************************************************/

/*4位独立按键引脚*/
sbit KEY_S2 = P3^0;	//S2独立按键
sbit KEY_S3 = P3^1;	//S3独立按键
sbit KEY_S4 = P3^2;	//S4独立按键
sbit KEY_S5 = P3^3;	//S5独立按键

/*矩阵键盘引脚*/
sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;

/*数码管引脚*/
sbit DU = P2^6;
sbit WE = P2^7;


/*IIC引脚*/
sbit sda = P2^0;
sbit scl = P2^1;

/*LED引脚*/
sbit L1 = P1^0;
sbit L7 = P1^6;
sbit L8 = P1^7;

/*超声波测距引脚*/
sbit TRIG = P3^4; //单片机2.7针脚对应 trig
sbit ECHO = P3^5; //单片机2.6针脚对应 echo


/*DAC相关引脚及定义*/
sfr P4 = 0xe8;  /*C语言中声明P4口特殊功能寄存器地址*/
sbit DAC_DATA = P4^4;//DA数据口
sbit CS = P3^7;
sbit DCLK = P2^1;
sbit DIN = 	P2^0;
sbit DOUT = P2^5;
#define AD_CH3 0xe4 

#endif