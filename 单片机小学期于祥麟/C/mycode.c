#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit S0=P3^0;
sbit S1=P3^1;
sbit S2=P3^2;
sbit S3=P3^3;
void san();
void wu();
void delay(uint);
uchar temp1;
uchar temp2;
uchar temp3;
uint a;
int c;
void main()
{
    while (1)
    {
        if (S1 == 0)
        {
            san();
        }

        if (S2 == 0)
        {
            P1 = 0xff;
        }

        if (S3 == 0)
        {
            san();
        }

        if (S4 == 0)
        {
            wu();
        }
    }
}

void san()
{
    uchar table[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
    int a;
    for (a = 0; a < 8; a++)
    {
        temp1 = table[a];
        P1 = temp1;
        delay(300);
    }
}

void delay(uint z)
{
    unsigned char x, y;
    for (x = 100; x > 0; x--)
        for (y = z; y > 0; y--)
            ;
}

void wu()
{
    uchar table1[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
    int c;
    for (c = 7; c > -1; c--)
    {
        temp2 = table1[c];
        P1 = temp2;
        delay(300);
    }
}