#ifndef GRAPHMTX_H
#define GRAPHMTX_H
#include <limits.h>
using namespace std;

const int DefaultVertices = 9;//最大顶点数
const int maxWeight = INT_MAX;//表示无穷大

class Graphmtx {
     private:
		 int maxVertices;//图中最大顶点数
		 int numEdges;//当前边数
		 int numVertices;//当前顶点数
		 int *VerticesList;//顶点表
		 int **Edge;//邻接矩阵
		 

     public:
		 Graphmtx(int sz = DefaultVertices);

		 ~Graphmtx() {
			 delete[]VerticesList;
			 delete[]Edge;
		}

		 int getWeight(int v1, int v2);

		int getValue(const int i);

		 int NumberOfVertices();
		 bool insertVertex(const int& vertex);//插入顶点

		 bool insertEdge(int v1, int v2, int cost);//插入边(v1,v2),权值为cost

		 int getVertexPos(const int vertex);          //获取值为vertex 的顶点的位置
		 
};

#endif //GRAPHMTX_H