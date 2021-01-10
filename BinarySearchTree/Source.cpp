#include <conio.h>
#include <stdio.h>
#include <iostream>


using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
}*start, * p;


node* SearchBST(node* currentNode, int n)
{
	node* lastLeaf = new node;

	while (currentNode != NULL)
	{
		lastLeaf = currentNode;

		if (currentNode->data == n)
		{
			return currentNode;
		}

		else if (currentNode->data > n)
		{
			currentNode = currentNode->left;
		}

		else
		{
			currentNode = currentNode->right;
		}

		p = lastLeaf;
	}

	return lastLeaf;
}

void insertBST(node* currentNode, int n)
{
	currentNode = SearchBST(currentNode, n);

	node* square = new node;
	square->left = square->right = NULL;
	square->data = n;

	if (start == NULL)
	{
		start = square;
	}

	else if (currentNode->data > n)
	{
		currentNode->left = square;
	}

	else if (currentNode->data < n)
	{
		currentNode->right = square;
	}

	else
	{
		cout << "\nValue is existed : " << currentNode->data << endl;
	}
}

node* findMinimumValueInRightSide(node* currentNode)
{
	while (currentNode && currentNode->left != NULL)
	{
		currentNode = currentNode->left;
	}

	return currentNode;
}

void deleteBST(node* currentNode, int n)
{
	currentNode = SearchBST(currentNode, n);

	if (currentNode->data == n) //node is existed
	{
		if (currentNode->left == NULL && currentNode->right == NULL) //node has no children
		{
			if (p->data < currentNode->data)
			{
				p->right = NULL;
			}

			else if (p->data > currentNode->data)
			{
				p->left = NULL;
			}

			delete currentNode;
		}

		else if (currentNode->left != NULL && currentNode->right == NULL) //node has a left child
		{
			if (p->data < currentNode->data)
			{
				p->right = currentNode->left;
			}

			else if (p->data > currentNode->data)
			{
				p->left = currentNode->left;
			}

			delete currentNode;
		}

		else if (currentNode->right != NULL && currentNode->left == NULL) //node has a right child
		{
			if (p->data < currentNode->data)
			{
				p->right = currentNode->right;
			}

			else if (p->data > currentNode->data)
			{
				p->left = currentNode->right;
			}

			delete currentNode;
		}

		else // node has two children
		{
			node* root = new node;
			root = currentNode;


			currentNode = findMinimumValueInRightSide(currentNode->right);
			int x = currentNode->data;

			deleteBST(start, x);

			root->data = x;
		}
	}

	else
	{
		cout << "\nThe programm didn't find your value\n";
	}
}


int inorderBSTShow(node* currentNode)
{
	while (currentNode != NULL)
	{
		inorderBSTShow(currentNode->left);
		cout << currentNode->data << "  ";
		inorderBSTShow(currentNode->right);
		return 1;
	}
}


int postorderBSTShow(node* currentNode)
{
	while (currentNode != NULL)
	{
		postorderBSTShow(currentNode->left);
		postorderBSTShow(currentNode->right);
		cout << currentNode->data << "  ";
		return 1;
	}
}

int preorderBSTShow(node* currentNode)
{
	while (currentNode != NULL)
	{
		cout << currentNode->data << "  ";
		preorderBSTShow(currentNode->left);
		preorderBSTShow(currentNode->right);
		return 1;
	}
}

int main()
{
	//insertBST(start, 9);
	//deleteBST(start, 19);
	//inorderBSTShow(start);
	//postorderBSTShow(start);
	//preorderBSTShow(start);

	return 1;
}