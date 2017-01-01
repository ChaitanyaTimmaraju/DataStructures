#ifndef GRAPH_H
#define GRAPH_H
struct edge
{
	int y,weight;
	struct edge *next;
};
class Graph
{
protected:
	static const int kMaxVertices =100;
	edge *edges[kMaxVertices];
	int degree[kMaxVertices];
	int numVertices,numEdges;
	bool directed,finished,weighted;
	
public:
	Graph(bool directed,bool weighted);
	void readGraph(const char* fileName);
	void insertEdge(int x,int y,int w,bool directed);
	void printGraph();
};
#endif