#include "GraphApp.h"

using namespace std;

int main() {
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