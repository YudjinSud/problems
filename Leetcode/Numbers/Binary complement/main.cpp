#include <iostream>

class Solution {
public:
    int findComplement(int num) {
        int i = 0, res = 0;
        while(num) {

            res += (1 & num) == 1 ? 0 : (1 << i);
            i++;
            num >>= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::cout << sol.findComplement(16) << std::endl;
    return 0;
}
