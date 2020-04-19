#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "log.h"

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        temp.reserve(nums.size());
        for (auto& s : nums) {
            std::stringstream ss;
            ss << s;
            temp.push_back(ss.str());
        }
        std::sort(temp.begin(), temp.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });
        std::stringstream ss;
        bool valid = false;
        for (auto & i : temp) {
            if (i == "0" && !valid) {
                continue;
            }
            ss<<i;
            valid = true;
        }
        if (valid == false) {
            return "0";
        }
        return ss.str();
    }
};

int main() {
    vector<int> input{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Solution s;
    std::cout<<s.largestNumber(input)<<std::endl;
    return 0;
}



