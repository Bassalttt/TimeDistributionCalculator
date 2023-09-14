/*=========================================
�ɶ����έp��� ²����
�o�O�ӥi�H�p��v�����ήɶ����p�{��
�@��:Elin
�}�o�ɶ�:2017/12/31 14:53
����:v1.0.0
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
		printf("���\��|���}��A���R�ݤU����s�C\n");
	}
	fontcolor(7);
	return;
}

void warning()
{
	printf("�o�O�ӥi�H�p��v�����ήɶ����{���C\n");
	fontcolor(12);
	printf("�`�N1:���{���ȥΧ@�p��A�Y�n���μv���A�ШϥΧO���{���C\n");
	printf("�`�N2:�Ҧ��ɶ��ХH");
	fontcolor(236);
	printf("��:��:��");
	fontcolor(12);
	printf("(�b��)�覡��J�C\n");
	fontcolor(7);
	printf("�Ш̧ǿ�J�_�l�ɶ�.�����ɶ�.���άq����\n\n");
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
		printf("��%d�q�A�q ", i);//show the begining of a part in Hr:Min:Sec way
		toHrMinSec(time[1]);
		printf(" �� ");
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
	printf("�п�J���άq��:");
	scanf("%d",&part);
	
	printf("�O�_�n��������(Y/N):");
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
	{printf("��J���~\n");}*/
	return;
}

int main(void)
{
	int strtTm[4] = { 0 }, endTm[4] = { 0 };
	fontcolor(63);
	printf("�ɶ����έp���  ²���� v1.0.0\n\n");
	fontcolor(7);
	warning();

	printf("�п�J�_�l�ɶ�:");
	scanf("%d:%d:%d", &strtTm[0], &strtTm[1], &strtTm[2]);
	strtTm[4] = strtTm[0] * 3600 + strtTm[1] * 60 + strtTm[2];
	printf("�п�J�����ɶ�:");
	scanf("%d:%d:%d", &endTm[0], &endTm[1], &endTm[2]);
	endTm[4] = endTm[0] * 3600 + endTm[1] * 60 + endTm[2];

	cut(strtTm[4], endTm[4]);

	printf("\n");
	system("pause");
	return 0;
}
