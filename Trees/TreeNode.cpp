#include "TreeNode.h"

TreeNode::TreeNode(int index, string customerId, string firstName, string lastName, string company, string city, string country, string phone1, string phone2, string email, string subscriptionDate, string website)
{
	this->index = index;
	this->customerId = customerId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->company = company;
	this->city = city;
	this->country = country;
	this->phone1 = phone1;
	this->phone2 = phone2;
	this->email = email;
	this->subscriptionDate = subscriptionDate;
	this->website = website;
	this->height = 0;
	this->left = nullptr;
	this->right = nullptr;
}
TreeNode::TreeNode()
{
	this->index = -1;
	this->height = 0;
	this->left = nullptr;
	this->right = nullptr;
}

//int TreeNode::getBalanceFactor(TreeNode* node)
//{
//	if (node == NULL) {
//		return 0;
//	}
//	return getHeight(node->left) - getHeight(node->right);
//}
//int TreeNode::getHeight(TreeNode* node)
//{
//	if (node == nullptr)
//	{
//		return 0;
//	}
//	return node->height;
//}
