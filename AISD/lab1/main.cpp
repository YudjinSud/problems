#include <bits/stdc++.h>

#define RESET   "\033[0m"
#define FAILURE     "\033[1m\033[31m"    
#define SUCCES   "\033[1m\033[32m"      

using namespace std;

//скобки::=А | B | ( скобки скобки )

int getNextSkobki(string s, int &k, int depth);

void error(string, int, int);

void printDepth(string s, int k, int depth) {
    for (int i = 0; i < depth; i++) cout << " ";
    cout << "Parsed ";
    for (int i = depth; i <= k; i++) cout << s[i];
    cout << "\n";
}

int parser(string s, int &k, int depth) {
    if (s[k] == 'A' || s[k] == 'B') {
        printDepth(s, k, k);
        return 1;
    }

    // Внутри () ждем 2 скобки
    depth = k;
    if (s[k] == '(') {
        if (getNextSkobki(s, ++k, depth + 1)) {
            if (getNextSkobki(s, ++k, depth + 1)) {
                if (s[++k] == ')') {
                    printDepth(s, k, 0);
                    return 1;
                } else
                    error(s, k, 4);
            } else
                error(s, k, 3);
        } else
            error(s, k, 2);
    }
    return 0;
}

int getNextSkobki(string s, int &k, int depth) {
    if (s[k] == 'A' || s[k] == 'B') {
        printDepth(s, k, k);
        return 1;
    }
    depth = k;
    if (s[k] == '(') {
        if (getNextSkobki(s, ++k, depth + 1)) {
            if (getNextSkobki(s, ++k, depth + 1)) {
                if (s[++k] == ')') {
                    printDepth(s, k, depth);
                    return 1;
                }
            }
        }
    }
    return 0;
}

void error(string s, int k, int c) {
    cout << FAILURE;
    switch (c) {
        case 1:
            cout << "Недопустимый символ в скобке: " << s[k] << " на позиции " << k << "\n";
            break;
        case 2:
            cout << "НЕ скобка после ( на позиции " << k << "\n";
            break;
        case 3:
            cout << "Нет второй скобки в () на позиции " << k << "\n";
            break;
        case 4:
            cout << "Нет закрывающей ) в скобке на позиции " << k << "\n";
            break;
    }
}

void runTests() {
    int cnt = 0;
    vector<string> tests;
    tests.emplace_back("A");
    tests.emplace_back("(AB)");
    tests.emplace_back("((AB)(AB))");
    tests.emplace_back("((AB)B)");
    tests.emplace_back("((A(AB))B)");
    tests.emplace_back("((A((A(AB))B))B)");
    tests.emplace_back("(((AB)(AB))((AB)(AB)))");
    tests.emplace_back("(B(AA))");
    tests.emplace_back("((AB)(A(((AB)(AB))((AB)(AB)))))");
    // НЕ СКОБКИ
    tests.emplace_back("d");
    tests.emplace_back("(A)");
    tests.emplace_back("(A(B))");
    for (const auto &t : tests) {
        int k = 0, depth = 0;
        if (parser(t, k, depth)) {
            cnt++;
            cout << SUCCES << t << " passed\n";
        } else {
            cout << FAILURE << t << " not passed\n";
        }
        cout << RESET;
    }
    cout << SUCCES << cnt << " tests PASSED" << FAILURE << " " << tests.size() - cnt << " NOT PASSED \n";
}


int main() {
    int f;
    cout << "if you want to input from file press 1 else press 0\n";
    cin >> f;
    if (f) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cout << "Введите строку:\n";
    string s;
    cin >> s;
    int k = 0, depth = 0;
    if (parser(s, k, depth)) {
        cout << SUCCES << s << " is skobki!\n";
    } else cout << FAILURE << s << "not a skobki\n";
  //  runTests();
    return 0;
}
