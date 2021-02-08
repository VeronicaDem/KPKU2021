// UsingSTLListTask2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include<list>
using namespace std;
bool symmetric(list<int> & const li) {
    list<int>::iterator i = li.begin();
    list<int>::iterator i_end = li.end();
    i_end--;
    while (i != i_end && next(i, 1) != i_end) {
        if (*i != *i_end) return false;
        i++;
        i_end--;
    }
    return true;
}
int max(list<int>& const li) {
    int max = *(li.begin());
    for (auto i : li) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}
int main()
{
    list<int> li;
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int info;
        cin >> info;
        li.push_back(info);
    }
    if (!symmetric(li)) {

        int m = max(li);
        list<int>::iterator curr = li.begin();
        list<int>::iterator end = li.end();
        end--;
        curr++;
        while (curr != end) {
            list<int>::iterator prev = curr;
            prev--;
            list<int>::iterator next = curr;
            next++;
            if (*prev > 0 && *next > 0 && *curr % 10 == 7) {
                *curr = m;
            }
            curr++;
        }
    }
    copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
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
