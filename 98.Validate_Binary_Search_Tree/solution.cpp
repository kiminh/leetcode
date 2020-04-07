#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <numeric>
#include "log.h"
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
    using min_t = int;
    using max_t = int;
    std::pair<min_t, max_t> my_is_valid_bst(TreeNode* root, bool& is_valid) {
        std::pair<min_t, max_t> result = std::make_pair(root->val, root->val);
        if (root->left || root->right) {
            if (root->left) {
                auto left = my_is_valid_bst(root->left, is_valid);
                if (left.second >= root->val) {is_valid = false;}
                result = std::make_pair(
                    std::min(result.first, left.first),
                    std::max(result.second, left.second)
                );
            }
            if (root->right) {
                auto right = my_is_valid_bst(root->right, is_valid);
                if (right.first <= root->val) {is_valid = false;}
                result = std::make_pair(
                    std::min(result.first, right.first),
                    std::max(result.second, right.second)
                );
            }
        } 
        //TRACE("Result of %d, min:[%d] max:[%d]", root->val, result.first, result.second);
        return result;
    }
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool result = true;
        my_is_valid_bst(root, result);
        return result;
    }
};

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    std::function<void(int&)> visit = [&node](int& i){std::cout<<i<<",";};
    alg::tree::in_order_traversal_iteratively(node, visit);std::cout<<std::endl;
    Solution s;
    std::cout<<s.isValidBST(node)<<std::endl;;
    return 0;
}

