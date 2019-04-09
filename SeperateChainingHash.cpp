#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;
struct node
{
	int value;
	node* next;
};
void printOutList(node* h) //prints out whole list
{
	if (h == NULL)
	{
		cout << "EMPTY";
		return;
	}
	while (h!= NULL)
	{
		cout << h->value << " ";
		h = h->next;
	}
}
void showHashArray(node* A[7]) //prints out hash array
{
	for (int i = 0; i < 7; i++)
	{
		printOutList(A[i]);
		cout << endl;
	}
}
void listInsert(node *&h, int x) //inserts an element to the list
{
	node* p = new node;
	p->value = x;
	p->next = NULL;
	node* temp = h;
	if (h == NULL)
	{
		h = p;
		return;
	}
	while (temp->next!= NULL)
	{

		temp = temp->next;
	}
	temp->next = p;
	return;
}
void deleteFromList(node *&h,int x) //deletes an element from the list
{
	if (h == NULL)
	{
		return;
	}
		if (h->value == x)
		{
			node*p = h;
			h = h->next;
			delete p;
			return;
		}
	node* prev = h;
	node* temp = h->next;
	while (temp!= NULL)
	{
		if (temp->value == x)
		{
			prev->next = temp->next;
			delete temp;
			return;
		}
		prev = temp;
		temp = temp->next;
	}
}
void deleteFromHashArray(node* A[7],int x) //deletes an element from the Hash Array
{
	deleteFromList(A[x % 7],x);
}
bool existInList(node* h, int x) //checks if the element exists in the list
{
	bool exist = false;
	while (h != NULL)
	{
		if (h->value == x)
		{
			exist = true;
			break;
		}
	}
	return exist;
}
bool existInHashArray(node* A[7], int x) //checks if the element exists in the Hash Array
{
	return existInList(A[x % 7], x);
}
int main()
{
	node* A[7];
	for (int i = 0; i < 7; i++)
	{
		A[i] = NULL;
	}
	for(int i=0;i<7;i++)
	{
		int value;
		cout << "Give value to insert:";
		cin >> value;
		listInsert(A[value % 7], value);
	}
	system("cls");
	cout << "Your Hash Array:";
	cout << endl;
	showHashArray(A);
	cout << "----------------";
	cout << endl;
	cout << "Which element would you like to delete? : ";
	int value;
	cin >> value;
	deleteFromHashArray(A, value);
	system("cls");
	cout << "Your Hash Array after deletion:";
	cout << endl;
	showHashArray(A);
	cout << "Which element's egsistence would you like to check? : ";
	cin >> value;
	if (existInHashArray(A, value))
	{
		cout << value << " exist in Hash Array!";
		cout << endl;
	}
	else
	{
		cout << value << " does not exist in Hash Array";
		cout << endl;
	}
}
