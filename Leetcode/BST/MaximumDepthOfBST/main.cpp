#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include<algorithm>

using namespace  std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans1 = 0, ans2 = 0;
        if(root == nullptr) return 0;
        if(root->left == nullptr) {
            ans1 = max(ans1, maxDepth(root->right));
        }
        else if(root->right == nullptr) {
            ans2 = max(ans2, maxDepth(root->left));
        }
        else if(root->right == nullptr && root->left == nullptr ) return 1;
        else {
            ans1 = max(ans1, maxDepth(root->right));
            ans2 = max(ans1, maxDepth(root->left));
        }
        return max(ans1, ans2) + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
