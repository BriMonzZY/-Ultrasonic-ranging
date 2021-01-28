#ifndef _MAIN_H
#define _MAIN_H

enum eStaSystem {  //枚举系统状态
	INIT, MEASURE, MEMORY, SETTING
};

#ifndef _MAIN_C
extern enum eStaSystem staSystem;//staSystem当前系统状态
#endif


extern uchar surface[8];
extern uchar addr;
extern uchar dis;
extern uchar num_dis[5];
extern uchar memory_dis;
extern uchar memory_temp_dis;
extern uchar setting;

void Init_Timer1();

#endif