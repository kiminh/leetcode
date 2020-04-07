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

namespace alg {

template<typename T, typename Iter, typename tree_node_t = default_tree_node_t<T>>
tree_node_t* construct_from_preorder_and_inorder(
    Iter preorder_begin, Iter preorder_last, Iter inorder_begin, Iter inorder_last) {
#ifdef _DEBUG
     std::stringstream ss;
     ss << "build from : preorder[";
     for (auto i = preorder_begin; i != std::next(preorder_last); ++i) {
         ss << *i <<",";
     }
     ss << "] inorder[";
     for (auto i = inorder_begin; i != std::next(inorder_last); ++i) {
         ss << *i <<",";
     }
     ss << "]";
     TRACE("%s", ss.str().c_str());
#endif

    auto root_node = new tree_node_t(*preorder_begin);

    auto inorder_split = std::find(inorder_begin, std::next(inorder_last), *preorder_begin);
    size_t left_size = std::distance(inorder_begin, inorder_split);
    size_t right_size = std::distance(inorder_split, inorder_last);

    if (left_size != 0) {
        root_node->left = construct_from_preorder_and_inorder<T, Iter, TreeNode>(
            std::next(preorder_begin), 
            std::next(std::next(preorder_begin), left_size - 1),
            inorder_begin, 
            std::prev(inorder_split));
    } else {
        root_node->left = nullptr;
    }
    if (right_size != 0) {
        root_node->right = construct_from_preorder_and_inorder<T, Iter, TreeNode>(
            std::next(std::next(std::next(preorder_begin), left_size - 1)),
            preorder_last,
            std::next(inorder_split), 
            inorder_last);
    } else {
        root_node->right = nullptr;
    }

    return root_node;
}

}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return alg::construct_from_preorder_and_inorder<int, vector<int>::iterator, TreeNode>(
            preorder.begin(), std::prev(preorder.end()),
            inorder.begin(), std::prev(inorder.end()));
    }
};


int main() {
    //vector<int> preorder{1,2,3};
    //vector<int> inorder{3,2,1};
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};
    Solution s;
    auto node = s.buildTree(preorder, inorder);
    alg::in_order_traversal(node, 
        static_cast<std::function<void(int&)>>([](int&i){std::cout<<i<<",";}));
}