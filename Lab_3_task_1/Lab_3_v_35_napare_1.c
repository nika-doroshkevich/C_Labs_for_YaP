#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
int main()
{
	char s[100];
	int k;
	printf("Enter a sentance: \n");
	gets(s);
	k = strlen(s);

	for (int i = 0; i  < k; i++)
	{	
		if (i==0 || s[i-1] == ' ')
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] + 'A' - 'a';
		}
	}
	printf("%s \n", s);
}