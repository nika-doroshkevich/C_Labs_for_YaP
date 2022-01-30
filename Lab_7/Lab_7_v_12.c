#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>
int main()
{
	FILE * file, * fForDep;
	struct TEmployees
	{
		char name[50];
		char dep[20];
		int salary;
	};

	struct TEmployees masInit[100];
	int masIndMin[100], masIndMax[100];

	int nWord = 0;

	file = fopen("file.txt", "r");
	while (fscanf(file, "%s %s %d", masInit[nWord].name, &(masInit[nWord].dep), &(masInit[nWord].salary)) != EOF)
		nWord++;
	fclose(file);
	nWord--;
	printf("1 - Exit\n");
	printf("2 - Add employee\n");
	printf("3 - Remove employee\n");
	printf("4 - Edit employee data\n");
	printf("5 - The total amount of payments and the average monthly earnings by department\n");
	
	int choice = 0;
	char newName[50], newDep[20];
	int newSalary;

	while (choice != 1)
	{
		scanf("%d", &choice);
		if (choice == 2)
		{
			printf("Add employee:\n");
			printf("Last name Department Salary\n");
			nWord++;
			scanf("%s %s %d", &masInit[nWord].name, &masInit[nWord].dep, &masInit[nWord].salary);

			file = fopen("file.txt", "w");
			for (int i = 0; i <= nWord; i++)
				fprintf(file, "%s\n%s\n%d\n", masInit[i].name, masInit[i].dep, masInit[i].salary);
			fclose(file);
		}

		if (choice == 3)
		{
			int Deli = 0;
			printf("Remove employee:\n");
			printf("Last name\n");
			char DelName[50];
			scanf("%s", &DelName);

			for (int i = 0; i <= nWord; i++)
			{
				if (strcmp(masInit[i].name, DelName) == 0)
					Deli = i;
			}

			for (int j = Deli; j <= nWord - 1; j++)
				masInit[j] = masInit[j + 1];
			nWord--;

			file = fopen("file.txt", "w");
			for (int i = 0; i <= nWord; i++)
				fprintf(file, "%s\n%s\n%d\n", masInit[i].name, masInit[i].dep, masInit[i].salary);
			fclose(file);	
		}

		if (choice == 4)
		{
			printf("Edit employee data:\n");
			printf("Employee's last name:\n");
			char newName[50], newDep[20], oldName[50];
			int newSalary;
			scanf("%s", &oldName);
			printf("New data (Last Name Department Salary).:\n");
			scanf("%s %s %d", &newName, &newDep, &newSalary);
			for (int i = 0; i <= nWord; i++)
			{
				if (strcmp(masInit[i].name, oldName) == 0)
				{
					strcpy(masInit[i].name, newName);
					strcpy(masInit[i].dep, newDep);
					masInit[i].salary = newSalary;
				}
			}
			file = fopen("file.txt", "w");
			for (int i = 0; i <= nWord; i++)
				fprintf(file, "%s\n%s\n%d\n", masInit[i].name, masInit[i].dep, masInit[i].salary);
			fclose(file);
		}
		
		if (choice == 5)
		{
			printf("The total amount of payments and the average monthly earnings by department\n");
			int sum = 0, count = 0, medSum = 0;

			char SearchDep[20];
			printf("Enter the department:\n");
			scanf("%s", &SearchDep);

			for (int i = 0; i <= nWord; i++)
			{
				if (strcmp(masInit[i].dep, SearchDep) == 0)
				{
					sum += masInit[i].salary;
					count++;
				}	
			}
			medSum = sum / count;
			fForDep = fopen("fForDep.txt", "a");
				fprintf(fForDep, "Total amount of payments by department %s = %d\n", SearchDep, sum);
				fprintf(fForDep, "Average monthly earnings by department %s = %d\n", SearchDep, medSum);
			fclose(file);
		}
	}
	return 0;
}