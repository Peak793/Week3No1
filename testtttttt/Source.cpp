#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double det(int* p)   //<-----Self created function and Pointer(Actually this thing makes my life a little more complicate than it should be....)
{
	int up1 = (*(p + 2)) * (*(p + 6)) * (*(p + 10))*(-1);
	printf("up1 = %dx%dx%d = %d\n", *(p + 2), *(p + 6), *(p + 10), (*(p + 2)) * (*(p + 6)) * (*(p + 10)) * (-1));
	int up2 = (*(p + 3)) * (*(p + 7)) * (*(p + 11))*(-1);
	printf("up2 = %dx%dx%d = %d\n", *(p + 3), *(p + 7), *(p + 11), (*(p + 3)) * (*(p + 7)) * (*(p + 11)) * (-1));
	int up3 = (*(p + 4)) * (*(p + 8)) * (*(p + 12))*(-1);
	printf("up3 = %dx%dx%d = %d\n", *(p + 4), *(p + 8), *(p + 12), (*(p + 4)) * (*(p + 8)) * (*(p + 12)) * (-1));
	int down1 = (*(p + 14)) * (*(p + 8)) * (*(p + 2));
	printf("down1 = %dx%dx%d = %d\n", *(p + 14), *(p + 8), *(p + 2), (*(p + 14)) * (*(p + 8)) * (*(p + 2)));		
	int down2 = (*(p + 13)) * (*(p + 7)) * (*(p + 1));
	printf("down2 = %dx%dx%d = %d\n", *(p + 13), *(p + 7), *(p + 1), (*(p + 13)) * (*(p + 7)) * (*(p + 1)));
	int down3 = (*(p + 12)) * (*(p + 6)) * (*(p + 0));
	printf("down3 %dx%dx%d = %d\n", *(p + 12), *(p + 6), *(p + 0), (*(p + 12)) * (*(p + 6)) * (*(p + 0)));
	int sumdown = down1 + down2 + down3;
	printf("sumdown= %d + %d + %d = %d\n", down1,down2,down3,sumdown);
	int sumup = up1 + up2 + up3;
	printf("sumup = %d + %d + %d = %d\n",up1,up2,up3, sumup);
	int sum = sumup + sumdown;
	printf("sum= %d + %d = %d\n", sumup,sumdown,sum);
	return sum;
}
int main()
{
	int x[3][3];            //<--------- 2d array WOOHOO!
	int cx[3][5];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &x[i][j]);
			if (x[i][j] < -30 || x[i][j]>30)       //<--------expression and/or is right here!
			{
				printf("ERROR");
				return 0;
			}
		}
	}
	for (int i = 0; i < 3; i++)                     //<-------Nested loop Eiei right here!
	{
		for (int j = 0; j < 5; j++)
		{
			if (j < 3)
			{
				cx[i][j] = x[i][j];
			}
			else
			{
				cx[i][j] = x[i][j - 3];
			}
		}
	}
	printf("\n------DET------\n\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", cx[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	int de = det(&cx[0][0]);
	printf("Det : %d",de);
	return 0;
}