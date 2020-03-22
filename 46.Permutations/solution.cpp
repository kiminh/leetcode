#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
template<class BidirIt>
bool my_next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;
    BidirIt i = last;
    if (first == --i) return false;
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (!(*i < *--i2))
                ;
            std::iter_swap(i, i2);
            std::reverse(i1, last);
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while(my_next_permutation(nums.begin(), nums.end()));
        return res;
    }
};

int main()
{
    std::vector<int> input{1,2,3};
    Solution s;
    s.permute(input);
    return 0;
}