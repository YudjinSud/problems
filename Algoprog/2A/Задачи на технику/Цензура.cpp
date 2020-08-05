//
// Created by yudjin on 8/2/20.
//
#include <bits/stdc++.h>

#define int long long
#define vi vector<int>

const int sz = 256;

using namespace std;


int is_punctuation(char c){
    return (c == '.' || c == '!' || c == '?' || c == ':' || c == '-' ||
            c == ',' || c == ';' || c == '(' || c == ')' || c == ' ');
}


int is_suspicious(string s) {
    vi freq(sz);
    for(char c : s) {
        if(!is_punctuation(c)) {
            int pos = static_cast<unsigned char> (c);
            freq[pos]++;
        }

    }
    int cnt = 0;
    for(int i = 0; i < sz; i++) {
        if(freq[i] > 0) cnt++;
    }
    return cnt <= 3;
}


vector<string> tokenize(string s) {
    vector<string> line;
    int i = 0;
    while(i < s.size()) {
        string word;
        while(!is_punctuation(s[i]) && (i < s.size())) {
            word.push_back(s[i++]);
        }
        if(!word.empty()) {
            line.push_back(word);
        }
        i++;
    }
    return line;
}

int32_t main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    string s;

    while(getline(cin, s)) {
        vector<string> line = tokenize(s);
        int sCount = 0;
        for(string word : line) {
            if(is_suspicious(word)) sCount++;
        }
        if(sCount < (line.size() + 1)/ 2) {
            cout << s << "\n";
        }
    }

    return 0;
}