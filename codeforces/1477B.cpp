// 1477BIteratorList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
using namespace std;

bool checkNanako(int Li, int Ri, string s) {
    bool flag0 = false;
    bool flag1 = false;
    for (int i = Li - 1; i < Ri; i++) {
        if (s[i] == 0) flag0 = true;
        if (s[i] == 1) flag1 = true;
        if (flag0 == flag1 == true) {
            break;
        }
    }
    if (flag0 && flag1) {
        return false; // строка не прошла проверку
    }
    return true; // строка прошла проверку

}
int main()
{
    int t;
    cin >> t;
    string result = "";
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        string f;
        cin >> f;
        
        int Li;
        int Ri;
        cin >> Li >> Ri;
        
        int k = 1; // счетчик дней
        // 1-ая проверка Nanako
        if (!checkNanako(Li, Ri, s)) {
                result += "NO\n";
                cout << "здесь" << endl;
                for (int i = 1; i < q; i++) {
                    cin >> Li >> Ri;
                }
        }
        else {
                // прошли проверку
            set<int> pos;
            for (int j = 0; j < n; j++) {
                if (s[j] != f[j]) pos.insert(j);
            }
            set<int> new_pos;
            do {
                auto it = pos.begin();
                int count_replace = 0;
                while (it != pos.end()) {
                    if (Li - 1 <= *it < Ri) {
                        if (count_replace < (Ri - Li + 1) / 2) {
                            s[*it] = f[*it];
                            count_replace++;
                        }
                    }
                    it++;
                    
                }
                k++; // новый день
                if (k > q && new_pos.size() != 0) {
                    result += "NO\n";
                    break;
                }
                cin >> Li >> Ri;
                // проверка Nanako
                if (!checkNanako(Li, Ri, s)) {
                    // заполняем new_pos
                    int count0 = 0;
                    int count1 = 0;
                    auto it = pos.begin();
                    while (it != pos.end()) {
                        if (Li - 1 <= *it < Ri) {
                            if (s[*it] == 0) count0++;
                            if (s[*it] == 1) count1++;
                        }
                        it++;
                    }
                    while (it != pos.end()) {
                        if (Li - 1 <= *it < Ri) {
                            if (s[*it] == 0 && count0 > count1) {
                                s[*it] = 1;
                                new_pos.insert(*it);
                            }
                            else if (s[*it] == 1 && count1 > count0) {
                                s[*it] = 0;
                                new_pos.insert(*it);
                            }
                            
                        }
                        new_pos.insert(*it);
                        it++;
                    }
                }
                pos = new_pos;
            } while (new_pos.size() != 0 && k <= q);
            if (new_pos.size() != 0 && k > q) {
                result += "NO\n";
            }
            else {
                result += "YES\n";
            }
        }

        
    }
    cout << result;
}

