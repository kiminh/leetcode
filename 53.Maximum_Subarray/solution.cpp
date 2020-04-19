#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> max_sum(nums.size());
        max_sum[0] = nums[0];
        for (auto i = 1; i < max_sum.size(); i++) {
            max_sum[i] = std::max(nums[i], nums[i] + max_sum[i - 1]);
        }
        return *std::max_element(max_sum.begin(), max_sum.end());
    }
};