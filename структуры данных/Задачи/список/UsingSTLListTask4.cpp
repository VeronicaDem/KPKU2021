// UsingSTLListTask4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
using namespace std;
bool exist1(int chislo) {
    while (chislo) {
        if (chislo % 10 == 1) return true;
        chislo /= 10;
    }
    return false;
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
    auto end = prev(li.end(), 2);
    auto curr = next(li.begin(), 1);
    while (curr != end) {
        if (!exist1(*curr) && *next(curr, 1) == 8) {
            curr = li.erase(curr);
        }
        curr++;
    }
    if (!exist1(*li.begin()) && *next(li.begin(), 1) == 8) {
        li.erase(li.begin());
    }
    copy(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
}

