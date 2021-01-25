// queue_in_school.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
struct queue {
	char info; // поле с данными
	queue* next;
};
int main()
{
   
    int n;
    int t;
    string data;
    cin >> n >> t;
    cin >> data;
    int sec = 0;
    bool flag = false;
    while (sec < t) {
        for (int i = 0; i < n; i++) {
            if (data[i] == 'B' && data[i + 1] == 'G') {
                char temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                flag = true;
            }
            else if (!flag) {
                continue;
            }
            else {
                flag = false;
            }
            sec++;
            flag = false;
        }
        cout << data << endl;



    }