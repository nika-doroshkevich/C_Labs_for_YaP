#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
int main()
{
	char s[100];
	char mas[100][100];
	int curLen=0, countW =0, minInd, maxInd;
	printf("Enter a string: \n");
	gets(s);
	int k = strlen(s);
	
	minInd = 100;
	maxInd = 0;

	for (int i = 0; i < k+1; i++)
	{
		if (s[i] == ' ' || s[i] == '\0')
		{
			mas[countW][curLen] = '\0';
			minInd = (strlen(mas[minInd]) > curLen) ? countW : minInd;
			maxInd = (strlen(mas[maxInd]) < curLen) ? countW : maxInd;
			countW++;
			curLen = 0;
		}
		else
			mas[countW][curLen++] = s[i];
	}
	
	char sTemp[100];
	strcpy(sTemp, mas[maxInd]);
	strcpy(mas[maxInd], mas[minInd]);
	strcpy(mas[minInd], sTemp);

	for (int i = 0; i < countW; i++)
		printf("%s ", mas[i]);
}