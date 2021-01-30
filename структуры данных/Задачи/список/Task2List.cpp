#include <iostream>
using namespace std;

struct list {
	int info;
	list* next;
	list* prev;
};
list* addLast(list* head, int info) {
	if (head == NULL) {
		head = new list;
		head->next = NULL;
		head->prev = NULL;
		head->info = info;
	}
	else {
		list* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		list* newElem = new list;
		newElem->info = info;
		newElem->next = NULL;
		newElem->prev = tmp;
		tmp->next = newElem;
	}
	return head;
}
void destroyList(list* head) {
	list* tmp = head;
	while (tmp != NULL) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void printList(list* head) {
	list* p = head;
	while (p != NULL) {
		cout << p->info << endl;
		p = p->next;
	}
}
bool symmetric(list* head) {
	list* begin = head;
	list* end = head;
	while (end->next != NULL) {
		end = end->next;
	}
	for (begin; begin != end; begin = begin->next, end = end->prev) {
		if (begin->info != end->info) {
			return false;
		}
	}
	return true;
}
int max(list* head) {
	list* begin = head;
	int m = begin->info;
	while (begin != NULL) {
		if (begin->info > m) {
			m = begin->info;
		}
		begin = begin->next;
	}
	return m;
}


int main()
{
	setlocale(LC_ALL, "rus");
	list* lst = NULL;
	int size;
	cout << "Введите размер ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		int info;
		cout << "Введите элемент ";
		cin >> info;
		lst = addLast(lst, info);
	}
	
	printList(lst);
	if (!symmetric(lst)) {
		int m = max(lst);
		list* temp = lst->next;
		while (temp != NULL && temp->next != NULL && temp->prev != NULL) {
			if (temp->info < 0 && temp->next->info > 0 && temp->prev->info > 0) {
				temp -> info = m;
			}
			temp = temp->next;
		}
	}
	
	printList(lst);
	system("pause");
	return 0;
}