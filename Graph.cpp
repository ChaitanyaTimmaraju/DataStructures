#include <fstream>
#include <iostream>
#include "Graph.h"
using std::cout;
using std::endl;
Graph::Graph(bool directed,bool weighted)
{
	this->directed = directed;
	this->weighted = weighted;
	numEdges = 0;
	numVertices = 0;
	
	for(int i=0;i<kMaxVertices;i++)
	{
		edges[i] = nullptr;
		degree[i]=0;
	}

}

void Graph::readGraph(const char* fileName)
{
   std::ifstream input(fileName);
   if(!input)
   {
   	std::cerr<<"Error reading file"<<endl;
   }
   input>>numVertices;
   input>>numEdges;
   int x,y,w=0;
   while(input)
   {
	if(!(input>>x).fail() && !(input>>y).fail())
	{
		//cout<<"("<<x<<","<<y<<")"<<endl;
		if(weighted)
				input>>w;
	
	
		insertEdge(x,y,w,directed);
	}
   }
}

void Graph::insertEdge(int x,int y,int w,bool directed)
{
	edge *temp = new edge;
	temp->y = y;
	temp->weight = w;
	temp->next = edges[x];

	edges[x] = temp;
	++degree[x];

	if(directed == false)
		  insertEdge(y,x,w,true);
	else
		  ++numEdges;
}

void Graph::printGraph()
{
	edge *temp;
	for(int i=1;i<=numVertices;++i)
	{	
		cout<<i<<"->";
		temp = edges[i];
		while(temp!= nullptr)
		{	
			cout<<"  "<<temp->y<<"("<<temp->weight<<")";
			temp = temp->next;
		}
		cout<<endl;
	}
}

