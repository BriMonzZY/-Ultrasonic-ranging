#ifndef _CONFIG_H
#define _CONFIG_H
/****************************************************************
 ͨ��ͷ�ļ�
****************************************************************/
#include <reg52.h>
#include <intrins.h>
#include <stdio.h>

#define MAIN_Fosc		11059200UL	//�궨����ʱ��HZ

/****************************************************************
���������������¶���
****************************************************************/
typedef signed char int8;  //8λ�з�����
typedef signed int  int16; //16λ�з�����
typedef unsigned char uint8;  //8λ�޷�����
typedef unsigned char uchar;  //8λ�޷�����
typedef unsigned int  uint16; //16λ�޷�����
typedef unsigned int  uint; //16λ�޷�����
typedef unsigned long uint32; //32λ�޷�����

/****************************************************************
 Ӳ���ӿڶ���
****************************************************************/

/*4λ������������*/
sbit KEY_S2 = P3^0;	//S2��������
sbit KEY_S3 = P3^1;	//S3��������
sbit KEY_S4 = P3^2;	//S4��������
sbit KEY_S5 = P3^3;	//S5��������

/*�����������*/
sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;

/*���������*/
sbit DU = P2^6;
sbit WE = P2^7;


/*IIC����*/
sbit sda = P2^0;
sbit scl = P2^1;

/*LED����*/
sbit L1 = P1^0;
sbit L7 = P1^6;
sbit L8 = P1^7;

/*�������������*/
sbit TRIG = P3^4; //��Ƭ��2.7��Ŷ�Ӧ trig
sbit ECHO = P3^5; //��Ƭ��2.6��Ŷ�Ӧ echo


/*DAC������ż�����*/
sfr P4 = 0xe8;  /*C����������P4�����⹦�ܼĴ�����ַ*/
sbit DAC_DATA = P4^4;//DA���ݿ�
sbit CS = P3^7;
sbit DCLK = P2^1;
sbit DIN = 	P2^0;
sbit DOUT = P2^5;
#define AD_CH3 0xe4 

#endif