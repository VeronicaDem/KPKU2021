// tree_simple.cpp : Defines the entry point for the console application.
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
int kolvo(tree * p, double a) {
	if (p != NULL) {
		if (p->info < a) {
			return 1 + kolvo(p->L, a) + kolvo(p->R, a);
		}
		else return  kolvo(p->L,a) + kolvo(p->R,a);
	}
	return 0;
}
int kolvo2(tree * p, double a, double b) {
	if (p != NULL) {
		if (p->info <= b && p->info >=a) {
			return 1 + kolvo(p->L, a) + kolvo(p->R, a);
		}
		else return  kolvo(p->L, a) + kolvo(p->R, a);
	}
	return 0;
}
int sum(tree * p, double a) {
	if (p != NULL) {
		if (p->info > a) {
			return p->info + sum(p->L, a) + sum(p->R, a);
		}
		else return  sum(p->L, a) + sum(p->R, a);
	}
	return 0;
}

void avg(tree * p, int &a, int &b) {

	if (p != NULL) {
		
			a += p->info;
			b++;
		
		avg(p->L, a, b);
		avg(p->R, a, b);
	}
	
}
int max(tree * p) {
	while (p->R != NULL) {
		p = p->R;
	}
	return p->info;
}
int min(tree * p) {
	while (p->L != NULL) {
		p = p->L;
	}
	return p->info;
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
	int a = 0;
	int b = 0;
	avg(t, a, b);
	print(t);
	cout << "************" << endl;
	double avg_tree = (double)a / b;
	int count = kolvo(t, avg_tree);
	cout << count << endl;
	int delta = max(t) - min(t);
	int sum2 = sum(t, delta);
	cout << sum2 << endl;
	system("pause");
	return 0;
}






