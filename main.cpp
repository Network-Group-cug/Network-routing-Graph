#include<iostream>
#include<string>
#include<stdlib.h>
#include "Management.h"
#include"AVL.h"

using namespace std;

int main() {
	/*string a("abc");
	string b("abde");
	cout << a.compare(b);*/
	string word("1");
	Management Dictionary;
	Dictionary.ReadFile("dictionary.txt");
	cout << "请输入要查询的单词，退出请输入Q：";
	cin >> word;
	while (1) {
		if (word == "Q") Dictionary.Quite();
		else Dictionary.Search(word);
		cout << "****************************************************" << endl;
		cout << "请输入要查询的单词，退出请输入Q：";
		cin >> word;
	}
	system("pause");
	return 0;
}
