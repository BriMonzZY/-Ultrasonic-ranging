#ifndef _IIC_H
#define _IIC_H

void init24c02();  //24c02��ʼ���ӳ���
void delay1(unsigned int m);
void nop();
void start();        //����I2C����
void stop();
void clock();         //I2C����ʱ��
unsigned char readbyte();   //��һ���ֽ�
void writebyte(uchar j);  //дһ���ֽ�


void write24c02(uchar address, unsigned char info);
uchar read24c02(uchar address);


#endif