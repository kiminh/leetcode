#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];
        res[1] = std::max(nums[0], nums[1]);
        for (auto i = 2; i < nums.size(); i++) {
            res[i] = std::max(nums[i] + res[i - 2], res[i - 1]);
        }
        return res.back();
    }
};

int main() {
    vector<int> input{0};
    Solution s;
    std::cout<<s.rob(input)<<std::endl;
    return 0;
}