// queue_realization.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
// реализация через массив
#define max 100
struct Queue {
    int N, K; // N - индекс начала, K - индекс конца
    string Q[max]; // вместо string может быть любой тип данных
};
void initQ(Queue& Qu) {
    Qu.N = 0;
    Qu.K = -1;
}
bool emptyQ(Queue Qu) {
    return Qu.N == 0 && Qu.K == -1;
}
void outQ(Queue& Qu, string& x) {
    if (emptyQ(Qu)) cout << "Пусто" << endl;
    else {
        x = Qu.Q[Qu.N];
        Qu.N++;
    }
}
void inQ(Queue& Qu, string x) {
    if (Qu.N == 0 && Qu.K == max - 1) {
        cout << "Переполнение";
    }
    else {
        if (Qu.K == max - 1) {
            for (int i = 0; i < Qu.K - Qu.N + 1; i++) {
                Qu.Q[i] = Qu.Q[i + Qu.N];
            }
            Qu.K = Qu.K - Qu.N;
            Qu.N = 0;
        }
        Qu.K++;
        Qu.Q[Qu.K] = x;
    }
}
// реализация через список
struct queue {
    char info; // поле с данными
    queue* next;
};

queue* pushQueue(queue* head, char inf) {
    queue* temp = new queue;
    temp->info = inf;
    temp->next = NULL;
    queue* curr;
    if (head == NULL) return temp;
    curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
queue* pullQueue(queue* head, string& answer) {
    if (head == NULL) {
        cout << "Нет элементов" << endl;
        return NULL;
    }
    queue* top = head;
    head = head->next;
    answer = top->info;
    return head;
}
bool isempty(queue* q) {
    return q == NULL;
}
