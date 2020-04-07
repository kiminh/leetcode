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

template<typename T, typename Iter, typename tree_node_t>
tree_node_t* construct_from_postorder_and_inorder(
    Iter postorder_begin, Iter postorder_last, Iter inorder_begin, Iter inorder_last) {
#ifdef _DEBUG
     std::stringstream ss;
     ss << "build from : postorder[";
     for (auto i = postorder_begin; i != std::next(postorder_last); ++i) {
         ss << *i <<",";
     }
     ss << "] inorder[";
     for (auto i = inorder_begin; i != std::next(inorder_last); ++i) {
         ss << *i <<",";
     }
     ss << "]";
     TRACE("%s", ss.str().c_str());
#endif

    auto root_node = new tree_node_t(*postorder_last);
    auto inorder_split = std::find(inorder_begin, std::next(inorder_last), *postorder_last);
    size_t left_size = std::distance(inorder_begin, inorder_split);
    size_t right_size = std::distance(inorder_split, inorder_last);
#ifdef _DEBUG
    TRACE("left_size:%lu, right_size:%lu", left_size, right_size);
#endif
    std::cout<<*inorder_split<<std::endl;

    if (left_size != 0) {
        root_node->left = construct_from_postorder_and_inorder<T, Iter, TreeNode>(
            postorder_begin, 
            std::next(postorder_begin, left_size - 1),
            inorder_begin, 
            std::prev(inorder_split));
    } else {
        root_node->left = nullptr;
    }
    if (right_size != 0) {
        root_node->right = construct_from_postorder_and_inorder<T, Iter, TreeNode>(
            std::next(std::next(postorder_begin, left_size - 1)),
            std::prev(postorder_last),
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        return alg::construct_from_postorder_and_inorder<int, vector<int>::iterator, TreeNode>(
            postorder.begin(), std::prev(postorder.end()),
            inorder.begin(), std::prev(inorder.end()));
    }
};


int main() {
    //vector<int> postorder{1,2,3};
    //vector<int> inorder{3,2,1};
    vector<int> postorder{9,15,7,20,3};
    vector<int> inorder{9,3,15,20,7};
    Solution s;
    auto node = s.buildTree(inorder, inorder);
    alg::in_order_traversal(node, 
        static_cast<std::function<void(int&)>>([](int&i){std::cout<<i<<",";}));
}