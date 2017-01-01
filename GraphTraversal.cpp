#include "GraphTraversal.h"
#include <string>
#include <queue>
#include <iostream>
using std::cout;
using std::endl;
void GraphTraversal::initializeSearch()
{
	int i=1;
	time = 0;
	finished = false;
	for(;i<=numVertices;++i)
	{
		processed[i]=discovered[i]=false;
		parent[i]=-1;
		treeOutDegree[i]=0;
		entryTime[i]=exitTime[i]=0;
	}
}

void GraphTraversal::bfs(int start)
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
		processVertexEarly(v);
		processed[v] = true;
		temp = edges[v];
		while(temp != nullptr)
		{
			y = temp->y;	
			if(processed[y]==false || discovered)
				processEdge(v,y);	
			if(discovered[y] == false)
			{
				q.push(y);
				parent[y] = v;
				discovered[y]=true;
			}
			temp = temp->next;
		}
		processVertexLate(v);
	}
}
void GraphTraversal::dfs(int start)
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

void GraphTraversal::findPath(int start,int end)
{
	if(start == end)
		cout<<"\nStart: "<<start<<"("<<edges[start]->weight<<")";
	else
	{
		  findPath(start,parent[end]);
		  cout<<"->"<<end<<"("<<edges[end]->weight<<")";
	}
}

void GraphTraversal::processVertexEarly(int v)
{
	/*
	Articulation vertices
	reachableAncestor[v] = v;
	*/
}
void GraphTraversal::processVertexLate(int v)
{
	cout<<v<<",";

	/*
	Topological sort
	stackObj.push(v);
	*/
	/*
	Articulation vertices
	bool root;
	int time_v,time_parent;
	if(parent[v]<1 && treeOutDegree[v]>1)
	{
		cout<<"Root articulation vertex: "<<v<<endl;
		return;
	}
	root = (parent[parent[v]]<1);
	if(parent[v]==reachableAncestor[v] &&(!root))
			cout<<"Parent articulation vertex:"<<parent[v]<<endl;

	if(v==reachableAncestor[v])
	{
			cout<<"Bridge articulation vertex:"<<parent[v]<<endl;
			if(treeOutDegree[v]>0)
				cout<<"Bridge articulation vertex:"<<v<<endl;
	}
	
	
	time_v=entryTime[reachableAncestor[v]];
	time_parent = entryTime[reachableAncestor[parent[v]]];
	if(time_v<time_parent)
		 reachableAncestor[parent[v]]=reachableAncestor[v];
	*/
}
GraphTraversal::Classification GraphTraversal::edgeClassification(int x, int y)
{
	if(parent[y] == x ) return TREE;
	if(discovered[y] && !processed[y]) return BACK;
	if(processed[y] && entryTime[y]<entryTime[x]) return CROSS;
	if(processed[y] && entryTime[y]>entryTime[x]) return FORWARD;

	return UNDEFINED;
}
void GraphTraversal::processEdge(int x,int y)
{
	//cout<<"("<<x<<","<<y<<") ";

	/*
	Topological sort
	Classification edgeType;
	edgeType = edgeClassification(x,y);
	if(edgeType == BACK)
	{
		cout<<"Warning back edge found not a DAG!"<<endl;
	}
	*/

	/*
	  Articulation vertices
	  1.root with two independent children
	  2.visited time <= low time of adjacent vertices 
	  If any of above 2 cond'ns satisfied then it is articulation point.
	
	Classification edgeType;
	edgeType = edgeClassification(x,y);
	if(edgeType == TREE)
			++treeOutDegree[x];
	if(edgeType == BACK && parent[x]!=y)
	{
		if(entryTime[y]<entryTime[reachableAncestor[x]])
					reachableAncestor[x] = y;
	}
	*/
	/* CYCLE DETECTION
	if(parent[x]!=y)
	{
	 	cout<<"FOUND CYCLE:"<<x<<"->"<<y<<endl;	
	 	//Find path not working in this case. segmentation fault.
	 	//findPath(y,x);
	 	finished = true;
	}*/
	
}
/*
void Graph::topologicalSort()
{
	int i;
	for(i=1;i<=numVertices;++i)
	{
		if(discovered[i]==false)
			 dfs(i);
	}
	stackObj.print();
	//please empty stack after usage.
}
*/