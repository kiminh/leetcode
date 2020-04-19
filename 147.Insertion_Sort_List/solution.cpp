#include <iostream>
#include "list.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        alg::list::sort<int, ListNode>(&head, [](const ListNode* a, const ListNode* b){return a->val <= b->val;});
        return head;
    }
};


int main() {
    ListNode * root = new ListNode(13);
    root->next = new ListNode(15);
    root->next->next = new ListNode(17);
    root->next->next->next = new ListNode(9);
    Solution s;
    auto res = s.insertionSortList(root);
    return 0;
}