#include <iostream>
#include <vector>
#include <map>
#include <memory>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef unsigned int Index;
        typedef int Diff;
        vector<int> dft;
        
        if (nums.size() < 2) {
            return dft;
        }
        map<Diff, Index> _temp;
        for (size_t pos = 0; pos < nums.size(); pos++) {
            if (auto itr = _temp.find(target - nums[pos]); 
                itr != _temp.end()) {
                return vector<int>{static_cast<int>(itr->second), 
                static_cast<int>(pos)};
            } else {
                _temp[nums[pos]] = pos;
            }
        }
        return std::move(dft);
    }
};


int main() {
    Solution s;
    vector<int> input{2, 7, 11, 15};
    for (auto & i : s.twoSum(input, 9)) {
        cout<<i<<std::endl;
    }
}
