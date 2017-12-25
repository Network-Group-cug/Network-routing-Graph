#ifndef GRAPHAPP_H
#define GRAPHAPP_H

#include "Graphmtx.h"
#include <limits.h>
//#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int maxValue = INT_MAX;

void CreateGraph(Graphmtx &G) {                                //����ͼ�ṹ
	ifstream fp("Graph.txt");
	if (!fp) {
		cout << "Data Error!"<<endl;
		return;
	}
	else {
		while (!fp.eof()) {                                    //��Graph.txt�ļ��ж�ȡ·������ͼ�Ļ�����Ϣ
			int Router1, Router2, cost;
			fp >> Router1 >> Router2 >> cost;
			G.insertVertex(Router1);
			G.insertVertex(Router2);
			G.insertEdge(G.getVertexPos(Router1), G.getVertexPos(Router2), cost);
		}
	}
	fp.close();
}

void printPath(Graphmtx& G, int v, int dist[], int path[]) {
	cout << "·����" << G.getValue(v) << "��·���������£�" << endl;
	int i, j, k, n = G.NumberOfVertices();
	int * d = new int[n];
	cout << "Ŀ��·����\t����\t��һ��" << endl;
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

////////////////////////////////////Dijkstra���·��//////////////////////////////////////////////////////////////////
void ShortestPath(Graphmtx& G, int v) {     //������·����֮������·��
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

#endif // !GRAPHAPP_H
