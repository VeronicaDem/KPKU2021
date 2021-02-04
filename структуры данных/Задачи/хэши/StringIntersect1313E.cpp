// StringIntersect1313E.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <functional>
#include <string>
#include <vector>
using namespace std;
string concat(string s, int i, int k) {
    string result = "";
    for (int c = i; i < k; i++) {
        result += s[c];
    }
    return result;
}
int main()
{
    setlocale(LC_ALL,"rus");
    int n, m;
    cin >> n >> m;
    string a, b, s;
    cin >> a >> b >> s;
    hash<string> str_hash;
    int k = 0;
    int lenA = 1;
    int lenB = 1;
    while (lenA + lenB <= m) {
        for (int i = 0; i < n - lenA; i++) {
  
            string s1 = concat(a, i, i + lenA);
            for (int j = 0; j < n - lenB; j++) {
                string s2 = concat(b, j, j + lenB);
                if (str_hash(s1 + s2) == str_hash(s) && ((i <= j && i + lenA <= j + lenB) || i >= j && i + lenA >= j + lenB)) {
                    k++;
                }
            }
            lenB++;
        }
        lenA++;
        lenB = 1;
    }
    lenA = lenB = 1;
    while (lenA + lenB <= m) {
      for (int i = 0; i < n - lenB; i++) {
            string s1 = concat(b, i, i + lenB);
            for (int j = 0; j < n - lenA; j++) {
                string s2 = concat(a, j, j + lenA);
                if (str_hash(s1 + s2) == str_hash(s) && ((i <= j && i + lenA <= j + lenB) || i >= j && i + lenA >= j + lenB)) {
                    k++;
                }
            }
            lenA++;
        }
        lenB++;
        lenA = 1;
    }
    cout << k << endl;
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
