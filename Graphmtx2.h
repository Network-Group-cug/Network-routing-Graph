#pragma once
#include<iostream>
using namespace std;
const int DefaultVertices = 20;
class Graphmtx {
     private:
		 int maxVertices;//图中最大顶点数
		 int numEdges;//当前边数
		 int numVertices;//当前顶点数
		 int *VerticesList;//顶点表
		 int **Edge;//邻接矩阵
     public:
		 const int maxWeight =10000;//表示无穷大
		 Graphmtx(int sz = DefaultVertices);
		 ~Graphmtx() {
			 delete[]VerticesList;
			 delete[]Edge;
		}
		int getWeight(int v1, int v2) {
			 return v1 != -1 && v2 != -1 ? Edge[v1][v2] : 0;
		 }
		 int getValue(int i) {
			 return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
		 }
		 int NumberOfVertices() {
			 return numVertices;
		 }
		 bool insertVertex(const int& vertex);//插入顶点
		 bool insertEdge(int v1, int v2, int cost);//插入边(v1,v2),权值为cost
		 bool removeVertex(int v);//删除顶点v和所有与它相关联的边
		 bool removeEdge(int v1, int v2);//在图中删除边(v1,v2)
		 void output();
		 void ShortestPath(Graphmtx& G, int v, int dist[], int path[]);
};
Graphmtx::Graphmtx(int sz) {
	maxVertices = sz;numVertices = 0;numEdges = 0;
	int i, j;
	VerticesList = new int[maxVertices];//创建顶点表数组
	Edge = (int **)new int*[maxVertices];//创建邻接矩阵数组
	for (i = 0;i < maxVertices;i++)
		Edge[i] = new int[maxVertices];
	for (i = 0;i < maxVertices;i++)
		for (j = 0;j < maxVertices;j++)
			Edge[i][j] = (i == j) ? 0 : maxWeight;

}
bool Graphmtx::insertVertex(const int& vertex) {
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
bool Graphmtx::removeVertex(int v) {
	if (v < 0 || v >= numVertices)
		return false;
	if (numVertices == 1)
		return false;
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];
	for (i = 0;i < numVertices;i++)
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)
			numEdges--;
	for (i = 0;i < numVertices;i++)
		Edge[i][v] = Edge[i][numVertices - 1];
	numVertices--;
	for (j = 0;j < numVertices;j++)
		Edge[v][j] = Edge[numVertices][j];
	cout << "删除成功！" << endl;
	return true;
}
bool Graphmtx::removeEdge(int v1, int v2) {
	if (v1 > -1 && v1<numVertices&&v2>-1 && v2 < numVertices&&Edge[v1][v2]>0 && Edge[v1][v2] < maxWeight) {
		Edge[v1][v2] = Edge[v2][v1] = maxWeight;
		numEdges--;
		cout << "删除成功！" << endl;
		return true;
	}
	else
		return false;
}
void Graphmtx::output() {
	for (int i = 0;i <numVertices;i++) {
		for (int j = 0;j < numVertices;j++)
			cout << Edge[i][j] << "    ";
		cout << endl;
	}
}
void Graphmtx::ShortestPath(Graphmtx& G, int v, int dist[], int path[]) {
	int n = G.NumberOfVertices();
	bool *s = new bool[n];
	int i, j, k, w, min;
	for (i = 0;i < n;i++) {
		dist[i] = G.getWeight(v, i);
		s[i] = false;
		if (i != v&&dist[i] < maxWeight) path[i] = v;
		else path[i] = -1;
	}
	s[v] = true;dist[v] = 0;
	for (i = 0;i < n - 1;i++) {
		min = maxWeight;int u = v;
		for(j=0;j<n;j++)
			if (s[j] == false && dist[j] < min) {
				u = j;min = dist[j];
			}
		s[u] = true;
		for (k = 0;k < n;k++) {
			w = G.getWeight(u, k);
			if (s[k] == false && w < maxWeight&&dist[u] + w < dist[k]) {
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	cout << "从路由器" <<G.getValue(v)<< "到其它各路由器的最短路径为"<<endl;
	cout << "路由器       " << "下一跳路由器     " << "距离"<<endl;
	int *d = new int[n];
	for (i = 0;i < n;i++) 
		if (i != v) {
			j = i;k = 0;
			while (j != v) {
				d[k++] = j;j = path[j];
			}
        cout << G.getValue(i) << "            " << G.getValue(d[--k]) << "                   " << dist[i] << endl;
		}
	delete[]d;
}
