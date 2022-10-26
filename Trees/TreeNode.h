#pragma once
#include <iostream>
using namespace std;
class TreeNode
{
public:
	int index, height;
	string customerId, firstName, lastName, company, city, country, phone1, phone2, email, subscriptionDate, website;
	TreeNode* left, * right;
	TreeNode(int index, string customerId, string firstName, string lastName, string company, string city, string country, string phone1, string phone2, string email, string subscriptionDate, string website);
	TreeNode();

	//int getBalanceFactor(TreeNode* node);
	//int getHeight(TreeNode* node);

};

