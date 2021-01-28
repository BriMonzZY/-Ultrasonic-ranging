#include "config.h"
#include "main.h"
#include "iic.h"

char buf[32];
float S;

void Mydelay(uint i)//i*10us 延时
{ 
	uint z = 922;
	i = z*i;
	while(i != 0){i--;}
}

void delay(uint z)//1ms 延时
{ uint x,y;
	for(x=z;x>0;x--)
	for(y=110;y>0;y--);
}

void senddelay(unsigned long time){
	int i = 0;
	int j = 0;
	for(i = 0;i<100;i++){
		for(j = 0;j<time;j++);
	}
}


void init()//初始化函数
{
	TMOD |= 0X01; //设 T0 为方式 1， GATE=1；
	TH0=0;
	TL0=0;	
	EA=1; //开启总中断
	ET0=1; //允许 T0 中断
	TR0=0;
	TRIG = 0;
}

void StartModule() //启动模块
 {
 	TRIG = 1;
	Mydelay(2);//20us的延时保证高电平持续时间足够来启动模块
	TRIG = 0;
}
 

void Conut(void) //计算距离
{	
	uint time;
	time=TH0*256+TL0;
	TH0=0;
	TL0=0;
	S=(time*1.7)/100;
}

void sendsingle(char single){ 		
	SBUF = single;
	while(TI != 1);
	TI = 0;
}

void sendMes(char *p)
{
	while( *p != '\0'){
	sendsingle(*p);
	p++;
	} 
	 senddelay(100);
}




void get_distance() {
	uchar temp_dis; //存储上一次距离
	StartModule();
	while(!ECHO); //当 ECHO 为零时等待
	TR0=1; //开启计数
	while(ECHO); //当 ECHO为 1 计数并等待
	TR0=0; //关闭计数
	Conut(); //计算
	TH0=0;	 //计数器复位准备下一次计数
	TL0=0; 
	sprintf(buf,"S=%f\r\n",S);
	sendMes(buf);
	
	//处理数据到数码管
	dis = (int)S;
	surface[2] = dis/100%10;
	surface[3] = dis/10%10;
	surface[4] = dis%10;
	
	if(addr == 110) {
		temp_dis = read24c02(113);
	}
	if(addr == 113) {
		temp_dis = read24c02(112);
	}
	if(addr == 111) {
		temp_dis = read24c02(110);
	}
	if(addr == 112) {
		temp_dis = read24c02(111);
	}
	
	surface[5] = temp_dis/100%10;
	surface[6] = temp_dis/10%10;
	surface[7] = temp_dis%10;
}