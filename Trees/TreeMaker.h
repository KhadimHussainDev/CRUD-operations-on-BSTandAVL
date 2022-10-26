#pragma once
#include "TreeNode.h"
#include<stack>
class TreeMaker
{
public:
	TreeNode* root;
	TreeMaker();
	int max(int a, int b);
	TreeNode* rightRotate(TreeNode* node);
	TreeNode* leftRotate(TreeNode* node);
	void insertionWithRotation(TreeNode* node, int option);
	stack<TreeNode*> insert(TreeNode* node);
	void rotate(stack<TreeNode*> s, TreeNode* node);
	TreeNode* search(int index);
	void deleteWithRotation(TreeNode* node, int option);
	stack<TreeNode*> deleteNode(TreeNode* node);
	void rotateAfterDelete(stack<TreeNode*>s);
	TreeNode* searchNode(int index);
	int getBalanceFactor(TreeNode* node);
	int height(TreeNode* node);
	TreeNode* insertRecord();
	void preOrderTraversal();
	void postOrderTraversal();
	void inOrderTraversal(TreeNode*);
	void breadthFirstTraversal();
};