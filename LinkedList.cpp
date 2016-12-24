#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Random.h"
#include "LinkedList.h"

using std::cin;
using std::cout;
using std::endl;



LinkedList::LinkedList(int value)
{
		head = nullptr;
 		insert(value);
}
LinkedList::LinkedList()
{
	head = nullptr;
}
Node* LinkedList::search(Node *l,int value)
{
		if(l == nullptr) return nullptr;
		if(l->data == value) return l;
		else 
			return search(l->next,value);
}

void LinkedList::insert(int value)
{
	
	Node *insertedNode = new Node;
	insertedNode->data = value;
	insertedNode->next = head;
	head = insertedNode;
	
}

Node* LinkedList::predecessor(Node *l,int value)
{
	if((l== nullptr) || (l->next == nullptr))
					return nullptr;
	if(l->next->data == value)
			return l;
	else 
			return predecessor(l->next,value);
}

void LinkedList::deleteElement(int value)
{
	Node *findElement = search(head,value);
	if(findElement != nullptr&& findElement!= head)
	{
		Node *pred = predecessor(head,value);
		if(pred == nullptr)
		{
			head= findElement->next;
		}
		else
		{
			pred->next= findElement->next;
		}
		delete findElement;
		
	}else
	{
		head = findElement->next;
		delete findElement;
	}
}
void LinkedList::populate(int numberOfElements)
{
	for(int elements= 0 ;elements<=numberOfElements;elements++)
   	{
   		insert(getRandom(1,numberOfElements));
   	}
}

void LinkedList::print(Node *l)
{
	if(l != nullptr)
	{	
		cout<<l->data<<"  ";
		print(l->next);
	}else
	{
		cout<<endl;
	}
}

LinkedList::~LinkedList()
{

	Node *nextElement ;
	while(head != nullptr)
	{
		nextElement= head->next;
		delete head;
		head = nextElement;
	}
}

