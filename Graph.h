#ifndef TRANSPORTATION_GRAPH_H
#define TRANSPORTATION_GRAPH_H

#include <iostream>

const int maxWeight = INT_MAX;
const int DeafultVertices = 9;                                          
class Graph {
public:
	Graph(int sz = DeafultVertices) {};
	~Graph() {}
	bool GraphEmpty()const                                              //�Ƿ�ͼΪ��
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const                                               //�Ƿ�ͼΪ��
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		                //���ص�ǰ������
	int NunberOfEdges() { return numEdges; }			                //���ص�ǰ����
	virtual int getValue(int i) = 0;                                    //ȡ����i��ֵ
	virtual int getWeight(int v1, int v2) = 0;			                //ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	virtual bool insertVertex(const int vertex) = 0;			        //����һ������vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;              //�����(v1,v2),ȨΪcost
protected:
	int maxVertices;
	int numVertices;
	int numEdges;                                       //�ߵ�����
};


#endif // !TRANSPORTATION_GRAPH_H
