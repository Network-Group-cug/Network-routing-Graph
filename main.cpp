#include "GraphApp.h"

int main() {
	void CreateGraph(Graphmtx &G);
	void ShortestPath(Graphmtx& G, int v);
	int R = 1;
	Graphmtx Router;
	CreateGraph(Router);
	while (R) {
		cout << "请输入要查询的路由器编号(输入0退出)：";
		cin >> R;
		if (R > 0) {
			if (Router.getVertexPos(R) == -1) {
				cout << R << "号路由器不存在！"<< endl;
				continue;
			}
			else 
				ShortestPath(Router, Router.getVertexPos(R));
		}
		else continue;
	}
	
	system("pause");
	
	return 0;
}