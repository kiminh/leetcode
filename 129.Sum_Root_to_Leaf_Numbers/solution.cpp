#include <iostream>
#include <vector>
#include <list>
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
    int sum = 0;
    std::list<int> lst;
    void cal_sum(TreeNode* root) {
        lst.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            int temp = 0;
            for (auto i : lst) {
                temp  = temp * 10 + i;
            }
            this->sum += temp;
        } else {
            if (root->left) {
                cal_sum(root->left);
            }
            if (root->right) {
                cal_sum(root->right);
            }
        }
        lst.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        sum = 0;
        lst.clear();
        cal_sum(root);
        return sum;
    }
};

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    std::function<void(int&)> visit = [&node](int& i){std::cout<<i<<",";};
    alg::tree::in_order_traversal_iteratively(node, visit);std::cout<<std::endl;
    Solution s;
    std::cout<<s.sumNumbers(node)<<std::endl;;
    return 0;
}