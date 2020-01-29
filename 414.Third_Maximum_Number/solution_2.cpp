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
        std::priority_queue<int> result;
        for (auto i : s) {
            result.push(i);
        }
        if (result.size() >= 3) {
            result.pop();
            result.pop();
        } 
        return result.top();
        return 0;// never here
    }
};


int main() {
    vector<int> a{1,2,2,5,3,5}; 
    Solution s;
    std::cout<<s.thirdMax(a);
    return 0;
}
