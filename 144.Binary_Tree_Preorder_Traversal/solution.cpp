#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iterator>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        std::stack<TreeNode*> sta;
        if (root == nullptr) {
            return result;
        }
        sta.push(root);
        while (!sta.empty()) {
            result.push_back(sta.top()->val);
            auto top = sta.top();
            sta.pop();
            if (top->right) {
                sta.push(top->right);
            }
            if (top->left) {
                sta.push(top->left);
            }
        }
        return result;
    }
};
int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto i : s.preorderTraversal(node)) {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}