#ifndef TRANSPORTATION_GRAPH_H
#define TRANSPORTATION_GRAPH_H

#include <iostream>

const int maxWeight = INT_MAX;
const int DeafultVertices = 9;                                          
class Graph {
public:
	Graph(int sz = DeafultVertices) {};
	~Graph() {}
	bool GraphEmpty()const                                              //是否图为空
	{
		if (numEdges == 0)
			return true;
		else
		{
			return false;
		}
	}
	bool GraphFull()const                                               //是否图为满
	{
		if (numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return numVertices; }		                //返回当前顶点数
	int NunberOfEdges() { return numEdges; }			                //返回当前边数
	virtual int getValue(int i) = 0;                                    //取顶点i的值
	virtual int getWeight(int v1, int v2) = 0;			                //取边（v1，v2）上的权值
	virtual bool insertVertex(const int vertex) = 0;			        //插入一个顶点vertex
	virtual bool insertEdge(int v1, int v2, int cost) = 0;              //插入边(v1,v2),权为cost
protected:
	int maxVertices;
	int numVertices;
	int numEdges;                                       //边的数量
};


#endif // !TRANSPORTATION_GRAPH_H
