#include <iostream>


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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *res = new TreeNode();
        if(t1 == nullptr && t2 == nullptr) return nullptr;
        else if(t1 == nullptr && t2 != nullptr) {
            res->val = t2->val;
            res->right = mergeTrees(nullptr, t2->right);
            res->left = mergeTrees(nullptr, t2->left);
        }
        else if(t2 == nullptr && t1 != nullptr) {
            res->val = t1->val;
            res->right = mergeTrees(t1->right, nullptr);
            res->left = mergeTrees(t1->left, nullptr);
        }
        else {
            res->val = t1->val + t2->val;
            res->right = mergeTrees(t1->right,t2->right);
            res->left = mergeTrees(t1->left, t2->left);
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
