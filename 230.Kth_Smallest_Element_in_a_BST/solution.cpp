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
    int cnt;
    bool found;
    int my_kthSmallest(TreeNode* root) {
        if (root->left) {
            auto res = my_kthSmallest(root->left);
            if (found) {
                return res;
            }
        }
        --cnt;
        if (cnt == 0) {
            found = true;
            return root->val;
        }
        if (root->right) {
            auto res = my_kthSmallest(root->right);
            if (found) {
                return res;
            }
        }
        return 0;
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return 0;
        }
        cnt = k;
        found = false;
        return my_kthSmallest(root);
    }
};
int main() {
    std::list<int> tvalues{5,3,2,1,-1,-1,-1,4,-1,-1,6,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    std::cout<<s.kthSmallest(node, 5)<<std::endl;
    return 0;
}