#include <reg52.h>

#define uchar unsigned char //宏定义
#define uint unsigned int

sbit k1 = P3 ^ 2; //位定义
sbit k2 = P3 ^ 3;
sbit k3 = P3 ^ 4;
sbit k4 = P3 ^ 5;

uchar a = 0;                                                            //定义所需变量
uchar k = 0;                                                            //开关状态
uchar code table1[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f}; //从上到下流水数组
uchar code table2[] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe}; //从下到上流水数组

void delay_ms(uint xms) //延时函数
{
    uint i, j;
    for (i = xms; i > 0; i--)
        for (j = 110; j > 0; j--)
            ;
}

void key() //判断开关状态
{
    if (k1 == 0)
    {
        k = 1;
    }
    if (k2 == 0)
    {
        k = 2;
    }
    if (k3 == 0)
    {
        k = 3;
    }
    if (k4 == 0)
    {
        k = 4;
    }
}

void shangdaoxia() //上到下循环点亮
{
    while (k2 == 1 && k3 == 1 && k4 == 1)
    {
        for (a = 0; a < 8; a++) //执行从上到下流水操作
        {
            P1 = table1[a];
            delay_ms(100);
        }
        a = 0;
    }
}

void xiadaoshang() //下到上循环点亮
{
    while (k1 == 1 && k2 == 1 && k4 == 1)
    {
        for (a = 0; a < 8; a++) //执行从下到上流水操作
        {
            P1 = table2[a];
            delay_ms(100);
        }
        a = 0;
    }
}

void ledoff() //P1口置1
{
    while (k1 == 1 && k3 == 1 && k4 == 1)
    {
        P1 = 0xff; //P0全部输出高电平，关闭LED
    }
}

void main() //主函数
{
    while (1)
    {
        key();
        if (k == 1)
        {
            shangdaoxia();
        }
        if (k == 2)
        {
            ledoff();
        }
        if (k == 3)
        {
            xiadaoshang();
        }
        if (k == 4)
        {
            shangdaoxia();
        }
    }
}