#include "GraphApp.h"

int main() {
	void CreateGraph(Graphmtx &G);
	void ShortestPath(Graphmtx& G, int v);
	int R = 1;
	Graphmtx Router;
	CreateGraph(Router);
	while (R) {
		cout << "������Ҫ��ѯ��·�������(����0�˳�)��";
		cin >> R;
		if (R > 0) {
			if (Router.getVertexPos(R) == -1) {
				cout << R << "��·���������ڣ�"<< endl;
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