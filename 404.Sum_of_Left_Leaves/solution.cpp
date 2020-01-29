class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        _sumOfLeftLeaves(root, false);
        return sum;
    }
    void _sumOfLeftLeaves(TreeNode* root, bool is_left) {
        if (is_left && !root->left && !root->right) {
            sum += root->val;
            return;
        } 
        if (root->left != nullptr) {
            _sumOfLeftLeaves(root->left, true);
        }
        if (root->right != nullptr) {
            _sumOfLeftLeaves(root->right, false);
        }
        
    }
};