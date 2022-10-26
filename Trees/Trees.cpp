#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <time.h>
#include "TreeMaker.h"
#include "Menu.h"
#include "NodeUI.h"
//										Functions Declaretions
void crudOperations(int);
string parse(string, int);
TreeMaker* loadData(string, int);
void traverseTree();
TreeMaker* tree;
//										Function Definations
int main()
{
	system("cls");

	string datafile100 = "customers-100.csv";
	string datafile1000 = "customers-1000.csv";
	string datafile10000 = "customers-10000.csv";
	string datafile100000 = "customers-100000.csv";
	while (true)
	{
		int option = mainMenu();
		if (option == 1 || option == 2)
		{
			clearScreen();
			while (true)
			{
				int op = loadRecordMenu();
				if (op == 1)
				{
					tree = loadData(datafile100, option);
				}
				else if (op == 2)
				{
					tree = loadData(datafile1000, option);
				}
				else if (op == 3)
				{
					tree = loadData(datafile10000, option);
				}
				else if (op == 4)
				{
					tree = loadData(datafile100000, option);
				}
				else if (op == 5)
				{
					break;
				}
				else
				{
					cout << "Invalid Option.\nTry Again" << endl;
					clearScreen();
					continue;
				}
				clearScreen();
				crudOperations(option);
				clearScreen();
			}
		}
		else if (option == 3)
		{
			cout << "Thanks For Using..." << endl;
			clearScreen();
			break;
		}
		else
		{
			cout << "Invalid Option.\nTry Again" << endl;
		}
		clearScreen();
	}
}
void crudOperations(int option)
{
	clock_t start, end;
	while (true)
	{
		int op = crudOperationsMenu();
		if (op == 1)
		{
			cout << "Enter Details: " << endl;
			TreeNode* temp = tree->insertRecord();
			start = clock();
			if (temp != NULL)
			{
				tree->insertionWithRotation(temp, option);
			}
			else
			{
				cout << "Node Already Available with This Index." << endl;
			}
			end = clock();
			double time = double(end - start) / double(CLOCKS_PER_SEC);
			cout << time << " sec Taken." << endl;
		}
		else if (op == 2)
		{
			int index = takeIndex();
			start = clock();
			TreeNode* temp = tree->searchNode(index);
			end = clock();
			if (temp != NULL)
			{
				cout << temp->firstName << endl;
			}
			else
			{
				cout << "Node Not Found" << endl;
			}
			double time = double(end - start) / double(CLOCKS_PER_SEC);
			cout << time << " sec Taken." << endl;
		}
		else if (op == 3)
		{
			int index = takeIndex();
			start = clock();
			TreeNode* temp = tree->searchNode(index);
			end = clock();

			if (temp != NULL)
			{
				updateNode(temp);
			}
			else
			{
				cout << "Node Not Found" << endl;
			}

			double time = double(end - start) / double(CLOCKS_PER_SEC);
			cout << time << " sec Taken." << endl;
		}
		else if (op == 4)
		{
			int index = takeIndex();
			start = clock();
			TreeNode* temp = tree->searchNode( index);
			if (temp != NULL)
			{
				tree->deleteWithRotation(temp, option);
				cout << "Deleted" << endl;
			}
			else
			{
				cout << "Node Not Found" << endl;
			}
			end = clock();
			double time = double(end - start) / double(CLOCKS_PER_SEC);
			cout << time << " sec Taken." << endl;
		}
		else if (op == 5)
		{
			traverseTree();
		}
		else if (op == 6)
		{
			break;
		}
		else
		{
			cout << "Invalid Option.\nTry Again" << endl;
		}
		clearScreen();
	}
}
TreeMaker* loadData(string fileName, int option)
{
	clock_t start, end;
	start = clock();
	TreeMaker* tree = new TreeMaker();
	fstream myFile(fileName);
	string line;
	int index = 1;
	string customerId, firstName, lastName, company, city, country, phone1, phone2, email, subscriptionDate, website;
	getline(myFile, line);
	while (getline(myFile, line))
	{
		index = stoi(parse(line, 0));
		customerId = parse(line, 1);
		firstName = parse(line, 2);
		lastName = parse(line, 3);
		company = parse(line, 4);
		city = parse(line, 5);
		country = parse(line, 6);
		phone1 = parse(line, 7);
		phone2 = parse(line, 8);
		email = parse(line, 9);
		subscriptionDate = parse(line, 10);
		website = parse(line, 11);
		TreeNode* temp = new TreeNode(index, customerId, firstName, lastName, company, city, country, phone1, phone2, email, subscriptionDate, website);
		tree->insertionWithRotation(temp, option);
		cout << index << ",";
	}
	end = clock();
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	cout << time << " sec Taken." << endl;
	return tree;
}
string parse(string line, int index)
{
	int count = 0;
	string word;
	for (int i = 0; line[i] != '/'; i++)
	{
		if (line[i] == ',')
		{
			count++;
		}
		else if (count == index)
		{
			word += line[i];
		}
	}
	return word;
}
void traverseTree()
{
	clearScreen();
	while (true)
	{
		int op = traverseMenu();
		clock_t start, end;
		start = clock();
		if (op == 1)
		{
			tree->breadthFirstTraversal();
		}
		else if (op == 2)
		{
			tree->inOrderTraversal(tree->root);
		}
		else if (op == 3)
		{
			tree->postOrderTraversal();
		}
		else if (op == 4)
		{
			tree->preOrderTraversal();
		}
		else if (op == 5)
		{
			break;
		}
		else
		{
			cout << "Invalid Option.\nTry Again" << endl;
		}
		end = clock();
		double time = double(end - start) / double(CLOCKS_PER_SEC);
		cout << endl << time << " sec Taken." << endl;
		clearScreen();
	}
}
