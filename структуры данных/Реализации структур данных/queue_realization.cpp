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
struct list {
    int field;
    struct list* ptr;
};
struct queue {
    struct list* frnt, * rear;
};
void init(queue * q) {
    q->frnt = 0;
    q->rear = 0;
}
int isempty(queue* q) {
    if (q->frnt == 0 && q->rear == 0)
        return 1;
    else
        return 0;
}
void pushElem(queue* q, int field) {
    if (isempty(q)) {
        q->frnt =  new list;
        q->frnt->field = field;

    }
    else {
        list * p = q->rear;
        while (p->ptr!= 0) {
            p = p->ptr;
        }
        p->ptr = new list;
        p->field = field;
        p->ptr->ptr = 0;
        q->rear = p->ptr;


    }
}
void pullElem(queue* qu, int & top) {
    if (isempty(qu)) {
        cout << "Пусто" << endl;
    }
    else {
        top = qu->frnt->field;
        qu->frnt = qu->frnt->ptr;
        if (qu->frnt == 0) {
            qu->rear = 0;
        }
    }
}

