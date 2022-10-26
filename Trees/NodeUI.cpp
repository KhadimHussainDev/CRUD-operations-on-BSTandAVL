#include "NodeUI.h"
#include "TreeNode.h"

TreeNode* makeNode(int index)
{
	string customerId, firstName, lastName, company, city, country, phone1, phone2, email, subscriptionDate, website;

	cout << "Customer ID: ";
	cin >> customerId;
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "Company: ";
	cin >> company;
	cout << "City: ";
	cin >> city;
	cout << "Country: ";
	cin >> country;
	cout << "Phone 1: ";
	cin >> phone1;
	cout << "Phone 2: ";
	cin >> phone2;
	cout << "Email: ";
	cin >> email;
	cout << "Subscription Date: ";
	cin >> subscriptionDate;
	cout << "Website: ";
	cin >> website;

	TreeNode* temp = new TreeNode(index, customerId, firstName, lastName, company, city, country, phone1, phone2, email, subscriptionDate, website);
	return temp;
}
void updateNode(TreeNode* temp)
{
	cout << "Enter Details: " << endl;
	cout << "Index: " << temp->index << endl;
	cout << "Customer ID: ";
	cin >> temp->customerId;
	cout << "First Name: ";
	cin >> temp->firstName;
	cout << "Last Name: ";
	cin >> temp->lastName;
	cout << "Company: ";
	cin >> temp->company;
	cout << "City: ";
	cin >> temp->city;
	cout << "Country: ";
	cin >> temp->country;
	cout << "Phone 1: ";
	cin >> temp->phone1;
	cout << "Phone 2: ";
	cin >> temp->phone2;
	cout << "Email: ";
	cin >> temp->email;
	cout << "Subscription Date: ";
	cin >> temp->subscriptionDate;
	cout << "Website: ";
	cin >> temp->website;
	cout << "Values Updated ...." << endl;
}
int takeIndex() {
	cout << "Enter Index : ";
	int index;
	cin >> index;
	return index;
}
