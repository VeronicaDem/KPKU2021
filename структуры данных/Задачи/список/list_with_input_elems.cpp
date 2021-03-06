// list0.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <clocale> 
using namespace std;

struct elem {
	int info;
	elem * next;
};
elem * initList(int info) {
	elem * head = new elem;
	head->info = info;
	head->next = NULL;
	return head;
}
elem * AddElemLast(elem * head, int info) {
	elem * new_elem = new elem;
	new_elem->info = info;
	new_elem->next = NULL;
	elem * temp = head;
	if (head == NULL) return new_elem;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new_elem;
	return head;
}
void DestroyList(elem * head) {
	elem * temp = head;
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
	}
}
void printList(elem * head) {
	elem * curr = head;
	while (curr != NULL) {
		cout << curr->info << endl;
		curr = curr->next;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество элементов списка ";
	cin >> n;
	elem * list;
	cout << "Введите элемент ";
	int to_add;
	cin >> to_add;
	list = initList(to_add);
	for (int i = 0; i < n - 1;i++){
		cout << "Введите элемент ";
		cin >> to_add;
		AddElemLast(list, to_add);
	}
	
	system("pause");
    return 0;
}

