#include "TreeMaker.h"
#include "NodeUI.h"
#include<queue>

TreeMaker::TreeMaker()
{
	root = nullptr;
}
int TreeMaker::height(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->height;
}
int TreeMaker::getBalanceFactor(TreeNode* node)
{
	if (node == NULL) {
		return 0;
	}
	return height(node->left) - height(node->right);
}
int TreeMaker::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}
TreeNode* TreeMaker::rightRotate(TreeNode* node)
{
	TreeNode* x = node->left;
	TreeNode* y = x->right;
	x->right = node;
	node->left = y;
	node->height = 1 + max(height(node->right), height(node->left));
	x->height = 1 + max(height(x->left), height(x->right));
	return x;
}
TreeNode* TreeMaker::leftRotate(TreeNode* node)
{
	TreeNode* x = node->right;
	TreeNode* y = x->left;
	x->left = node;
	node->right = y;
	node->height = 1 + max(height(node->right), height(node->left));
	x->height = 1 + max(height(x->left), height(x->right));
	return x;
}
void TreeMaker::insertionWithRotation(TreeNode* node, int option)
{
	stack<TreeNode*> s = insert(node);
	if (option == 2) {
		rotate(s, node);
	}
}
stack<TreeNode*>TreeMaker::insert(TreeNode* node)
{
	stack<TreeNode*> s;
	if (root == NULL)
	{
		root = node;
		return s;
	}
	TreeNode* temp = root, prev;
	while (temp != NULL)
	{
		s.push(temp);
		if (node->index < temp->index)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				temp->left = node;
				break;
			}
		}
		else if (node->index > temp->index)
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				temp->right = node;
				break;
			}
		}
	}
	s.push(node);
	return s;
}
void TreeMaker::rotate(stack<TreeNode*> s, TreeNode* node)
{
	TreeNode* temp, * temp1 = NULL;
	bool isBalance = false;
	while (!s.empty())
	{
		isBalance = false;
		temp = s.top();
		s.pop();
		temp->height = 1 + max(height(temp->left), height(temp->right));
		int bf = getBalanceFactor(temp);
		if (bf > 1)
		{
			if (node->index < temp->left->index)
			{
				temp1 = rightRotate(temp);
			}
			else if (node->index > temp->left->index)
			{
				temp->left = leftRotate(temp->left);
				temp1 = rightRotate(temp);
			}
			isBalance = true;
		}
		if (bf < -1)
		{
			if (node->index > temp->right->index)
			{
				temp1 = leftRotate(temp);
			}
			else if (node->index < temp->right->index)
			{
				temp->right = rightRotate(temp->right);
				temp1 = leftRotate(temp);
			}
			isBalance = true;
		}
		if (isBalance)
		{
			if (s.empty())
			{
				root = temp1;
			}
			else
			{
				s.top()->left == temp ? s.top()->left = temp1 : s.top()->right = temp1;
			}
		}
	}
}
TreeNode* TreeMaker::search(int index)
{
	if (root == NULL)
	{
		return NULL;
	}
	TreeNode* temp = root, prev;
	while (temp != NULL)
	{
		if (index < temp->index)
		{
			if (temp->left != NULL)
			{
				temp = temp->left;
			}
			else
			{
				return NULL;
			}
		}
		else if (index > temp->index)
		{
			if (temp->right != NULL)
			{
				temp = temp->right;
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return temp;
		}
	}
	return NULL;
}
void TreeMaker::deleteWithRotation(TreeNode* node, int option) {
	stack<TreeNode*>s = deleteNode(node);
	if (option == 2) {
		rotateAfterDelete(s);
	}
}
stack<TreeNode*> TreeMaker::deleteNode(TreeNode* node)
{
	stack<TreeNode*> s;
	if (root == NULL)
	{
		return s;
	}
	TreeNode* temp = root, * prev = temp;
	while (temp != NULL)
	{
		s.push(temp);
		if (node->index < temp->index)
		{
			prev = temp;
			temp = temp->left;
		}
		else if (node->index > temp->index)
		{
			prev = temp;
			temp = temp->right;
		}
		else if (temp->index == node->index)
		{
			s.pop();
			if (temp->left == temp->right)
			{
				if (prev == temp)
				{
					root = NULL;
				}
				else
				{
					prev->right == temp ? prev->right = NULL : prev->left = NULL;
				}
				break;
			}
			else if (temp->left == NULL)
			{
				if (temp == prev)
				{
					root = temp->right;
				}
				else
				{
					prev->right == temp ? prev->right = temp->right : prev->left = temp->right;
				}
			}
			else if (temp->right == NULL)
			{
				if (temp == prev)
				{
					root = temp->left;
				}
				else
				{
					prev->right == temp ? prev->right = temp->left : prev->left = temp->left;
				}
			}
			else
			{
				TreeNode* t = temp->right, * pre = temp;
				while (t->left)
				{
					pre = t;
					t = t->left;
					s.push(t);
				}
				s.push(temp->right);
				if (pre == temp)
				{
					if (prev == temp)
					{
						t->left = temp->left;
						root = t;
					}
					else
					{
						prev->left == temp ? prev->left = t : prev->right = t;
						t->left = pre->left;
					}
				}
				else
				{
					if (prev == temp)
					{
						t->left = temp->left;
						pre->left = t->right;
						t->right = temp->right;
						root = t;
					}
					else
					{
						prev->right == temp ? prev->right = t : prev->left = t;
						pre->left = t->right;
						t->left = temp->left;
						t->right = temp->right;
					}
				}
			}
			break;
		}
	}
	return s;
}
void TreeMaker::rotateAfterDelete(stack<TreeNode*>s) {
	TreeNode* temp, * temp1 = NULL;
	bool isBalance = false;
	while (!s.empty()) {
		isBalance = false;
		temp = s.top();
		s.pop();
		temp->height = 1 + max(height(temp->left), height(temp->right));
		int balanceFactor = getBalanceFactor(temp);
		if (balanceFactor > 1) {
			int leftBalanceFactor = getBalanceFactor(temp->left);
			if (leftBalanceFactor >= 0) {
				temp1 = rightRotate(temp);
			}
			else {
				temp->left = leftRotate(temp->left);
				temp1 = rightRotate(temp);
			}
			isBalance = true;
		}
		else if (balanceFactor < -1) {
			int rightBalanceFactor = getBalanceFactor(temp->right);
			if (rightBalanceFactor <= 0) {
				temp1 = leftRotate(temp);
			}
			else {
				temp->right = rightRotate(temp->right);
				temp = leftRotate(temp);
			}
			isBalance = true;
		}
		if (isBalance) {
			if (s.empty())
			{
				root = temp1;
			}
			else
			{
				s.top()->left == temp ? s.top()->left = temp1 : s.top()->right = temp1;
			}
		}
	}
}
TreeNode* TreeMaker::searchNode( int index)
{
	TreeNode* temp = search(index);
	return temp;
}
TreeNode* TreeMaker::insertRecord()
{
	int index = takeIndex();
	if (search(index) != NULL)
	{
		return NULL;
	}

	TreeNode* temp = makeNode(index);
	return temp;
}


void TreeMaker::breadthFirstTraversal()
{
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty())
	{
		TreeNode* temp = q.front();
		cout << temp->index << "\t";
		q.pop();
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}
void TreeMaker::inOrderTraversal(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrderTraversal(root->left);
	cout << root->index << "\t";
	inOrderTraversal(root->right);
}
void TreeMaker::postOrderTraversal()
{
	stack<TreeNode*> s1, s2;
	s1.push(root);
	while (!s1.empty())
	{
		TreeNode* temp = s1.top();
		s2.push(temp);
		s1.pop();
		if (temp->left != NULL)
		{
			s1.push(temp->left);
		}
		if (temp->right != NULL)
		{
			s1.push(temp->right);
		}
	}
	while (!s2.empty())
	{
		TreeNode* temp = s2.top();
		//cout << getBalanceFactor(temp) << "\t";
		cout << temp->index << "\t";
		s2.pop();
	}
}
void TreeMaker::preOrderTraversal()
{
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* temp = s.top();
		cout << temp->index << "\t";
		s.pop();
		if (temp->left != NULL)
		{
			s.push(temp->left);
		}
		if (temp->right != NULL)
		{
			s.push(temp->right);
		}
	}
}

