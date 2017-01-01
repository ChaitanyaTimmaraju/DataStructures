#ifndef UNION_FIND_H
#define UNION_FIND_H

class UnionFind
{
private:
	static const int kSetSize = 256;
	int parent[kSetSize+1];
	int size[kSetSize+1];
	int numberOfElements;
public:
	UnionFind(int n);
	int find(int element);
	bool sameComponenet(int element1,int element2);
	void unionSets(int element1,int element2);

};
#endif