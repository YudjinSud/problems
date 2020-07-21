#include <iostream>
#include <bits/stdc++.h>
using namespace  std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());
        int j = 0, i = 0;
        while(j < magazine.size()) {
            while(i < ransomNote.size() && ransomNote[i] == magazine[j]) {
                i++;
                j++;
            }
            j++;
        }
        return i >= ransomNote.size();
    }
};


int main() {
    string s1,  s2;
    cin >> s1;
    cin >> s2;
    Solution sol;
    cout << sol.canConstruct(s1, s2);
    return 0;
}
