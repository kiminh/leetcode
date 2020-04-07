#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <numeric>
#include "tree.h"
#include "heap.h"
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::unordered_map<int, int> freq;
    int dfs(TreeNode* root) {
        int sum = root->val;
        if (root->left) {
            sum += dfs(root->left);
        }
        if (root->right) {
            sum += dfs(root->right);
        }
        if (freq.find(sum) == freq.end()) {
            freq[sum] = 0;
        }
        ++freq[sum];
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        freq.clear();
        dfs(root);
        if (freq.size() == 0) {
            return result;
        }
        using item_t = std::pair<int, int>;
        vector<item_t> heap;
        heap.reserve(freq.size());
        for (auto& i : freq) {
            heap.push_back(i);
        }
        auto cmp = [](const item_t& a, const item_t& b){return a.second < b.second;};
        alg::make_heap(heap, cmp);
        size_t freq = heap.begin()->second;
        int last = heap.size() - 1;
        while (heap.begin()->second == freq && last >= 0) {
            result.push_back(heap.begin()->first);
            alg::pop_heap(heap, last--, cmp);
        }
        return result;
    }
};

int main() {
    std::list<int> tvalues{1, -1, -1};
    auto node = alg::tree::create_from_pre_order<int, TreeNode>(tvalues, -1);
    Solution s;
    for (auto& i : s.findFrequentTreeSum(node)) {
        std::cout<<i<<",";
    }
    std::cout<<std::endl;
    return 0;
}

