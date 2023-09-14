/*=========================================
時間分割計算機 簡易版
這是個可以計算影片分割時間的小程式
作者:Elin
開發時間:2017/12/31 14:53
版本:v1.0.0
=========================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void fontcolor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return;
}

void notYet()
{
	int i = 0;
	fontcolor(112);
	for (i = 0; i < 5; i++)
	{
		printf("此功能尚未開放，請靜待下次更新。\n");
	}
	fontcolor(7);
	return;
}

void warning()
{
	printf("這是個可以計算影片分割時間的程式。\n");
	fontcolor(12);
	printf("注意1:本程式僅用作計算，若要分割影片，請使用別的程式。\n");
	printf("注意2:所有時間請以");
	fontcolor(236);
	printf("時:分:秒");
	fontcolor(12);
	printf("(半形)方式輸入。\n");
	fontcolor(7);
	printf("請依序輸入起始時間.結束時間.分割段落數\n\n");
	return;
}

void toHrMinSec(int time)
{
	int i;
	int hrMinSec[3];
	hrMinSec[0] = time / 3600;//hour
	hrMinSec[1] = (time % 3600) / 60;
	hrMinSec[2] = time % 60;
	fontcolor(11);
	(hrMinSec[0]<10) ? (printf("0%d:", hrMinSec[0])) : (printf("%d:", hrMinSec[0]));
	(hrMinSec[1]<10) ? (printf("0%d:", hrMinSec[1])) : (printf("%d:", hrMinSec[1]));
	(hrMinSec[2]<10) ? (printf("0%d", hrMinSec[2])) : (printf("%d", hrMinSec[2]));
	fontcolor(7);
	return;
}

void avgCut(int bgn, int end, int part, double wholeTm)//average cutting
{
	double time[3] = { 0 };
	int i;
	time[0] = wholeTm / part;//time in a part
	time[1] = bgn;//begining of the first part

	for (i = 1; i <= part; i++)
	{
		time[2] = time[1] + time[0];//ending of a part = begining of a part + during time
		printf("第%d段，從 ", i);//show the begining of a part in Hr:Min:Sec way
		toHrMinSec(time[1]);
		printf(" 到 ");
		if (i == part)
		{
			toHrMinSec(end);
		}
		else
		{
			toHrMinSec(time[2]);
			time[1] = time[2];
		}
		printf("\n");
	}
	return;
}
void nonaC()//nonaverage cutting
{
	notYet();
	return;
}

void cut(int bgn, int end)//Starting to cut
{
	int part;
	double wholeTime;
	int ans = 0;
	int i;
	char yn;
	
	wholeTime= end - bgn;//whole time
	printf("請輸入分割段數:");
	scanf("%d",&part);
	
	printf("是否要平均分割(Y/N):");
	yn=getchar();
	putchar(yn);
	//yn=strupr(yn); 
	/*if(strupr(yn)=='Y'||"YE"||"YES")
	{printf("YES");}
	/*else if(strupr(yn)=='N'||"NO")
	{printf("NO");}*/
	//else
	
	//scanf("%d", &ans);
	/*if (ans == 1)
	{
		printf("\n");
		avgCut(bgn, end, part, wholeTime);
	}
	else if (ans == 0)
	{nonaC();}
	else
	{printf("輸入錯誤\n");}*/
	return;
}

int main(void)
{
	int strtTm[4] = { 0 }, endTm[4] = { 0 };
	fontcolor(63);
	printf("時間分割計算機  簡易版 v1.0.0\n\n");
	fontcolor(7);
	warning();

	printf("請輸入起始時間:");
	scanf("%d:%d:%d", &strtTm[0], &strtTm[1], &strtTm[2]);
	strtTm[4] = strtTm[0] * 3600 + strtTm[1] * 60 + strtTm[2];
	printf("請輸入結束時間:");
	scanf("%d:%d:%d", &endTm[0], &endTm[1], &endTm[2]);
	endTm[4] = endTm[0] * 3600 + endTm[1] * 60 + endTm[2];

	cut(strtTm[4], endTm[4]);

	printf("\n");
	system("pause");
	return 0;
}
