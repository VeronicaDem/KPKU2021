// recursive_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct list {
	int info;
	list * next;
};
list * initList(int info) {
	list * head = new list;
	head->next = NULL;
	head->info = info;
	return head;
}
void createList(list * lst) {
	int x;
	cin >> x;
	if (x != 0) {
		lst->next = new list;
		lst->next->info = x;
		lst->next->next = NULL;
		createList(lst->next);
	}
}
void printList(list * lst) {
	if (lst != NULL) {
		cout << lst->info << endl;
		printList(lst->next);
	}
}
void zam(list * lst, int x, int x1) {
	if (lst != NULL) {
		if (lst->info == x) {
			lst->info = x1;
		}
		zam(lst->next, x, x1);
	}
}
void destroyList(list * head) {
	list * p = head;
	while (p != NULL) {
		head = head->next;
		delete p;
		p = head;
	}
}
int kol(list * lst, int x) {
	if (lst != NULL) {
		if (lst->info == x) {
			return kol(lst->next, x) + 1;
		}
		return kol(lst->next, x);
	}
	return 0;
}
int max(list * lst) {
	if (lst != NULL) {
		if ((*lst).next == NULL) return lst->info;
		else
		if (lst->info > max(lst->next)) return lst->info;
		else return max(lst->next);
	}
	
}
// avg четных элементов
double avg(list * lst, int k=0, double sum=0){
	if (lst != NULL) {
		if (lst->info % 2 == 0) return avg(lst->next, ++k, sum + lst->info); // обрати внимание на ++k
		else return avg(lst->next, k, sum);
	}
	return sum / k;
}
list * addElemLast(list * head, int info, list * iterator) {
	if (head == NULL) {
		head = new list;
		head->next = NULL;
		head->info = info;
		return head;
	}
	else {
		if (iterator->next != NULL) {
			return addElemLast(head, info, iterator->next);
		}
		list * newElem = new list;
		newElem->next = NULL;
		newElem->info = info;
		iterator->next = newElem;
		return head;
	}
}
list * copyList(list * oldList, list * newList=NULL) {
	if (oldList != NULL) {
		newList = addElemLast(newList, oldList->info, newList);
		return copyList(oldList->next, newList);
	}
	return newList;
}
int main()
{
	setlocale(LC_ALL, "rus");
	list * myList;
	int info;
	cin >> info;
	myList = initList(info);
	createList(myList);
	cout << "*********************" << endl;
	printList(myList);
	list * myList2;
	myList2 = copyList(myList);

	cout << "********************" << endl;
	printList(myList2);

	destroyList(myList2);
	destroyList(myList);
	system("pause");
    return 0;
}

