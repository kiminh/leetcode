#include <iostream>
#include <vector>
#include <algorithm>
#include "log.h"
using namespace std;
#define TRACE(asdf, ...)
class Solution {
public:

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        };
        return std::max(rob1(nums), rob2(nums));

    }
    int rob1(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = 0;
        res[1] = nums[1];
        for (auto i = 2; i < nums.size(); i++) {
            res[i] = std::max(nums[i] + res[i - 2], res[i - 1]);
        }
        TRACE("rob1:[%d]", res.back());
        return res.back();
    }
    int rob2(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        res[1] = std::max(nums[0], nums[1]);
        for (auto i = 2; i < nums.size(); i++) {
            res[i] = std::max(nums[i] + res[i - 2], res[i - 1]);
        }
        *std::prev(res.end()) = *std::prev(res.end(), 2);
        TRACE("rob2:[%d]", res.back());
        return res.back();
    }
};

int main() {
    vector<int> input{1,2,3,1};
    Solution s;
    std::cout<<s.rob(input)<<std::endl;
    return 0;
}