#include <iostream>
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

namespace alg {

template<typename T, typename tree_node_t>
vector<vector<T>> level_order_traversal(tree_node_t* root) {
    using level_t = int;
    vector<vector<T>> result;
    vector<T> level_result;
    std::queue<std::pair<decltype(root), level_t>> que;
    if (root == nullptr) {
        return result;
    }

    level_t cur_level = 0;
    que.push(std::make_pair(root, cur_level));

    while (!que.empty()) {
        if (que.front().second != cur_level) {
            result.push_back(level_result);
            level_result.clear();
            cur_level = que.front().second;
        }
        level_result.push_back(que.front().first->val);
        if (que.front().first->left) {
            que.push(std::make_pair(que.front().first->left, que.front().second + 1));
        }
        if (que.front().first->right) {
            que.push(std::make_pair(que.front().first->right, que.front().second + 1));
        }
        que.pop();
    }
    result.push_back(level_result);
    return result;
}

};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return alg::level_order_traversal<int, TreeNode>(root);
    }
};

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto& level: s.levelOrder(node)) {
        for (auto& i : level) {
            std::cout<<i<<",";
        }
        std::cout<<std::endl;
    }
    return 0;
}
