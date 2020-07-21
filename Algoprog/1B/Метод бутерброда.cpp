#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char c;
    string maxWord, tempWord;
    while ((c = getchar())) {
        if (c != ' ')
            tempWord.push_back(c);

        if (c == ' ' || c == '\n') {
            if(c == '\n')
                tempWord.pop_back();
            if (tempWord.size() > maxWord.size()) {
                maxWord = tempWord;
            }
            tempWord = "";
        }

        if (c == '\n') break;
    }
    cout << maxWord << "\n" << maxWord.size();

    return 0;
}