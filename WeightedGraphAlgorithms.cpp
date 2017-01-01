#include <iostream>
#include "WeightedGraphAlgorithms.h"
#include <climits>
 void WeightedGraphAlgorithms::prim(int start)
 {
 	int i;
 	edge *temp;
 	bool intree[kMaxVertices];
 	int distance[kMaxVertices];
 	int v;
 	int w;
 	int weight;
 	int dist;

 	for(i=1;i<=numVertices;++i)
 	{
 		intree[i]=false;
 		distance[i]=INT_MAX;
 		parent[i]=-1;
 	}
 	distance[start] = 0;
 	v=start;
 	while(intree[v]==false)
 	{
 		intree[v]=true;
 		std::cout<<v<<"->"<<parent[v]<<std::endl;

 		temp = edges[v];
 		while(temp != nullptr)
 		{
 			weight= temp->weight;
 			w=temp->y;
 			if(intree[w]==false && weight<distance[w])
 			{
 				distance[w]=weight;
 				parent[w]=v;
 			}
 			temp = temp->next;
 		}
 		v=1;
 		dist = INT_MAX;
 		for(i=1;i<=numVertices;++i)
 				if(intree[i]==false && dist>distance[i])
 				{
 					dist = distance[i];
 					v=i;

 				}
 	}
 	for(i=1,dist=0;i<=numVertices;++i)
 	{
 		dist+=distance[i];
 	}
 	std::cout<<std::endl<<dist;
 }
void WeightedGraphAlgorithms::toEdgeArray(edgePair arr[])
{
	edge *temp;
	int i,j;
	int e=0;
	for(i=1;i<=numVertices;++i)
	{	
		cout<<i<<"->";
		temp = edges[i];
		while(temp!= nullptr)
		{	
			while()
			cout<<"  "<<temp->y<<"("<<temp->weight<<")";
			temp = temp->next;
		}
	}
}