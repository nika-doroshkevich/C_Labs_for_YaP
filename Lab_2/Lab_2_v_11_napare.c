#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int arr[10][10];
	int i, j, n, min1, min2;

	printf("Enter the size of the matrix: \n");
	scanf("%d", &n);
	printf("Matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", arr[i][j] = rand() % 10);
		printf("\n");
	}
	printf("\n");

	//With initialized matrix
	/*int arr[5][5] = { {3, 5, 4, 5, 8}, {5, 7, 3, 9, 5}, {2, 8, 9, 2, 5}, {5, 7, 3, 2, 3},  {2, 8, 9, 4, 2} };
	int i, j, n, min1, min2;
	printf("Enter the size of the matrix: \n");
	scanf("%d", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}*/

	min1 = arr[0][0];
	for (int i = 0; i < n; i++) 
		for (int j = min(i, n - 1 - i); j <= max(i, n - 1 - i); j++)
			if (arr[i][j] < min1)
				min1 = arr[i][j];
	printf("0 0 0 0 0 \n");
	printf("| 0 0 0 | \n");
	printf("| | 0 | | \n");
	printf("| 0 0 0 | \n");
	printf("0 0 0 0 0 \n");
	printf("Minimum element in part with 0: \n");

	printf("%d ", min1);
	printf("\n");
	printf("\n");
	min2 = arr[0][0];
	for (int i = 0; i < n; i++)
		for (int j = (i, n - 1 - i); j <= max(i, n - 2 - i); j++)
			if (arr[j][i] < min2)
				min2 = arr[j][i];
	printf("| | | | 0 \n");
	printf("| | | 0 0 \n");
	printf("| | 0 0 0 \n");
	printf("| | | 0 0 \n");
	printf("| | | | 0 \n");
	printf("Minimum element in part with 0: \n");

	printf("%d ", min2);
	printf("\n");

	//Matrix output
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}*/
}