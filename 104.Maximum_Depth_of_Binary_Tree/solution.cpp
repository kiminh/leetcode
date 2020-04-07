
#include <iostream>
#include <list>
#include <vector>
#include <queue>
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
    int cur_depth = 0;
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return max_depth;
        }
        cur_depth += 1;
        max_depth = std::max(max_depth, cur_depth);
        if (root->left) {
            maxDepth(root->left);
        }
        if (root->right) {
            maxDepth(root->right);
        }
        cur_depth -= 1;
        return max_depth;
    }
};

int main() {
    std::list<int> tvalues{1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    std::cout<<s.maxDepth(node)<<std::endl;
    return 0;
}