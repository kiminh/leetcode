#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <numeric>
#include "tree.h"
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        std::queue<std::pair<Node*, size_t>> que;
        que.push(std::make_pair(root, 0));
        while(!que.empty()) {
            auto front = que.front();
            que.pop();
            if (front.first->left) {
                que.push(std::make_pair(front.first->left, front.second + 1));
            }
            if (front.first->right) {
                que.push(std::make_pair(front.first->right, front.second + 1));
            }
            if (que.empty() || que.front().second != front.second) {
                front.first->next = nullptr;
            } else {
                front.first->next = que.front().first;
            }
        }
        return root;
    }
};

int main() {
    std::list<int> tvalues{1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, Node>(tvalues, -1);
    std::function<void(int&)> visit = [&node](int& i){std::cout<<i<<",";};
    Solution s;
    s.connect(node);
    alg::tree::print<int, Node>(node);
    return 0;
}