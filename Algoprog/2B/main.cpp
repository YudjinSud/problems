#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

class Stack {
    int top = 0;
public:
    int stack[100];

    void push(int x) {
        stack[top++] = x;
    }

    void clear() {
        top = 0;
    }

    int pop() {
        return stack[--top];

    }

    int back() {
        return stack[top-1];
    }

    int size() {
        return top;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string cmd;
    int op;
    Stack stack;
    while(cmd != "exit") {
        cin >> cmd;
        if(cmd == "push") {
            cin >> op;
            stack.push(op);
            cout << "ok";
        }
        else if(cmd == "pop") {
            cout << stack.pop();
        }
        else if(cmd == "back") {
            cout << stack.back();
        }
        else if(cmd == "size") {
            cout << stack.size();
        }
        else if(cmd == "clear") {
            stack.clear();
            cout << "ok";
        }
        else {
            cout << "bye";
            break;
        }
//        for(int i = 0; i <= 5; i++) {
//            cout << stack.stack[i] << " ";
//        }
        cout << "\n";
    }

    return 0;
}