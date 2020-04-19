#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        if (nums.size() == 1 &&nums[0] == 0) {
            return true;
        }
        vector<bool> states(nums.size(), false);
        states[0] = true;
        for (auto i = 1; i < nums.size(); i++) {
            for (auto b = i - 1; b >= 0; b--) {
                if (states[b] && b + nums[b] >= i) {
                    states[i] = true;
                    break;
                }
            }
        }
        return states.back();
    }
};

int main() {
    vector<int> input{2,3,1,1,4};
    Solution s;
    std::cout<<s.canJump(input)<<std::endl;
    return 0;
}