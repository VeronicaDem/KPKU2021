const int max = 100;
struct Stek {
	int top;
	string s[max];
};
struct elem {
	string info; // поле с данными
	elem * next;
};
elem * AddElemHead(elem * head, int inf) { // вставка в начало head = AddElem(Head, a)
	elem * temp = new elem;
	temp->info = inf;
	temp->next = head;
	return temp;
}
elem * AddElemLast(elem * head,string inf) {
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
void initSt(Stek & St) {
	St.top = -1;

}
bool EmptySt(Stek  St) {
	return St.top == -1;
}
void inputSt(Stek & St, string x) {
	if (St.top == max - 1) {
		cout << "Переполнение " << endl;
	}
	else {
		St.top++;
		St.s[St.top] = x;
	}
}
void OutSt(Stek & St, string & x) {
	if (EmptySt(St)) {
		cout << "Пуст" << endl;
	}
	else {
		x = St.s[St.top];
		St.top--;
	}
}
