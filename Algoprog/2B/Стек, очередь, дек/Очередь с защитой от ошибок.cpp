
//
// Created by yudjin on 08.08.2020.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;


class Queue {
    int sz = 200;
    vi queue = vi(sz);
    int start = 0, end = 0;

    void shiftQueue() {
        for (int i = 0; i <= end - start; i++) {
            queue[i] = queue[start + i];
        }
        end -= start;
        start = 0;
    }

public:
    void push(int x) {
        if (end >= sz) {
            shiftQueue();
        }
        queue[end++] = x;
    }

    int pop() {
        if (start != end) {
            return queue[start++];
        } else return -11111; // а вдруг такой элемент есть в очереди...

    }

    int front() {
        if (start != end) {
            return queue[start];
        } else return -11111;
    }

    int size() {
        return end - start;
    }

    void clear() {
        start = 0;
        end = 0;
    }

    void print() {
        cout << "Queue :: start = " << start << " end = " << end << "\n";
        for (int i = start; i < end; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }

};


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Queue q;
    string cmd;
    int op;

    while (cmd != "exit") {
        cin >> cmd;
        if (cmd == "push") {
            cin >> op;
            q.push(op);
            cout << "ok";
        } else if (cmd == "pop") {
            int res = q.pop();
            if (res == -11111) {
                cout << "error";
            } else
                cout << res;
        } else if (cmd == "front") {
            int res = q.front();
            if (res == -11111) {
                cout << "error";
            } else
                cout << res;
        } else if (cmd == "size") {
            cout << q.size();
        } else if (cmd == "clear") {
            q.clear();
            cout << "ok";
        } else {
            cout << "bye";
            break;
        }
        cout << "\n";
        // q.print();
    }

    return 0;
}