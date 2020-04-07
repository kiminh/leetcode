#include <iostream>
#include <vector>
#include "list"
#include <chrono>
#include <thread>
#include <stack>
#include "tree.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    alg::tree::tree_iterator<alg::tree::INORDER, int, TreeNode> iter;
public:
    BSTIterator(TreeNode* root) : iter(root){
    }
    int next() {
        auto res = (*iter).val;
        ++iter;
        return res;
    }
    bool hasNext() {
        return (iter != alg::tree::tree_iterator<alg::tree::INORDER, int, TreeNode>());
    }
};


int main() {
        
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    BSTIterator iter(node);
    while (iter.hasNext()) {
        std::cout<<iter.next()<<",";
    }
    std::cout<<std::endl;
    return 0;
}