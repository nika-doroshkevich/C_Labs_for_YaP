#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>

typedef struct Node
{
	int color;
	struct Node* next;
} Node;

Node* push(Node* head, int color)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->color = color;
	temp->next = head;
	head = temp;
	return head;
}

void print(Node* head)
{
	for (Node* t = head; t != NULL; t = t->next)
	{
		if (t->color == 0)
			printf("Red ");
		if (t->color == 1)
			printf("White ");
		if (t->color == 2)
			printf("Blue ");
	}
}

void bubbleSort(Node* list) 
{
	Node* p = NULL;

	if (list != NULL) {
		while (list->next != NULL) 
		{
			p = list->next;

			do 
			{
				if (p->color < list->color) 
				{
					int tmp = p->color;
					p->color = list->color;
					list->color = tmp;
				}

				p = p->next;
			} while (p != NULL);

			list = list->next;
		}
	}
}

int main()
{
	Node* head = NULL;

	//Red - 0
	//White - 1
	//Blue -2

	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 2);
	head = push(head, 0);
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 1);
	head = push(head, 0);
	head = push(head, 1);
	head = push(head, 2);

	print(head);
	printf("\n");

	bubbleSort(head);

	print(head);
	
	return 0;
}