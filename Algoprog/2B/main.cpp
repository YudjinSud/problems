#include <bits/stdc++.h>

#define int long long

typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::pair<int, int>> vpi;

using namespace std;

int solve(string s, stack<char>st){
    int offset = 0;
    if(s[s.size()-1] == '\n') offset++;a
    for(int i = 0; i < s.size() - offset; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if(!st.empty()){
            switch (s[i]) {
                case '}' :
                    if(st.top() == '{') st.pop();
                    break;
                case ')' :
                    if(st.top() == '(') st.pop();
                    break;
                case ']' :
                    if(st.top() == '[') st.pop();
                    break;
                default:
                    return -1;

            }
        }
        else return -1;
    }
    return st.size();
}


int32_t main() {
    string s;
    getline(cin, s);

    stack<char>st;

    if(solve(s, st) == 0)  cout << "yes";
    else cout << "no";

    return 0;
}

