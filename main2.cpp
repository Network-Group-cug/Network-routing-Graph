#include"Graphmtx.h"
int main(){
	Graphmtx L(9);
	int a[20], b[20];
	int i = 0,j=0,v=0,m;
	while (i < 9) {
		L.insertVertex(i + 1);
		i++;
	}
	L.insertEdge(0, 1, 2);
	L.insertEdge(0, 5, 1);
	L.insertEdge(0, 6, 1);
	L.insertEdge(1, 2, 2);
	L.insertEdge(1, 3, 4);
	L.insertEdge(2, 3, 1);
	L.insertEdge(2, 5, 3);
	L.insertEdge(2, 6, 2);
	L.insertEdge(3, 4, 1);
	L.insertEdge(3, 6, 6);
	L.insertEdge(3, 7, 5);
	L.insertEdge(3, 8, 2);
	L.insertEdge(4,5,5);
	L.insertEdge(5,6,1);
	L.insertEdge(6,7,3);
	L.insertEdge(7,8,2);
	cout <<"当前路由器个数为:"<< L.NumberOfVertices() << endl;
	while (1) {
		cout << "1:生成某个路由器的路由表" << endl;
		cout << "2:删除原拓扑中的一个路由器,重新生成路由表" << endl;
		cout << "3:删除原拓扑中的一条边，重新生成路由表" << endl;
		cout << "4:退出系统" << endl;
		cout << "请输入你的选择:";
			cin >> m;
			if (m == 1) {
				cout << "请输入你想生成路由表的路由器号:";
				cin >> v;
				L.ShortestPath(L, v-1, a, b);
			}
			if (m == 2) {
				cout << "请输入你想删除的路由器号:";
					cin >> v;
					L.removeVertex(v - 1);
					cout << "当前路由器个数为:" << L.NumberOfVertices() << endl;
					cout << "请输入你想生成路由表的路由器号:";
					cin >> v;
					L.ShortestPath(L, v - 1, a, b);
			}
			if (m == 3) {
				cout << "请输入你要删除的边两个路由器号:";
				cin >> v >> m;
				L.removeEdge(v, m);
				cout << "请输入你想生成路由表的路由器号:";
				cin >> v;
				L.ShortestPath(L, v - 1, a, b);
			}
			if (m == 4) {
				exit(1);
			}
	}
	system("pause");
	return 0;
}}
