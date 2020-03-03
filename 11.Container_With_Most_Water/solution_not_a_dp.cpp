#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> max_volume;
        max_volume.resize(height.size());
        max_volume[0] = 0;
        for (auto i = 1; i < max_volume.size(); i++) {
            auto last_max = max_volume[i - 1];
            auto current_height = height[i];
            auto last_max_height_iter = std::max_element(height.begin(), height.begin() + i);
            auto last_max_height = *last_max_height_iter;
            auto distince = std::distance(last_max_height_iter, height.begin() + i);
            auto current_max = std::min(current_height, last_max_height) * distince; 
            max_volume[i] = std::max<int>(last_max, current_max);
            //std::cout<<i<<" last_max:"<<last_max
            //<<" current_height:"<<current_height
            //<<" last_max_height:"<<last_max_height
            //<<" distince:"<<distince
            //<<" current_max:"<<current_max
            //<<std::endl;
        }
        return max_volume[max_volume.size() - 1];
    }
};

int main() {
    Solution s;
    vector<int> input{1,8,6,2,5,4,8,3,7};
    std::cout<<s.maxArea(input);
    vector<int> input2{1, 2, 1};
    std::cout<<s.maxArea(input2);
    return 0;
}