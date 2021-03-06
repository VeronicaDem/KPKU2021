// prost_tree.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct tree {
	int info;
	tree * L;
	tree * R;
};
void ADDDDP(tree * p, int x) {
	tree *q;
	if (x < p->info) {
		if (p->L == NULL) {
			q = new tree;
			q->info = x;
			q->L = NULL;
			q->R = NULL;
			p->L = q;
		}
		else ADDDDP(p->L, x);
	}
	else {
		if (p->R == NULL) {
			q = new tree;
			q->info = x;
			q->L = NULL;
			q->R = NULL;
			p->R = q;
		}
		else ADDDDP(p->R, x);
	}
}
void print(tree * p) {
	if (p != NULL) {
		print(p->L);
		cout << p->info << endl;
		print(p->R);
	}
}
bool prost(int a) {
	for (int i = 2; i <= a / 2; i++) {
		if (a % i == 0) return false;
	}
	return true;
}
int sum_prost_leaves(tree * t) {
	if (t != 0) {
		if (t->R == 0 && t->L == 0 && prost(t->info)) {
			return t->info + sum_prost_leaves(t->L) + sum_prost_leaves(t->R);
		}
		else return sum_prost_leaves(t->L) + sum_prost_leaves(t->R);
	}
	else return 0;
}
int sum_prost(tree * t) {
	if (t != 0) {
		if (prost(t->info)) {
			return t->info + sum_prost(t->R) + sum_prost(t->L);
		}
		else return sum_prost(t->R) + sum_prost(t->L);
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "rus");
	tree * t = new tree;
	int x;
	cin >> x;
	t->info = x;
	t->L = NULL;
	t->R = NULL;
	cin >> x;
	while (x != 0) {
		ADDDDP(t, x);
		cin >> x;
	}
	if (sum_prost_leaves(t) * 2 == sum_prost(t)) {
		cout << "Верно " << endl;
	}
	else {
		cout << "Неверно " << endl;
	}
	system("pause");
    return 0;
}

