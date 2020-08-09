//
// Created by yudjin on 09.08.2020.
//
#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

using namespace std;

#define error -1234567
#define startPos 1000000
#define endPos 1000000
#define sz 2000000
#define endGame 1e6


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
    if (res == error) {
        cout << "error";
    } else
        cout << res;
}

void read(Dequeue &m) {
    int x;
    for(int i = 0; i < 5; i++) {
        cin >> x;
        m.push_back(x);
    }
}

int32_t main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    Dequeue first, second;

    read(first);
    read(second);

    int count = 0;

    while(first.size() > 0 && second.size() > 0 && count != endGame) {
        int f = first.pop_front();
        int s = second.pop_front();

        if(s == 0 && f == 9) {
            second.push_back(f);
            second.push_back(s);
        }
        else if(f == 0 && s == 9) {
            first.push_back(f);
            first.push_back(s);
        }
        else if(s > f) {
            second.push_back(f);
            second.push_back(s);
        }
        else if(f > s) {
            first.push_back(f);
            first.push_back(s);
        }
        //first.print();
        //  second.print();
        count++;
    }
    if(first.size() == 0) cout << "second " << count;
    else if(second.size() == 0) cout << "first " << count;
    else cout << "botva";

    return 0;
}

