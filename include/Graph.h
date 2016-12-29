#ifndef GRAPH_H
#define GRAPH_H
struct edge
{
	int y,weight;
	struct edge *next;
};
class Graph
{
private:
	static const int kMaxVertices =100;
	edge *edges[kMaxVertices];
	int degree[kMaxVertices],entryTime[kMaxVertices],exitTime[kMaxVertices],treeOutDegree[kMaxVertices],reachableAncestor[kMaxVertices];
	int numVertices,numEdges,time;
	bool directed,finished;
	bool processed[kMaxVertices];
	bool discovered[kMaxVertices];
	int parent[kMaxVertices];
public:
	enum Classification
	{
		TREE,
		BACK,
		FORWARD,
		CROSS,
		UNDEFINED
	};
	Graph(bool directed);
	void readGraph(const char* fileName);
	void insertEdge(int x,int y,bool directed);
	void printGraph();
	void initializeSearch();
	void findPath(int start,int end);
	void bfs(int start);
	void dfs(int start);
	void processVertexEarly(int v);
	void processVertexLate(int v);
	void processEdge(int x,int y);
	Classification edgeClassification(int x, int y);
};
#endif