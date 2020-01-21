#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* cur = nullptr;
        bool jw = false;
        while (l1 != nullptr && l2 != nullptr) {
            auto val = l1->val + l2->val + (jw ? 1 : 0);
            jw = val >= 10;
            val = val % 10;
            if (result == nullptr) {
                result = new ListNode(val);
                cur = result;
            } else {
                result->next = new ListNode(val);
                result = result->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (nullptr == l1 && nullptr == l2) {
            if (jw) {
                result->next = new ListNode(1);
            }
            return cur;
        } else {
            auto remind = l1 != nullptr ? l1 : l2;
            while (remind != nullptr) {
                auto val = remind->val + (jw ? 1 : 0);
                jw = val >= 10;
                val = val % 10;
                result->next = new ListNode(val);
                result = result->next;
                remind = remind->next;
            }
        }
        if (jw) {
            result->next = new ListNode(1);
        }
        return cur;
    }
};


int main() {
    
    ListNode* a_head = new ListNode(2);
    a_head->next = new ListNode(4);
    a_head->next->next = new ListNode(2);

    ListNode* b_head = new ListNode(8);
    b_head->next = new ListNode(5);
    b_head->next->next = new ListNode(7);
    b_head->next->next->next = new ListNode(9);
    
    Solution s;
    auto result = s.addTwoNumbers(a_head, b_head);
    if (result == nullptr) {
        return 0;
    }
    auto p = result;
    while(p != nullptr) {
        cout<<p->val<<std::endl;
        p = p->next;
    }
    return 0;
}



