#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return head;
        }
        decltype(head)  n_more_one = nullptr;
        size_t steps = n + 1;
        for (auto pos = head; pos != nullptr; pos = pos->next) {
            if (--steps == 0) {
                n_more_one = head;
            } else if (n_more_one != nullptr) {
                n_more_one = n_more_one->next;
            }
        }
        if (n_more_one == nullptr) {
            if (steps == 1) {
                // len == n
                auto temp = head->next;
                delete head;
                return temp;
            } else {
                // len < n
                return head;
            }
        } else {
            auto temp = n_more_one->next;
            n_more_one->next = n_more_one->next->next;
            delete temp;
            return head;
        }
    }
};

int main() {

    auto head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    Solution s;
    auto p = s.removeNthFromEnd(head, 2);
    while (p) {
        std::cout<<">"<<p->val <<std::endl;
        p = p->next;
    }
    return 0;
}