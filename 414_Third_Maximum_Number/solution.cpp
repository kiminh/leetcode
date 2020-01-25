#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::set<int> s(nums.begin(), nums.end());
        switch(s.size()) {
        case 0: return 0;break;
        case 1: 
        case 2: return *(std::max_element(s.begin(), s.end()));break;
        case 3: return *(std::min_element(s.begin(), s.end()));break;
        default: {
        vector<int> result;
        for (auto i : s) {
            if (result.size() < 3) {
                result.push_back(i);
            } else {
                auto itr = std::min_element(result.begin(), result.end());
                if (i > *itr) {
                    *itr = i;
                }
            }
        }
        return std::min(result[0], std::min(result[1], result[2]));
        };break;
        }
        return 0;// never here
    }
};


int main() {
    vector<int> a{1,2,2,5,3,5}; 
    Solution s;
    std::cout<<s.thirdMax(a);
    return 0;
}
