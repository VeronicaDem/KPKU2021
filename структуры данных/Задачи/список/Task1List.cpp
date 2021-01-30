// Task1List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct elem {
	int info; // поле с данными
	elem* next;
};

elem* AddElemHead(elem* head, int inf) { // вставка в начало head = AddElem(Head, a)
	elem* temp = new elem;
	temp->info = inf;
	temp->next = head;
	return temp;
}
elem* AddElemLast(elem* head, int inf) {
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
// вставка в отсортированный по возрастанию список
elem* Insert(elem* head, int inf) {
	elem* curr = head;
	while (curr != NULL && curr->next != NULL && curr->info < inf && curr->next->info < inf) {
		curr = curr->next;

	}
	if (curr == NULL) {
		return AddElemHead(head, inf);
	}
	if (curr->next == NULL) {
		return AddElemLast(head, inf);
	}
	elem* temp = new elem;
	temp->info = inf;
	temp->next = curr->next;
	curr->next = temp;
	return head;
}
void PrintList(elem* head) {
	elem* curr;
	curr = head;
	while (curr != NULL) {
		cout << curr->info << endl;
		curr = curr->next;
	}
}
elem* init(int inf) {
	elem* head = new elem;
	head->info = inf;
	head->next = NULL;
	return head;
}
void destroyList(elem* head) {
	elem* curr = head;
	while (head != NULL) {
		head = head->next;
		delete curr;
		curr = head;
	}
}
elem* reverseList(elem* head) {
	elem* new_head = NULL;
	elem* temp = head;
	while (temp != NULL) {
		new_head = AddElemHead(new_head, temp->info);
		temp = temp->next;
		
	}
	return new_head;
	
}
int main()
{
	setlocale(LC_ALL, "rus");
	elem* head = NULL;
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
	elem* new_list = reverseList(head);
	PrintList(new_list);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
