#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double det(int* p)   //<-----Self created function and Pointer(Actually this thing makes my life a little more complicate than it should be....)
{
	int up1 = (*(p + 2)) * (*(p + 6)) * (*(p + 10))*(-1);
	int up2 = (*(p + 3)) * (*(p + 7)) * (*(p + 11))*(-1);
	int up3 = (*(p + 4)) * (*(p + 8)) * (*(p + 12))*(-1);
	int down3 = (*(p + 14)) * (*(p + 8)) * (*(p + 2));		
	int down2 = (*(p + 13)) * (*(p + 7)) * (*(p + 1));
	int down1 = (*(p + 12)) * (*(p + 6)) * (*(p + 0));
	printf("Up1     = (%dx%dx%d)x-1 = %d\n", *(p + 10), *(p + 6), *(p + 2), up1);
	printf("Up2     = (%dx%dx%d)x-1 = %d\n", *(p + 11), *(p + 7), *(p + 3), up2);
	printf("Up3     = (%dx%dx%d)x-1 = %d\n", *(p + 12), *(p + 8), *(p + 4), up3);
	printf("Down1   = (%dx%dx%d)    = %d\n", *(p + 0), *(p + 6), *(p + 12),down1);
	printf("Down2   = (%dx%dx%d)    = %d\n", *(p + 1), *(p + 7), *(p + 13), down2);
	printf("Down3   = (%dx%dx%d)    = %d\n", *(p + 2), *(p + 8), *(p + 14), down3);
	int sumdown = down1 + down2 + down3;
	printf("sumdown = (%d) + (%d) + (%d) = %d\n", down1,down2,down3,sumdown);
	int sumup = up1 + up2 + up3;
	printf("Sumup   = (%d) + (%d) + (%d) = %d\n",up1,up2,up3, sumup);
	int sum = sumup + sumdown;
	printf("Det     = (%d) + (%d) = %d\n", sumup,sumdown,sum);
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
	printf("\nSolution\n");
	int de = det(&cx[0][0]);
	printf("\nDet : %d\n",de);
	return 0;
}