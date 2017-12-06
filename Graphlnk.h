#ifndef GRAPHLNK_H
#define GRAPHLNK_H

#include <iomanip>
#include "Graph.h"

using namespace std;

struct Edge
{
	int dest;			//�ߵ���һ������λ��
	int cost;			//���ϵ�Ȩֵ
	Edge * link;	    //��һ������ָ��
	Edge() {}
	Edge(int num, int weight, int f) : dest(num), cost(weight), link(NULL) {}
	bool operator != (Edge& R)const
	{
		return (dest != R.dest) ? true : false;
	}
};

struct Vertex
{
	int data;
	Edge *adj;			//�������ͷָ��
	Vertex() :adj(NULL) { }
};

class Graphlnk : public Graph
{
public:
	Graphlnk(int sz = DeafultVertices);
	~Graphlnk();
	int getValue(int i)					    //ȡλ��Ϊi�Ķ����е�ֵ
	{
		return (i >= 0 && i <= numVertices) ? NodeTable[i].data : 0;
	}
	int getWeight(int v1, int v2);			//���ر�(v1,v2)��Ȩֵ
	bool insertVertex(const int vertex);
	bool insertEdge(int v1, int v2, int cost);
	int NumberOfVertices()
	{
		return this->numVertices;
	}
	int getVertexPos(const int vertex)
	{
		for (int i = 0; i< numVertices; i++)
			if (NodeTable[i].data == vertex)
				return i;
		return -1;
	}
private:
	Vertex * NodeTable;
};

Graphlnk::Graphlnk(int sz /* = DeafultVertices */)
{
	maxVertices = sz;
	numVertices = 0;
	numEdges = 0;
	NodeTable = NULL;

	try
	{
		NodeTable = new Vertex[maxVertices];
	}
	catch (bad_alloc & memExp)
	{
		cerr << memExp.what() << endl;
	}
	for (int i = 0; i<=maxVertices; i++)
		NodeTable[i].adj = NULL;
}

Graphlnk::~Graphlnk()
{
	for (int i = 0; i<maxVertices; i++)
	{
		Edge * p = NodeTable[i].adj;
		while (p != NULL)
		{
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete[] NodeTable;
}

int Graphlnk::getWeight(int v1, int v2)
{
	if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices && v1 != v2)
	{
		Edge *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL) {
			return p->cost;
		}
		else {
			return maxWeight;
		}
	}
	else
		if (v1 == v2) {
			return 0;
		}			
	return maxWeight;
}

bool Graphlnk::insertVertex(const int vertex)
{
	if (getVertexPos(vertex) >= 0) return false;
	if (numVertices == maxVertices) return false;
	NodeTable[numVertices].data = vertex;
	numVertices++;
	return true;
}

bool Graphlnk::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 0 && v2 >= 0 && v1 != v2)
	{
		Edge *q, *p = NodeTable[v1].adj;
		while (p != NULL && p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
		{
			p->cost = cost;
			return true;
		}
		p = new Edge;
		q = new Edge;
		p->dest = v2;
		p->cost = cost;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		q->cost = cost;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
	return false;
}

/*ostream& operator << (ostream& out, Graphlnk& G)
{
	int i, j;
	cout << "�������Ϊ:" << G.NumberOfVertices() << endl;
	cout << "�ߵ�����Ϊ:" << G.NunberOfEdges() << endl;
	cout << "��㼯��Ϊ:";
	for (i = 0; i< G.NumberOfVertices(); i++)
		cout << "     " << G.getValue(i);
	cout << "\n";
	cout << "Ȩֵ����Ϊ:\n";
	for (i = 0; i<G.NumberOfVertices(); i++)
	{
		for (j = 0; j<G.NumberOfVertices(); j++)
		{
			if (G.getWeight(i, j) == maxWeight)
				cout << setw(10) << "Max";
			else
				cout << setw(10) << G.getWeight(i, j);
		}
		cout << "\n";
	}
	return out;
}*/


#endif