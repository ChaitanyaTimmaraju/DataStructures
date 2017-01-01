#ifndef BFS_APPLICATIONS_H
#define BFS_APPLICATIONS_H
#include "GraphTraversal.h"
class BFSApplications: public GraphTraversal
{
private:
		enum COLOR
		{
			WHITE,
			BLACK,
			UNCOLORED
		};
		COLOR color[kMaxVertices];
		bool bipartite;

public:
	   BFSApplications(bool directed,bool weighted):GraphTraversal(directed,weighted)
 	   {

 	   }
	   void connectedComponents();
	   void twoColor();
	   COLOR colorComplement(COLOR x);
	   virtual void processVertexEarly(int v);
	   virtual void processVertexLate(int v);
	   virtual void processEdge(int x,int y);
};
#endif