#ifndef _MAIN_H
#define _MAIN_H

enum eStaSystem {  //ö��ϵͳ״̬
	INIT, MEASURE, MEMORY, SETTING
};

#ifndef _MAIN_C
extern enum eStaSystem staSystem;//staSystem��ǰϵͳ״̬
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