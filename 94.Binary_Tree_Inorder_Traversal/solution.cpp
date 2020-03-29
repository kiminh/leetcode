#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <stack>
#include "tree.h"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        alg::in_order_traversal_iteratively(root, 
            static_cast<std::function<void(int&)>>([&result](int& i){result.push_back(i);}));
        return result;
    }
};

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto i : s.inorderTraversal(node)) {
        std::cout<<i<<std::endl;
    }
    return 0;
}