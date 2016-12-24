#include <iostream>
#include "BST.h"
using std::cout;
using std::endl;
BST::BST()
{
	head= nullptr;
}

tree* BST::search(tree* t,int value)
{
	if(t == nullptr)
				return nullptr;
	if(value == t->data)
				return t;
	if(value>t->data)
				return search(t->right,value);
	else
				return search(t->left,value);
}

tree* BST::findMinimum(tree *t)
{
	tree* min;
	if(t == nullptr)
			return nullptr;
	min = t;
	
	while(min->left != nullptr)
	{
			min = min->left;
	}

	return min;
}
void BST::traverse(tree *t)
{
	if(t != nullptr)
	{
		traverse(t->left);
		cout<<t->data<<"  ";
		traverse(t->right);
	}
}
void BST::insert(tree **nodePointing,int value,tree *parent)
{
	if(*nodePointing == nullptr)
	{
		tree *newNode = new tree;
		newNode->data = value;
		newNode->left = newNode->right = nullptr;
		newNode->parent = parent;
		*nodePointing = newNode;
		return;
	}
	if((*nodePointing)->data > value)
					insert(&((*nodePointing)->left),value,*nodePointing);
	else
					insert(&((*nodePointing)->right),value,*nodePointing);
}
