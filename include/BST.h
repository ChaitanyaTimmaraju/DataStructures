#ifndef BST_H
#define BST_H
typedef struct tree
{
	int data;
	struct tree *parent,*left,*right;
}tree;
class BST
{

		
public:
	  tree *head;
	  BST();
	  void insert(tree **currentNodeAddress,int value,tree* parent);
	  tree* search(tree *n,int value);
	  tree* findMinimum(tree *n);
	  void traverse(tree *n);
};
#endif