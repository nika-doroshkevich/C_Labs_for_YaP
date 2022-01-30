#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE* goods;
	struct TGoods
	{
		char name[50];
		char num[50];
		char date[50];
	};

	struct TGoods masGd[100];

	int nGood = 0;

	goods = fopen("goods.txt", "r");

	while (fscanf(goods, "%s%s%s", masGd[nGood].name, &(masGd[nGood].num), &(masGd[nGood].date)) != EOF)
		nGood++;

	fclose(goods);

	char firstN[1], secondN[1];

	for (int i = 0; i < nGood; i++)
	{
		firstN[0] = masGd[i].date[3];
		secondN[0] = masGd[i].date[4];
		if (firstN[0] == '0' && secondN[0] == '2')
			printf("%s %s %s \n", masGd[i].name, masGd[i].num, masGd[i].date);
	}
}