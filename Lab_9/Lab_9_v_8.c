#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <conio.h>
#include <stdlib.h>

struct tree
{
	int key;
	struct tree* left;
	struct tree* right;
};
typedef struct tree TreeNode;
typedef TreeNode* Tree;

Tree Root = NULL;

void add(int key)
{
	Tree r = (Tree)malloc(sizeof(TreeNode));
	r->key = key;
	r->left = NULL;
	r->right = NULL;
	if (Root == NULL) 
	{
		Root = r;
		return;
	}

	Tree temp = Root;
	while (1) 
	{
		if (temp->key == key)
			return;

		if (key < temp->key)
			if (temp->left != NULL)
				temp = temp->left;
			else 
			{
				temp->left = r;
				return;
			}
			
		if (temp->right != NULL)
			temp = temp->right;
		else 
		{
			temp->right = r;
			return;
		}
	}
}

void print(Tree r, int l)
{
	if (r == NULL)  
		return;

	print(r->right, l + 1);

	for (int i = 0; i < l; i++)  
		printf("    ");
	
	printf("%d\n\n", r->key);
	print(r->left, l + 1);	
}

int potomki(Tree r)
{
	int kol = 0;
	if (!r) return 0;
	if ((r->left == NULL) ^ (r->right == NULL))
		kol = 1;
	return kol + potomki(r->left) + potomki(r->right);
}

int main()
{
	add(6);
	add(2);
	add(19); 
	add(4);
	add(15);
	add(3);
	add(5);
	add(16);
	add(12);
	
	
	print(Root, 0);

	int potomkiNum = potomki(Root);
	printf("\n");
	printf("Number of nodes with one child: %d\n", potomkiNum);

	return 0;
}