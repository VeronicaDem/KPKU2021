// list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
// реализация списка
struct elem {
	int info; // поле с данными
	elem * next;
};

elem * AddElemHead(elem * head, int inf) { // вставка в начало head = AddElem(Head, a)
	elem * temp = new elem;
	temp->info = inf;
	temp->next = head;
	return temp;
}
elem * AddElemLast(elem * head, int inf) {
	elem * temp = new elem;
	temp->info = inf;
	temp->next = NULL;
	elem * curr;
	if (head == NULL) return temp;
	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = temp;
	return head;
}
// вставка в отсортированный по возрастанию список
elem * Insert(elem * head, int inf) {
	elem * curr = head;
	while (curr != NULL && curr->next != NULL && curr->info < inf && curr->next->info < inf) {
		curr = curr->next;

	}
	if (curr == NULL) {
		return AddElemHead(head, inf);
	}
	if (curr->next == NULL) {
		return AddElemLast(head, inf);
	}
	elem * temp = new elem;
	temp->info = inf;
	temp->next = curr->next;
	curr->next = temp;
	return head;
}
void PrintList(elem * head) {
	elem * curr;
	curr = head;
	while (curr != NULL) {
		cout << curr->info << endl;
		curr = curr->next;
	}
}
elem * init(int inf) {
	elem * head = new elem;
	head->info = inf;
	head->next = NULL;
	return head;
}
void destroyList(elem * head) {
	elem * curr = head;
	while (head != NULL) {
		head = head->next;
		delete curr;
		curr = head;
	}
}


//
int sumZifr(int chislo) {
	int temp = chislo;
	int s = 0;
	while (temp) {
		s += temp % 10;
		temp /= 10;
	}
	return s;
}

int main()
{
	setlocale(LC_ALL, "rus");
	elem * head = NULL;
	int size;
	cout << "Введите размер списка ";
	cin >> size;
	cout << "Введите элемент списка ";
	int inf;
	cin >> inf;
	head = init(inf);
	for (int i = 1; i < size; i++) {
		cout << "Введите элемент списка ";
		cin >> inf;
		AddElemLast(head, inf);

	}
	PrintList(head);
	int sum = 0;
	elem * curr = head;
	while (curr != NULL) {
		if (curr->info % 2 == 0) {
			sum += curr->info;
		}
		curr = curr->next;
	}
	cout << "Сумма четных элементов " << sum << endl;

	curr = head;
	int max = head->info;
	int min = head->info;
	while (curr != NULL) {
		if (max < curr->info) {
			max = curr->info;
		}
		if (min > curr->info) {
			min = curr->info;
		}
		curr = curr->next;
	}
	cout << "Максимальный элемент " << max << endl;

	curr = head;
	int p = 1;
	while (curr != NULL) {
		if (sumZifr(curr->info) % 2 == 0) {
			p *= curr->info;
		}
		curr = curr->next;
	}
	cout << "Произведение " << p << endl;
	/*
	curr = head;
	while (curr != NULL) {
		curr->info = curr->info > 0 ? curr->info * curr->info : -curr->info;
		curr = curr->next;
	}
	PrintList(head);
	*/
	curr = head;
	while (curr != NULL) {
		curr->info = curr->info - max;
		curr = curr->next;
	}
	PrintList(head);

	 curr = head;
	float a = 0;
	int k = 0;
	while (curr != NULL) {
		
			a += curr->info;
			k++;
		
		curr = curr->next;
	}
	
	a = a / k;
	curr = head;
	int count = 0;
	while (curr != NULL) {
		if (curr->info % 2 == 0) {
			if (curr->info > a) {
				count++;
			}
		}
		curr = curr->next;
	}
	cout << "Количество " << count << endl;

	curr = head;
	int delta = max - min;
	while (curr != NULL) {
		if (curr->info % 3 == 0) {
			curr->info = delta;
		}
		curr = curr->next;
	}
	PrintList(head);
	destroyList(head);
	system("pause");
    return 0;
}

