// embedded_brackets.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
using namespace std;

struct elem {
	string info;
	elem* next;
};
elem* AddElemHead(elem* head, int inf) { // вставка в начало head = AddElem(Head, a)
	elem* temp = new elem;
	temp->info = inf;
	temp->next = head;
	return temp;
}
elem* AddElemLast(elem* head, string inf) {
	elem* temp = new elem;
	temp->info = inf;
	temp->next = NULL;
	elem* curr;
	if (head == NULL) return temp;
	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = temp;
	return head;
}
elem* inputElem(elem* head, string info) {
	elem* temp = new elem;
	temp->next = NULL;
	temp->info = info;
	if (head == NULL) {
		head = temp;
		return head;
	}
	elem* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = temp;
    
	return head;
}
bool emptyStack(elem* head) {
	return head == NULL;
}
elem* outElem(elem* head) {
	if (emptyStack(head)) {
		cout << "Нет элементов" << endl;
		return NULL;
	}
	elem* top = head;
	if (head->next == NULL) {
		head = NULL;
		return head;
	}
	while (top->next != NULL) {
		top = top->next;
	}
	elem* prev = head;
	while (prev->next->next != NULL) {
		prev = prev->next;
	}
	prev->next = NULL;
	return top;
}


int main()
{
	setlocale(LC_ALL, "rus");
	elem* head = NULL;

	bool correct = true;
	string all_string;

	cout << "Введите строку для проверки" << endl;
	cin >> all_string;
	for (int i = 0; i < all_string.size(); i++) {
		if (all_string[i] == ')') {
			if (emptyStack(head)) {
				correct = false;
				break;
			}
			else {
				head = outElem(head);
			}
		}
		else if (all_string[i] == '(') {
			 head = inputElem(head, "*");
		}
	}
	
	if (correct && emptyStack(head)) {
		cout << "Верно" << endl;
	}
	else cout << "Неверно" << endl;
	system("pause");
	return 0;
}

