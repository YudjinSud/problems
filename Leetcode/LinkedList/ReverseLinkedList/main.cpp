#include <iostream>
#include <bits/stdc++.h>

 using namespace  std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:

    void push_front(ListNode **head, int val) {
        ListNode* tmp = new ListNode();
        tmp->val = val;
        tmp->next = (*head);
        (*head) = tmp;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *res = nullptr;
        ListNode *tmp = new ListNode();
        while(head != nullptr) {
            push_front(&res, head->val);
            head = head -> next;
        }
        return res;
    }
};

int main() {
    vector<int>l = {1,2,3,4,5};
    ListNode *head = new ListNode();
    head->val = 1;
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution *sol = new Solution();
    ListNode *res = sol->reverseList(head);

    return 0;
}
