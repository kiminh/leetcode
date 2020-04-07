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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<TreeNode*> que;
        que.push(root);
        size_t cnt = 0;
        while(!que.empty()) {
            if (que.front()->left && que.front()->right) {
                que.push(que.front()->left);
                que.push(que.front()->right);
            } else if (que.front()->left) {
                return cnt * 2 + 1 + 1;
            } else {
                return cnt * 2 + 1;
            } 
            que.pop();
            cnt ++;
        }
        return cnt + 1;

        
    }
};
int main() {
    std::list<int> tvalues{1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    alg::tree::print<int, TreeNode>(node);
    Solution s;
    std::cout<<s.countNodes(node)<<std::endl;
    return 0;
}