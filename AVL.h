#ifndef AVL_H
#define AVL_H

#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct AVLNode {
	string key;                 // 关键字(键值)
	string chinese;             // 汉译
	int height;                 // 高度
	AVLNode *left;              // 左孩子
	AVLNode *right;             // 右孩子
	AVLNode(string value, string chin, AVLNode *l, AVLNode *r) :
		key(value), chinese(chin), height(0), left(l), right(r) {}
};

class AVL {
public:
	AVL():root(NULL){}
	~AVL();
	void Insert(string, string);           //插入新节点
	AVLNode *Search( string);              //搜索函数
private:
	AVLNode *root;                         //根节点
	void RotateL(AVLNode*&);               //左单旋
	void RotateR(AVLNode*&);               //右单旋
	void RotateLR(AVLNode*&);              //先左后右双旋
	void RotateRL(AVLNode*&);              //先右后左双旋
	void destroy(AVLNode *&);              //销毁AVL树
};

void AVL::destroy(AVLNode* &tree) {
	if (tree == NULL) return;
	if (tree->left != NULL) destroy(tree->left);
	if (tree->right != NULL) destroy(tree->right);
	delete tree;
}

AVL::~AVL() {
	destroy(root);
}

void AVL::RotateL(AVLNode *& ptr) {
	AVLNode *subL = ptr;
	ptr = subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	ptr->height = subL->height = 0;
}

void AVL::RotateR(AVLNode *& ptr) {
	AVLNode *subR = ptr;
	ptr = subR->left;
	subR->left = ptr->right;
	ptr->right = subR;
	ptr->height = subR->height = 0;
}

void AVL::RotateLR(AVLNode *& ptr) {
	AVLNode *subR = ptr,*subL = subR->left;
	ptr = subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->height <= 0) subL->height = 0;
	else subL->height = -1;
	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->height == -1) subR->height = 1;
	else subR->height = 0;
	ptr->height = 0;
}

void AVL::RotateRL(AVLNode *& ptr) {
	AVLNode *subL = ptr, *subR = subL->right;
	ptr = subR->left;
	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->height >= 0) subR->height = 0;
	else subR->height = 1;
	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->height == 1) subL->height = -1;
	else subL->height = 0;
	ptr->height = 0;
}

void AVL::Insert(string a, string b) {
	AVLNode *pr = NULL, *p = root, *q;
	int d;
	stack <AVLNode*> st;
	while (p != NULL) {
		if (a == p->key) return;
		pr = p;
		st.push(pr);
		if (a.compare(p->key) < 0) p = p->left;
		else if (a.compare(p->key) > 0) p = p->right;
	}
	p = new AVLNode(a, b, NULL, NULL);
	if (pr == NULL) {
		root = p;
		return;
	}
	if (a.compare(pr->key) < 0) pr->left = p;
	else if (a.compare(pr->key) > 0) pr->right = p;
	while (st.empty() == 0) {
		pr = st.top();
		st.pop();
		if (p == pr->left) pr->height--;
		else pr->height++;
		if (pr->height == 0) break;
		if (pr->height == 1 || pr->height == -1) p = pr;
		else {
			d = (pr->height < 0) ? -1 : 1;
			if(p->height == d) {
				if(d == -1) RotateR(pr);
				else RotateL(pr);
			}
			else {
				if (d == -1) RotateLR(pr);
				else RotateRL(pr);
			}
			break;
		}
	}
	if (st.empty() == 1) root = pr;
	else {
		q = st.top();
		if (q->key.compare(pr->key) > 0) q->left = pr;
		else q->right = pr;
	}
	return;
}

AVLNode* AVL::Search(string a) {
	AVLNode* current = root;
	while(current!=NULL){
		if ( a == current->key)
		return current;
	if (a.compare(current->key) < 0)
		current = current->left;
	else current = current->right;
	}
	return NULL;
}

#endif // !AVL_H
