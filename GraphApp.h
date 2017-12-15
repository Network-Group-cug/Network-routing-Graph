#ifndef GRAPHAPP_H
#define GRAPHAPP_H

#include "Graphlnk.h"
#include "Graph.h"
#include <limits.h>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

int maxValue = INT_MAX;

void CreateGraph(Graphlnk &G) {                                //建立图结构
	ifstream fp("Graph.txt");
	if (!fp) {
		cout << "Data Error!"<<endl;
		return;
	}
	else {
		while (!fp.eof()) {                                    //从Graph.txt文件中读取路由拓扑图的基本信息
			int Router1, Router2, cost;
			fp >> Router1 >> Router2 >> cost;
			G.insertVertex(Router1);
			G.insertVertex(Router2);
			G.insertEdge(G.getVertexPos(Router1), G.getVertexPos(Router2), cost);
		}
	}
	fp.close();
}

void printPath(Graph& G, int v, int dist[], int path[]) {
	cout << "路由器" << G.getValue(v) << "的路由器表如下：" << endl;
	int i, j, k, n = G.NumberOfVertices();
	int * d = new int[n];
	cout << "目的路由器\t距离\t下一跳" << endl;
	for (i = 0; i<n; i++)
	{
		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			cout << G.getValue(i)<<"\t\t"<<dist[i]<<"\t"<< G.getValue(d[--k]);
			cout << endl;
		}
	}
	delete[] d;
}

////////////////////////////////////Dijkstra最短路径//////////////////////////////////////////////////////////////////
void ShortestPath(Graph& G, int v) {//求两个路由器之间的最短路径
	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	int *dist = new int[n];
	int *path = new int[n];
	int i, j, k;
	int w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = G.getWeight(v,i);
		S[i] = false;
		if (i != v && dist[i] <maxValue)
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i<n - 1; i++)
	{
		min = maxValue;
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k<n; k++)
		{
			w = G.getWeight(u, k);
			if (S[k] == false && w <maxValue && dist[u] + w<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	printPath(G, v, dist, path);
	delete[] S;
	delete[] dist;
	delete[] path;
}

/*void Ford(Graph& G, int v) {                             //Bellman-Ford算法实现
	int i, k, u, w, n = G.NumberOfVertices();
	int *dist = new int[n];
	int *path = new int[n];
	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i);
		if (i != v && dist[i] < maxValue) path[i] = v;
		else path[i] = -1;
	}
	for (k = 2; k < n; k++){
		for (u = 0; u < n; u++) {
			if (u != v) {
				for (i = 0; i < n; i++) {
					w = G.getWeight(i, u);
					if (w > 0 && w < maxValue && dist[u] > dist[i] + w) {
						dist[u] = dist[i] + w;
						path[u] = i;
					}
				}
			}
		}
	}		
	printPath(G, v, dist, path);
	delete[] dist;
	delete[] path;
}*/

#endif // !GRAPHAPP_H
