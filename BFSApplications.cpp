#include <iostream>
#include "BFSApplications.h"
using std::cout;
using std::endl;
void BFSApplications::connectedComponents()
{
	int componentNumber=0,i;
	initializeSearch();
	for(i=1;i<=numVertices;++i)
	{
		if(discovered[i]==false)
			{
				++componentNumber;
				cout<<"Component: "<<componentNumber<<endl;
				bfs(i);
			}
	}

}
void BFSApplications::twoColor()
{
	int i;
	initializeSearch();
	bipartite = true;
	for(i=1;i<=numVertices;++i)
			color[i]=UNCOLORED;
	for(i=1;i<=numVertices;++i)
	{
		if(discovered[i]==false)
			{
				color[i] = WHITE;
				bfs(i);
			}
	}
}
BFSApplications::COLOR BFSApplications::colorComplement(BFSApplications::COLOR x)
{
   if(x==WHITE) return BLACK;
   if(x==BLACK) return WHITE;
   return UNCOLORED;
}
void BFSApplications::processVertexEarly(int v)
{

}
void BFSApplications::processVertexLate(int v)
{

}
void BFSApplications::processEdge(int x,int y)
{
	if(color[x]==color[y] && bipartite)
	{
		cout<<"Not a bipartite graph:("<<x<<","<<y<<")"<<endl;
		bipartite=false;
	}
	color[y] = colorComplement(color[x]);

}