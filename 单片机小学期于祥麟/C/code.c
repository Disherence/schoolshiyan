#include<reg52.h>
#include<intrins.h>  //包含循环左、右移位函数的头文件（_crol_, _cror_）
sbit S1=P1^0;
sbit S2=P1^1;
sbit S3=P1^2;
unsigned char keyval;    
void key_scan(void);    //按键扫描，取键值
void forward(void);       //从上到下闪烁
void backward(void);         //从下到上闪烁
void middleward(void);      //从中间到两边，再从两边到中间
void delay10ms(void);   //按键扫描延时，防抖动
void led_delay(void);
void main(void)
{
    keyval=0;			  //键盘初始化为0
        while(1)
        {
           key_scan();		//调用键盘扫描函数
           switch(keyval)
           {
               case 1:forward();			 //键值为1，从上到下闪烁
                   break;
               case 2:backward();			 //键值为2，从下到上闪烁
                   break;
			   case 3:middleward();			  //键值为3，从中间到两边，再从两边到中间
                   break;
           }
        }
}
void key_scan(void)
{
    P1=0xff;
        if((P1&0x0f)!=0x0f)		//检测到有键按下
        {
           delay10ms();
           if(S1==0)
           keyval=1;
           if(S2==0)
           keyval=2;
		   if(S3==0)
           keyval=3;
    }
}
void forward(void)
{
   P2=0xfe;		    //1
   led_delay();
   P2=0xfd;			//2
   led_delay();
   P2=0xfb;			//3
   led_delay();
   P2=0xf7;			//4
   led_delay();
   P2=0xef;			//5
   led_delay();
   P2=0xdf;			//6
   led_delay();
   P2=0xbf;			//7
   led_delay();
   P2=0x7f;			//8
   led_delay();
}

void backward(void)
{
    P2=0x7f;			//8
	led_delay();
    P2=0xbf;			//7
	led_delay();
	P2=0xdf;			//6
	led_delay();
	P2=0xef;			//5
	led_delay();
	P2=0xf7;			//4
	led_delay();
	P2=0xfb;			//3
	led_delay();
	P2=0xfd;			//2
	led_delay();
	P2=0xfe;		    //1
	led_delay();
}

void middleward(void)
{
	 P2=0xe7;
	 led_delay();
	 P2=0xdb;
	 led_delay();
	 P2=0xbd;
	 led_delay();
	 P2=0x7e;
	 led_delay();
	 P2=0xbd;
	 led_delay();
	 P2=0xdb;
	 led_delay();
}
void led_delay(void)
{
    unsigned char i,j;
        for(i=0;i<220;i++)
        for(j=0;j<220;j++);
}
  
void delay10ms(void)
{   
    unsigned char i,j;
        for(i=0;i<100;i++)
        for(j=0;j<100;j++);
}
