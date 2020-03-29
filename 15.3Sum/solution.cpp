#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>
using namespace std;

class Solution {
public:
    using tuple = std::tuple<int, int, int>;
    sort(int a, int b, int c) {
        std::stringstream ss;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<uint32_t> uniq;
        vector<vector<int>> result;
        std::unordered_map<int, std::pair<int, int>> two_sum;
        for (auto i = 0; i < nums.size(); ++i) {
            if (auto pos = two_sum.find(0 - nums[i]); pos != two_sum.end()) {
                auto hash = nums[i] ^ pos->second.first ^ pos->second.second;
                if (uniq.find(hash) == uniq.end()) {
                    result.push_back({nums[i], pos->second.first, pos->second.second});
                    uniq.insert(hash);
                    printf("insert [%d][%d][%d]\n",nums[i], pos->second.first, pos->second.second);
                } else {
                    printf("already [%d][%d][%d]\n",nums[i], pos->second.first, pos->second.second);
                }
            } 
            for (auto t = 0; t < i; ++t) {
                two_sum[nums[i] + nums[t]] = std::make_pair(nums[i], nums[t]);
            }
        }
        return result;
        
    }
};

int main() {
    vector<int> input{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution s;
    for (auto & v: s.threeSum(input)) {
        for (auto i : v) {
            std::cout<<i<<',';
        }
        std::cout<<std::endl;
    }
}