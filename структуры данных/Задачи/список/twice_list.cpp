// twice_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list {
	int info;
	list * next;
	list * prev;
};
list * addLast(list * head, int info) {
	if (head == NULL) {
		head = new list;
		head->next = NULL;
		head->prev = NULL;
		head->info = info;
	}
	else {
		list * tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		list * newElem = new list;
		newElem->info = info;
		newElem->next = NULL;
		newElem->prev = tmp;
		tmp->next = newElem;
	}
	return head;
}
void destroyList(list * head) {
	list * tmp = head;
	while (tmp != NULL) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}
double avg(list * head) {
	double a = 0;
	int k = 0;
	list * p = head->next;
	while (p->next != NULL) {
		if (p->prev->info == p->next->info) {
			k++;
			a += p->info;
		}
		p = p->next;
	}
	return a / k;
}
void printList(list * head) {
	list * p = head;
	while (p != NULL) {
		cout << p->info << endl;
		p = p->next;
	}
}
// вставить после каждого отрицательного элемента его противоположный 
void insertAfter(list * head) {
	list * tmp = head;
	while (tmp->next != NULL) {
		if (tmp->info < 0) {
			list * p = new list;
			p->info = -tmp->info;
			p->next = tmp->next;
			tmp->next->prev = p;
			p->prev = tmp;
			tmp->next = p;
		}
		tmp = tmp->next;
	}
	if (tmp->info < 0) {
		list * p = new list;
		p->info = -tmp->info;
		p->next = NULL;
		p->prev = tmp;
		tmp->next = p;
	}
}
list * reverseBetween(list * head, int x) {
	list * newList = NULL;
	list * p1 = head;
	list * p2 = head;
	while (p1 != NULL && p1->info != x) { // ищем первый x
		p1 = p1->next;
	}
	while (p2->next != NULL) {
		p2 = p2->next;
	}
	while (p2 != NULL && p2->info != x) {
		p2 = p2->prev;
	}
	list * iterator = head;
	while (iterator != p1) {
		newList = addLast(newList, iterator->info);
		iterator = iterator->next;
	}
	iterator = p2;
	while (iterator != p1) {
		newList = addLast(newList, iterator->info);
		iterator = iterator->prev;
	}
	while (p2 != NULL) {
		newList = addLast(newList, p2->info);
		p2 = p2->next;
	}
	return newList;
}
void reverseBetween2(list * head, int x) {
	list * first = head;
	list * last = head;
	while(last->next != NULL) {
		last = last->next;
	}
	while (first != NULL && first->info != x) {
		first = first->next;
	}
	while (last != NULL && last->info != x) {
		last = last->prev;
	}
	while (last != first || first->next != last->prev) {
		last->info = first->info;
		last = last->prev;
		first = first->next;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	list * lst = NULL;
	int size;
	cout << "Введите размер ";
	cin >> size;
	for (int i = 0; i < size; i++) {
		int info;
		cout << "Введите элемент ";
		cin >> info;
		lst = addLast(lst, info);
	}
	cout << "Введите x " << endl;
	int x;
	cin >> x;
	reverseBetween2(lst, x);
	cout << "*************************" << endl;
	printList(lst);
	system("pause");
    return 0;
}

