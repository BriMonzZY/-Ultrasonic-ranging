#include "config.h"
#include "main.h"
#include "hcsr04.h"
#include "iic.h"
#include "led.h"
#include "key.h"
#include "dac.h"
#include "smg.h"
#include "app.h"

void key_s2() {
	if(staSystem == INIT) { //进入测距界面并测一个
		staSystem = MEASURE;
		surface[0] = 16;
		get_distance();
		
		write24c02(addr, dis);
		if(addr == 113) addr = 110;
		else addr++;
		
		surface[5] = 14; surface[6] = 14; surface[7] = 14;
	}
	
	else if(staSystem == MEASURE) { //测量下一个
		get_distance();
		
		write24c02(addr, dis);
		if(addr == 113) addr = 110;
		else addr++;
	}
}


void key_s3()  {
	if(staSystem == MEASURE) {
		staSystem = MEMORY;
		memory_dis = 1;
	}
	
	else if(staSystem == MEMORY) { //回到测量界面
		staSystem = MEASURE;
		surface[5] = read24c02(addr)/100%10; surface[6] = read24c02(addr)/10%10; surface[7] = read24c02(addr)%10;
	}
}


void key_s4() {
	if(staSystem != SETTING) { //切换到设置页面
		staSystem = SETTING;
		surface[0] = 17;
		surface[1] = 14; surface[2] = 14; surface[3] = 14; surface[4] = 14; surface[5] = 14; surface[6] = 14; surface[7] = 0;
		setting = read24c02(114); //初始化setting为上一次的保存值
		//write24c02(114, 0);
	}
	
	else if(staSystem == SETTING) { //保存设置，切换回测距显示页面
		write24c02(114, setting);
		surface[5] = read24c02(addr)/100%10; surface[6] = read24c02(addr)/10%10; surface[7] = read24c02(addr)%10;
		staSystem = MEASURE;
	}
	
}


void key_s5() {
	if(staSystem == MEMORY) {
		memory_dis++;
		if(memory_dis == 5) memory_dis = 1;
	}
	
	if(staSystem == SETTING) {
		setting += 10;
		if(setting == 40) setting = 0;
	}
}


/*按键驱动*/
void KeyAction(uint8 keycode)
{
	switch (keycode)
	{
		case 0x0d: key_s2(); break;	
		case 0x26: key_s3(); break;	
		case 0x28: key_s4(); break;	
		case 0x1b: key_s5(); break;	
		default: break;
	}
}