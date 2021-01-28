#ifndef _IIC_H
#define _IIC_H

void init24c02();  //24c02初始化子程序
void delay1(unsigned int m);
void nop();
void start();        //启动I2C总线
void stop();
void clock();         //I2C总线时钟
unsigned char readbyte();   //读一个字节
void writebyte(uchar j);  //写一个字节


void write24c02(uchar address, unsigned char info);
uchar read24c02(uchar address);


#endif