#include <iostream>
#include "Menu.h"
using namespace std;
int mainMenu()
{
	cout << "1.Binary Search Tree" << endl;
	cout << "2.AVL Tree" << endl;
	cout << "3.Exit" << endl;
	int op;
	cout << "Your Option : ";
	cin >> op;
	return op;
}
void clearScreen()
{
	system("pause");
	system("cls");
}
int loadRecordMenu()
{
	cout << "1.Load 100 records" << endl;
	cout << "2.Load 1000 records" << endl;
	cout << "3.Load 10000 records" << endl;
	cout << "4.Load 100000 records" << endl;
	cout << "5.Back" << endl;
	int op;
	cout << "Your Option : ";
	cin >> op;
	return op;
}
int traverseMenu()
{
	cout << "1.Breadth First Traversal" << endl;
	cout << "2.InOrder Traversal" << endl;
	cout << "3.PostOrder Traversal" << endl;
	cout << "4.PreOrder Traversal" << endl;
	cout << "5.Back" << endl;
	int op;
	cout << "Your Option : ";
	cin >> op;
	return op;
}
int crudOperationsMenu()
{
	cout << "1.Insert a New Record" << endl;
	cout << "2.Retrieve a Record" << endl;
	cout << "3.Update a Record" << endl;
	cout << "4.Delete a Record" << endl;
	cout << "5.Traverse a Tree" << endl;
	cout << "6.Back" << endl;
	int op;
	cout << "Your Option : ";
	cin >> op;
	return op;
}