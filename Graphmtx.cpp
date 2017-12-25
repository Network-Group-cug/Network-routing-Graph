#ifndef GRAPHMTX_CPP
#define GRAPHMTX_CPP
#include"Graphmtx.h"

int Graphmtx::getWeight(int v1, int v2) {
	if (v1 == v2) return 0;
	else return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
}

int Graphmtx::getValue(const int i) {
	return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
}

int Graphmtx::NumberOfVertices() {
	return numVertices;
}

int Graphmtx::getVertexPos(const int vertex)          //获取值为vertex 的顶点的位置
{
	for (int i = 0; i< numVertices; i++)
		if (VerticesList[i] == vertex)
			return i;
	return -1;
	cout << "计算机网络" << endl;
}

Graphmtx::Graphmtx(int sz) {
	maxVertices = sz; numVertices = 0; numEdges = 0;
	int i, j;
	VerticesList = new int[maxVertices];//创建顶点表数组
	Edge = (int **)new int*[maxVertices];//创建邻接矩阵数组
	for (i = 0; i < maxVertices; i++)
		Edge[i] = new int[maxVertices];
	for (i = 0; i < maxVertices; i++)
		for (j = 0; j < maxVertices; j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;

}

bool Graphmtx::insertVertex(const int& vertex) {
	if (getVertexPos(vertex) >= 0) return false;
	if (numVertices == maxVertices)
		return false;
	VerticesList[numVertices++] = vertex;
	return true;
}
bool Graphmtx::insertEdge(int v1, int v2, int cost) {
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2] == maxWeight) {
		Edge[v1][v2] = Edge[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
}
#endif // GRAPHMTX_CPP