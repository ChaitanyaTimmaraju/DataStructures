#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include "Graph.h"
using std::cout;
using std::endl;
Graph::Graph(bool directed)
{
	this->directed = directed;
	numEdges = 0;
	numVertices = 0;
	directed = directed;
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
   int x,y;
   while(input)
   {
	if(!(input>>x).fail() && !(input>>y).fail())
	{
		//cout<<"("<<x<<","<<y<<")"<<endl;
		insertEdge(x,y,directed);
	}
   }
}

void Graph::insertEdge(int x,int y,bool directed)
{
	edge *temp = new edge;
	temp->y = y;
	temp->weight = 0;
	temp->next = edges[x];

	edges[x] = temp;
	++degree[x];

	if(directed == false)
		  insertEdge(y,x,true);
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
			cout<<"  "<<temp->y;
			temp = temp->next;
		}
		cout<<endl;
	}
}

void Graph::initializeSearch()
{
	int i=1;
	time = 0;
	finished = false;
	for(;i<=numVertices;++i)
	{
		processed[i]=discovered[i]=false;
		parent[i]=-1;
		treeOutDegree[i]=0;
	}
}

void Graph::bfs(int start)
{
	std::queue<int> q;
	int v,y;
	edge *temp;
	q.push(start);
	discovered[start] = true;
	while(!q.empty())
	{
		v = q.front();
		q.pop();
		processed[v] = true;
		temp = edges[v];
		while(temp != nullptr)
		{
			y = temp->y;
			if(discovered[y] == false)
			{
				cout<<y<<",";
				q.push(y);
				parent[y] = v;
				discovered[y]=true;
			}
			temp = temp->next;
		}
	}
}
void Graph::dfs(int start)
{
	int y;
	edge *temp;
	if(finished) return;
	temp = edges[start];
	discovered[start] = true;
	++time;
	entryTime[start] = time;
	processVertexEarly(start);

	while(temp != nullptr)
	{
		y = temp->y;
		if(discovered[y] == false)
		{
			parent[y] = start;
			processEdge(start,y);
			dfs(y);
		}else if((!processed[y])|| directed)
				processEdge(start,y);
		if(finished) return;
		temp = temp->next;
	}
	processVertexLate(start);
	++time;
	exitTime[start]=time;
	processed[start] = true;
}

void Graph::findPath(int start,int end)
{
	if(start == end)
		cout<<"\nStart: "<<start;
	else
	{
		  findPath(start,parent[end]);
		  cout<<"->"<<end;
	}
}

void Graph::processVertexEarly(int v)
{
	reachableAncestor[v] = v;
}
void Graph::processVertexLate(int v)
{
	
}
Graph::Classification Graph::edgeClassification(int x, int y)
{
	if(parent[y] == x ) return TREE;
	if(discovered[y] && !processed[y]) return BACK;

	return UNDEFINED;
}
void Graph::processEdge(int x,int y)
{
	/*1.root with two independent children
	  2.visited time <= low time of adjacent vertices 
	  If any of above 2 cond'ns satisfied then it is articulation point.
	*/
	Classification edgeType;
	edgeType = edgeClassification(x,y);
	if(edgeType == TREE)
			++treeOutDegree[x];
	
	/* CYCLE DETECTION
	if(parent[x]!=y)
	{
	 	cout<<"FOUND CYCLE:"<<x<<"->"<<y<<endl;	
	 	//Find path not working in this case. segmentation fault.
	 	//findPath(y,x);
	 	finished = true;
	}*/
	
}