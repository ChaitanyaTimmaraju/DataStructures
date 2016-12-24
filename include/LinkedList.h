#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node
{
	int data;
	struct Node *next;
};
class LinkedList
{
private:
 		Node *head;
public:
	LinkedList();
	LinkedList(int value);
	Node* search(Node *l,int value);
	void insert(int value);
	Node* predecessor(Node *l,int value);
	void deleteElement(int value);
	void populate(int numberOfElements);
	void print(Node *l);
	Node* getHead(){ return head;}
	~LinkedList();
};
#endif