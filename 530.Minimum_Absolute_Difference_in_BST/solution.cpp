#include <map>
#include <limits>
#include <utility>
#include <optional>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int min_abs;
    int getMinimumDifference(TreeNode* root) {
        min_abs = std::numeric_limits<int>::max();
        auto min_max = _get(root);
        return this->min_abs;
    }
    typedef int min_value_t;
    typedef int max_value_t;
    std::optional<std::pair<min_value_t, max_value_t>> _get(TreeNode* root) {
        if (root == nullptr) {
            return std::nullopt;
        }
        int min = root->val;
        int max = root->val;
        if (auto min_max = _get(root->left)) {
            int left_min, left_max;
            std::tie(left_min, left_max) = min_max.value();
            max = std::max(max, left_max);
            min = std::min(min, left_min);
            min_abs = std::min(min_abs, root->val - left_max);
            //printf("min_abs = min(%d, %d - %d)\n", min_abs, root->val, left_max);
        }
        if (auto min_max = _get(root->right)) {
            int right_min, right_max;
            std::tie(right_min, right_max) = min_max.value();
            max = std::max(max, right_max);
            min = std::min(min, right_min);
            min_abs = std::min(min_abs, right_min - root->val);
            //printf("min_abs = min(%d, %d - %d)\n", min_abs, right_min, root->val);
        }
        return std::make_pair(min, max);
    }

};


int main() {
    auto root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    Solution a;
    std::cout<<a.getMinimumDifference(root)<<std::endl;
    return 0;
}