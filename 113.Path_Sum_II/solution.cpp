
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
    vector<vector<int>> result;
    void dfs(TreeNode* root, int sum, vector<int>& path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == std::accumulate(path.begin(), path.end(), 0)){
                result.push_back(path);
            }
        } else {
            if (root->left) {
                dfs(root->left, sum, path);
            }
            if (root->right) {
                dfs(root->right, sum, path);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        result.clear();
        if (root != nullptr) {
            vector<int> path;
            dfs(root, sum, path);
        }
        return result;
        
        
    }
};
int main() {
    std::list<int> tvalues{5, 4, 11, 7,-1,-1,2,-1,-1,-1,8,13,-1,-1,4,5,-1,-1,1,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    std::function<void(int&)> visit = [&node](int& i){std::cout<<i<<",";};
    alg::tree::in_order_traversal_iteratively(node, visit);std::cout<<std::endl;
    Solution s;
    for (auto& v: s.pathSum(node, 22)) {
        for (auto & i: v) {
            std::cout<<i<<",";
        }
        std::cout<<std::endl;
    }
    return 0;
}