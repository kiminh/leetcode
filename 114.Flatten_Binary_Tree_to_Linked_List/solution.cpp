
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <numeric>
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
    TreeNode* my_flatten(TreeNode* root) {
        TreeNode* rtn = root;
        if (root->left) {
            auto left_last = my_flatten(root->left);
            rtn = left_last;
            if (root->right) {
                rtn = my_flatten(root->right);
                left_last->right = root->right;
            } 
            root->right = root->left;
            root->left = nullptr;
        } else if (root->right) {
            rtn = my_flatten(root->right);
        }

        return rtn;
    }
    void flatten(TreeNode* root) {
        if (root != nullptr) {
            my_flatten(root);
        }
    }
};
int main() {
    std::list<int> tvalues{3,1,-1,2,-1,-1,4,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    //alg::tree::print<int, TreeNode>(node);
    Solution s;
    s.flatten(node);
    alg::tree::print<int, TreeNode>(node);
    return 0;
}