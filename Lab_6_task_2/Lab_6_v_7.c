#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE *f1, *f2;
	struct TStudents
	{
		char name[50];
		int res;
	};

	struct TStudents masSt[100];
	int masIndMin[100], masIndMax[100];
	
	int nWord = 0;

	f1 = fopen("f1.txt", "r");
	while (fscanf(f1, "%s %d", masSt[nWord].name, &(masSt[nWord].res)) != EOF)
		nWord++;
	fclose(f1);

	int k = 0, m = 0;
	for(int i = 0; i < nWord; i++)
		if (masSt[i].res < 4)
		{
			masIndMin[k] = i;
			k++;
		}
		else
		{
			masIndMax[m] = i;
			m++;
		}
	
	f2 = fopen("f2.txt", "w");
	for (int i = 0; i < m; i++)
		fprintf(f2, "%s %d\n", masSt[masIndMin[i]].name, masSt[masIndMin[i]].res);
	fclose(f2);

	f1 = fopen("f1.txt", "w");
	for (int i = 0; i < m; i++)
		fprintf(f1, "%s %d\n", masSt[masIndMax[i]].name, masSt[masIndMax[i]].res);
	fclose(f1);

	return 0;
}