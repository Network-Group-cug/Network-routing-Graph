#include "GraphApp.h"

using namespace std;

int main() {
	int R = 1;
	Graphlnk Router;
	CreateGraph(Router);
	while (R) {
		cout << "������Ҫ��ѯ��·�������(����0�˳�)��";
		cin >> R;
		if(R>0 && R<=Router.NumberOfVertices())		ShortestPath(Router, Router.getVertexPos(R));
		else if (R != 0) {
			cout << R << "��·���������ڣ�"<< endl;
			continue;
		}
		else continue;
	}
	
	system("pause");
	
	return 0;
}