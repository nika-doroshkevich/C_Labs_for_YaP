#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
int main()
{
	char s[100];
	char masLet[100];
	int	 masNum[100];
	int curNumLet = 0, curNumNum = 0, num;
	printf("Enter a string: \n");
	gets(s);
	int k = strlen(s);
	for (int i = 0; i < k; i++)
		if (s[i] > '0' && s[i] < '9')
		{
			num = (s[i] - '0') % 2;
			if (num == 0)
			{
				masNum[curNumNum] = s[i] - '0';
				curNumNum++;
			}
		}
		else
		{
			masLet[curNumLet] = s[i];
			curNumLet++;
		}

	for (int i = 0; i < curNumLet; i++)
	{
		printf("%c", masLet[i]);
		printf("%d", masNum[i]);
	}
	//qwer12345678
}