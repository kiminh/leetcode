#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include "tree_creator.h"
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
namespace alg::tree {

class INORDER {};
class PREORDER {};
class POSTORDER {};

template<typename ORDER, typename T, typename tree_node_t = default_tree_node_t<T>> 
class tree_iterator {};

template<typename T, typename tree_node_t> 
class tree_iterator<PREORDER, T, tree_node_t> {
    static T end_t;
    static tree_node_t end_node;
public:
    std::stack<tree_node_t*> sta;
    tree_iterator<PREORDER, T, tree_node_t>() {
        sta.push(&end_node);
    }
    tree_iterator<PREORDER, T, tree_node_t>(tree_node_t* node) {
        sta.push(&end_node);
        if (node != nullptr) {
            sta.push(node);
        }
    }
    tree_node_t& operator*() {
        return *sta.top();
    }
    tree_node_t* operator++() {
        auto top(sta.top());
        if (top != &end_node) {
            sta.pop();
            if (top->right) {
                sta.push(top->right);
            }
            if (top->left) {
                sta.push(top->left);
            }
        }
        return sta.top();
    }
    bool operator != (const tree_iterator<PREORDER, T, tree_node_t>& other) {
        return other.sta.top() != sta.top();
    }

};
template<typename T, typename tree_node_t> 
T tree_iterator<PREORDER, T, tree_node_t>::end_t;
template<typename T, typename tree_node_t> 
tree_node_t tree_iterator<PREORDER, T, tree_node_t>::end_node(end_t);

template<typename T, typename tree_node_t> 
class tree_iterator<INORDER, T, tree_node_t> {
    static T end_t;
    static tree_node_t end_node;
    void correct() {
        while (vtop != nullptr) {
            sta.push(vtop);
            vtop = vtop->left;
        }
    }
public:
    std::stack<tree_node_t*> sta;
    tree_node_t* vtop;
    tree_iterator<INORDER, T, tree_node_t>() {
        sta.push(&end_node);
    }
    tree_iterator<INORDER, T, tree_node_t>(tree_node_t* node) {
        sta.push(&end_node);
        vtop = node;
        correct();
    }
    tree_node_t& operator*() {
        return *sta.top();
    }
    tree_node_t* operator++() {
        auto top(sta.top());
        if (top != &end_node) {
            if (vtop == nullptr) {
                auto top_right = sta.top()->right;
                sta.pop();
                vtop = top_right;
                correct();
            } else {
                correct();
            }
        }
        return sta.top();
    }
    bool operator != (const tree_iterator<INORDER, T, tree_node_t>& other) {
        return other.sta.top() != sta.top();
    }

};
template<typename T, typename tree_node_t> 
T tree_iterator<INORDER, T, tree_node_t>::end_t;
template<typename T, typename tree_node_t> 
tree_node_t tree_iterator<INORDER, T, tree_node_t>::end_node(end_t);
}
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
       vector<int> result; 
       alg::tree::tree_iterator<alg::tree::INORDER, int, TreeNode> iter1(root1);
       alg::tree::tree_iterator<alg::tree::INORDER, int, TreeNode> iter2(root2);
       alg::tree::tree_iterator<alg::tree::INORDER, int, TreeNode> end;
       while (iter1 != end || iter2 != end) {
           if (iter1 != end && iter2 != end) {
               if ((*iter1).val < (*iter2).val) {
                   result.push_back((*iter1).val);
                   ++iter1;
               } else {
                   result.push_back((*iter2).val);
                   ++iter2;
               }
           } else if (iter1 != end) {
                result.push_back((*iter1).val);
                ++iter1;
           } else if (iter2 != end) {
                result.push_back((*iter2).val);
                ++iter2;
           }
       }
       return result;
    }
};

int main() {
    std::list<int> tvalues{1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,8,-1,-1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto i : s.getAllElements(node, node)) {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}

