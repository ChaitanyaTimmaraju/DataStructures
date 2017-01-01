#include "UnionFind.h"

UnionFind::UnionFind(int n):numberOfElements(n)
{
	int i;
	for(i=1;i<=n;++i)
	{
		parent[i]=i;
		size[i] = 1;
	}
}

int UnionFind::find(int element)
{
	if(parent[element]==element)
		return element;
	else
		return find(parent[element]);
}

bool UnionFind::sameComponenet(int element1,int element2)
{
	return (find(element1)==find(element2));
}

void UnionFind::unionSets(int element1,int element2)
{
	int root1= find(element1);
	int root2= find(element2);
	if(root1==root2)
		return;
	if(size[root1]>=size[root2])
	{
		size[root1] += size[root2];
		parent[root2]=root1;
	}else
	{
		size[root2] += size[root1];
		parent[root1]=root2;
	}

}