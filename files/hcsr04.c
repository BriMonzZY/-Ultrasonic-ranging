#include "config.h"
#include "main.h"
#include "iic.h"

char buf[32];
float S;

void Mydelay(uint i)//i*10us ��ʱ
{ 
	uint z = 922;
	i = z*i;
	while(i != 0){i--;}
}

void delay(uint z)//1ms ��ʱ
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


void init()//��ʼ������
{
	TMOD |= 0X01; //�� T0 Ϊ��ʽ 1�� GATE=1��
	TH0=0;
	TL0=0;	
	EA=1; //�������ж�
	ET0=1; //���� T0 �ж�
	TR0=0;
	TRIG = 0;
}

void StartModule() //����ģ��
 {
 	TRIG = 1;
	Mydelay(2);//20us����ʱ��֤�ߵ�ƽ����ʱ���㹻������ģ��
	TRIG = 0;
}
 

void Conut(void) //�������
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
	uchar temp_dis; //�洢��һ�ξ���
	StartModule();
	while(!ECHO); //�� ECHO Ϊ��ʱ�ȴ�
	TR0=1; //��������
	while(ECHO); //�� ECHOΪ 1 �������ȴ�
	TR0=0; //�رռ���
	Conut(); //����
	TH0=0;	 //��������λ׼����һ�μ���
	TL0=0; 
	sprintf(buf,"S=%f\r\n",S);
	sendMes(buf);
	
	//�������ݵ������
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