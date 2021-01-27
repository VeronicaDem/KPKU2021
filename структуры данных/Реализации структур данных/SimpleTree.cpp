

#include <iostream>
using namespace std;
struct tree {
	int info;
	tree* L;
	tree* R;
};
void ADDDDP(tree* p, int x) {
	tree* q;
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

void print(tree* t) {
	if (t != 0) {
		cout << t->info << endl;

		print(t->L);

		print(t->R);
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	tree* t = new tree;
	int x;
	cin >> x;
	t->info = x;
	t->L = NULL;
	t->R = NULL;
}