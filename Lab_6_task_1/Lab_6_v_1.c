#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE *f1, *f2;

	int mas[10] = { 4, -6, 7, 9, 0, -4, -2, 5, -1, 8 };
	int masEnt[10], masF2[10];
	int nNum = 0;

	f1 = fopen("f1.txt", "a+");
	for (int i = 0; i < 10; i++)
		fprintf(f1, "%d ", mas[i]);
	fclose(f1);

	f1 = fopen("f1.txt", "r");
	while (fscanf(f1, "%d", &masEnt[nNum]) != EOF)
		nNum++;
	fclose(f1);

	int k = 0;
	for (int i = 0; i < 10; i++)
		if (masEnt[i] > 0)
		{
			masF2[k] = masEnt[i];
			k++;
		}

	f2 = fopen("f2.txt", "w");
	for (int i = 0; i < k; i++)
		fprintf(f2, "%d ", masF2[i]);
	fclose(f2);

	return 0;
}