
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
    using find_p_t = bool;
    using find_q_t = bool;
    std::pair<find_p_t, find_q_t> dfs(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
        std::pair<find_p_t, find_q_t> result{false, false};
        if (root == nullptr) {
            return result;
        }
        result = std::make_pair(root == p, root == q);
        if (root->left) {
            auto left_res = dfs(root->left, p, q, res);
            result.first |= left_res.first;
            result.second |= left_res.second;
        }
        if (root->right) {
            auto right_res = dfs(root->right, p, q, res);
            result.first |= right_res.first;
            result.second |= right_res.second;
        }
        if (result.first && result.second && res == nullptr) {
            res = root;
        }
        return result;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result = nullptr;
        dfs(root, p, q, result);
        return result;
        
    }
};
int main() {
    std::list<int> tvalues{3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);

    auto p_cond = [](const TreeNode& node){ return node.val == 7;};
    auto p_find_result = alg::tree::find_if<int, TreeNode>(node, 
        static_cast<std::function<bool(const TreeNode&)>>(p_cond));
    auto q_cond = [](const TreeNode& node){ return node.val == 0;};
    auto q_find_result = alg::tree::find_if<int, TreeNode>(node, 
        static_cast<std::function<bool(const TreeNode&)>>(q_cond));
    //alg::tree::print<int, TreeNode>(node);
    std::cout<<"p:"<<p_find_result->val<<std::endl;
    std::cout<<"q:"<<q_find_result->val<<std::endl;
    Solution s;
    auto lca = s.lowestCommonAncestor(node, p_find_result, q_find_result);
    std::cout<<lca->val<<std::endl;
    return 0;
}