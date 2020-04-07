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
    vector<int> result;
    void level_order_traversal(TreeNode* root) {
        std::queue<std::pair<TreeNode*, size_t>> que;
        //result.push_back(root->val);
        size_t cur_level = 0;
        int last_val = root->val;
        que.push(std::make_pair(root, cur_level));
        while(!que.empty()) {
            if (que.front().second != cur_level) {
                cur_level = que.front().second;
                result.push_back(last_val);
            } 
            if (que.front().first->left) {
                que.push(std::make_pair(que.front().first->left, que.front().second + 1));
            }
            if (que.front().first->right) {
                que.push(std::make_pair(que.front().first->right, que.front().second + 1));
            }
            last_val = que.front().first->val;
            que.pop();
        }
        result.push_back(last_val);

    }
    vector<int> rightSideView(TreeNode* root) {
        result.clear();
        if (root != nullptr) {
            level_order_traversal(root);
        }
        return result;
    }
};
int main() {
    std::list<int> tvalues{1,2,4,-1,-1,-1,3,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto i : s.rightSideView(node)) {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}