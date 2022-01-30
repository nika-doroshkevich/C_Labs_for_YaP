#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE *f1, *f2;

	char sEnt[100];
	char *eStr;

	f1 = fopen("f1.txt", "r");
	eStr = fgets(sEnt, sizeof(sEnt), f1);
	fclose(f1);

	int len = 0;
	for (int i = 0; sEnt[i] != 0; i++)
		len++;
	char mas[100];
	int k = 0;
	int flag;

	mas[0] = sEnt[0];
	for (int i = 0; i < len; i++)
	{
		flag = 1;
		for (int j = 0; mas[j] != 0; j++)
			if (sEnt[i] != mas[j])
				flag = flag && 1;
			else
				flag = flag && 0;

		if (flag == 1)
		{
			k++;
			mas[k] = sEnt[i];
		}
	}
	k++;
	char temp[1];

	for (int i = 0; i < k - 1; i++)
		for (int j = 0; j < k - i - 1; j++)
			if (mas[j] > mas[j + 1])
			{
				temp[0] = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp[0];
			}

	mas[k] = 0;

	f2 = fopen("f2.txt", "w");
	fputs(mas, f2);
	fclose(f2);
	//cbacbadhwtvcba
	return 0;
}