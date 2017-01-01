#ifndef WEIGHTED_GRAPH_ALGORITHMS
#define WEIGHTED_GRAPH_ALGORITHMS
#include "Graph.h"
#include "UnionFind.h"
typedef struct 
{
	int x,y;
}edgePair;
class WeightedGraphAlgorithms:public Graph
{
 public:
 		WeightedGraphAlgorithms(const char* fileName,bool directed,bool weighted):Graph(directed,weighted)
 		{
 			readGraph(fileName);
			initializeSearch();
 		}
 		void prim(int start);
 		void kruskal();
 		void toEdgeArray(edgePair arr[]);
};
#endif