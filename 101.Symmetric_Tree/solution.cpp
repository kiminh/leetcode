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
    bool my_isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            if (left->val != right->val) {
                return false;
            } else {
                if (my_isSymmetric(left->left, right->right) && 
                my_isSymmetric(left->right, right->left)) {
                    return true;
                }
            }
        } 
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return my_isSymmetric(root->left, root->right);
    }
};

int main() {
    std::list<int> tvalues{1,2,3,-1,-1,4,-1,-1,2,4,-1,-1,3,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    std::cout<<s.isSymmetric(node)<<std::endl;
    return 0;
}