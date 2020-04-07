#include <iostream>
#include <map>
#include "list.h"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
namespace alg::list {

template <typename T, typename list_node_t = default_list_node_t<T>>
void insert(list_node_t** list, const T& val) {
    if (list == nullptr) {
        return;
    }
    if (*list == nullptr) {
        *list = new list_node_t(val);
        return;
    }
    auto pos = (*list);
    while (pos->next != nullptr) {
        pos = pos->next;
    }
    pos->next = new list_node_t(val);
}

template <typename T, typename list_node_t = default_list_node_t<T>>
using copy_callback_t = std::function<void(list_node_t*, list_node_t*)>;

template <typename T, typename list_node_t = default_list_node_t<T>>
list_node_t* copy(list_node_t* list, copy_callback_t<T, list_node_t> callback = {}) {
    if (list == nullptr) {
        return nullptr;
    }
    list_node_t* result = nullptr;
    auto pos = &result;
    while (list) {
        if ((*pos) == nullptr) {
            (*pos) = new list_node_t(list->val);
            if (callback) {
                callback(list, *pos);
            }
        } 
        pos = &(*pos)->next;
        list = list->next;
    }
    return result;
}


};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node*, Node*> m;
        alg::list::copy_callback_t<int, Node> callback = [&m](Node* a, Node* b){
            m[a] = b;
            b->random = a->random;
        };
        auto result = alg::list::copy<int, Node>(head, callback);
        for (auto * pos = result; pos != nullptr; pos = pos->next) {
            if (pos->random != nullptr) {
                pos->random = m[pos->random];
            }
        }
        return result;
    }
};

int main() {
    using node_t = Node;
    node_t* list = nullptr;
    std::list<int> input{1,2,3,4,5,6,7,9};
    std::for_each(input.begin(), input.end(), 
        [&list](int &i) {alg::list::insert<int>(&list, i);});
    list->next->random = list->next->next->next;
    Solution s;
    auto res = s.copyRandomList(list);
    return 0;
}


