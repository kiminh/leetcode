#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max_area = 0;
        while (l < r) {
            auto cur_area = std::min(height[l], height[r]) * (r - l);
            max_area = std::max(max_area, cur_area);
            if (height[l] >= height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> input{1 ,8, 6, 2, 5, 4, 8, 3, 7};
    std::cout<<s.maxArea(input)<<std::endl;
    vector<int> input2{1, 2, 1};
    std::cout<<s.maxArea(input2)<<std::endl;
    return 0;
}