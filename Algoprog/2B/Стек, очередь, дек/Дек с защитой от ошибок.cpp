//
// Created by yudjin on 08.08.2020.
//

#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

#define error -1234567
#define startPos 1000000
#define endPos 1000000
#define sz 2000000


class Dequeue {
    vi dequeue = vi(sz);
    int start = startPos, end = endPos;


    int check() {
        return start != end;
    }

    int universal_back(int pos, int inc) {
        int res = 0;
        if (check()) {
            res = dequeue[pos + inc];
        } else res = error;
        return res;
    }


public:
    void push_back(int x) {
        dequeue[end++] = x;
    }

    void push_front(int x) {
        dequeue[--start] = x;
    }

    int pop_front() {
        int res = universal_back(start, 0);
        if(res != error) start++;
        return res;
    }

    int pop_back() {
        int res = universal_back(end, -1);
        if(res != error) end--;
        return res;
    }


    int front() {
        return universal_back(start, 0);
    }

    int back() {
        return universal_back(end, -1);
    }


    int size() {
        return end - start;
    }

    void clear() {
        start = startPos;
        end = endPos;
    }

    void print() {
        cout << "Queue :: start = " << start << " end = " << end << "\n";
        cout << "[";
        for (int i = start; i < end; i++) {
            cout << dequeue[i] << ",";
        }
        cout << "]\n";
    }
};

void coutCheckAnswer(int res) {
    if (res == -11111) {
        cout << "error";
    } else
        cout << res;
}


int32_t main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    Dequeue q;
    string cmd;
    int op;

    while (cmd != "exit") {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> op;
            q.push_front(op);
            cout << "ok";
        } else if (cmd == "push_back") {
            cin >> op;
            q.push_back(op);
            cout << "ok";
        } else if (cmd == "pop_back") {
            coutCheckAnswer(q.pop_back());
        } else if (cmd == "pop_front") {
            coutCheckAnswer(q.pop_front());
        } else if (cmd == "back") {
            coutCheckAnswer(q.back());
        } else if (cmd == "front") {
            coutCheckAnswer(q.front());
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
        //  q.print();
    }

    return 0;
}

