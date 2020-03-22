#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    void sortColors_slow(vector<int>& nums) {
        for (auto i = nums.begin(); i != nums.end(); i++) {
            std::iter_swap(i, std::min_element(i, nums.end()));
        }
    }
    void sortColors2(vector<int>& nums) {
        auto l = 0, r = nums.size() - 1;
        auto red = 0, blue = nums.size() - 1;
        for (; l <= r; l++, r--) {
            if (nums[l] == 2) {
                std::swap(nums[l], nums[r]);
            } else if (nums[r] = 0)
        }
    }
};


int main() {
    vector<int> input{2,0,2,1,1,0};
    Solution s;
    s.sortColors(input);
    for (auto i : input) {
        std::cout<<i;
    }
    std::cout<<std::endl;
    return 0;
}