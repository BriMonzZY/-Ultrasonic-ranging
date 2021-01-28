#define _MAIN_C
#include "config.h"
#include "main.h"
#include "hcsr04.h"
#include "iic.h"
#include "led.h"
#include "key.h"
#include "dac.h"
#include "smg.h"
#include "app.h"



enum eStaSystem staSystem = INIT;	//系统运行状态


uchar surface[8] = {16, 14, 14, 14, 14, 14, 14, 14};//显示数组


uchar addr = 110; //存储24c02地址
uchar dis = 0;
uchar memory_dis; //查询索引
uchar setting;



void main()
{
	Init_Timer1(); //定时器中断0初始化
	init();
	init24c02();
	while(1) {
		KeyDriver(); //扫描独立键盘
		
		if(staSystem == INIT) {
			surface[0] = 16; surface[1] = 14; surface[2] = 14; surface[3] = 14; surface[4] = 14; surface[5] = 14; surface[6] = 14; surface[7] = 14;
		}
		
		if(staSystem == MEASURE) {
			surface[0] = 16;
		}
		
		if(staSystem == MEMORY) {
			surface[0] = memory_dis;
			surface[1] = 14; surface[2] = 14; surface[3] = 14; surface[4] = 14;			
			surface[5] = read24c02(memory_dis + 109)/100%10;
			surface[6] = read24c02(memory_dis + 109)/10%10;
			surface[7] = read24c02(memory_dis + 109)%10;
		}
		
		if(staSystem == SETTING) {
			surface[6] = setting/10;
			surface[7] = 0;
		}
		
		if(read24c02(addr) <= setting) {
			
		}
		else {
			
		}
		
	}
	
	
}



void Init_Timer1() {
	EA = 1;
	TMOD = 0x10;
	TH1 = 0xfc; //加载初值1ms
	TL1 = 0x66;
	ET1 = 1;
	TR1 = 1;
}
/*定时器0用于测距*/
/*定时器1用于扫描*/
void timer1() interrupt 3 //用于数码管扫描以及按键扫描
{
	static uchar flags;
	TH1 = 0xfc; //重新加载初值1ms
	TL1 = 0x66;
	/*数码管*/  
	flags++;
	if(flags == 2) {
		flags = 0;
		display(surface[0], surface[1], surface[2], surface[3], surface[4], surface[5], surface[6], surface[7]);
	}
	KeyScan();
}