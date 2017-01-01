#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H
#include "Graph.h"
#include "Stack.h"
class GraphTraversal:public Graph
{
 protected:
 	bool processed[kMaxVertices];
	bool discovered[kMaxVertices];
	Stack stackObj;
	int entryTime[kMaxVertices];
	int exitTime[kMaxVertices];
	int parent[kMaxVertices];
	int time;
	int treeOutDegree[kMaxVertices],reachableAncestor[kMaxVertices];
 public:
 	GraphTraversal(bool directed,bool weighted):Graph(directed,weighted)
 	{

 	}
 	enum Classification
	{
		TREE,
		BACK,
		FORWARD,
		CROSS,
		UNDEFINED
	};
	void findPath(int start,int end);
	void bfs(int start);
	void dfs(int start);
	virtual void processVertexEarly(int v);
	virtual void processVertexLate(int v);
	virtual void processEdge(int x,int y);
	void initializeSearch();
	//void topologicalSort();
	Classification edgeClassification(int x, int y);
};
#endif
