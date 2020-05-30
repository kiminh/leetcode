#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int result = 0;
        vector<int> diff(prices.size() - 1);
        for (auto i = 1; i < prices.size(); i++) {
            diff.push_back(prices[i] - prices[i - 1]);
        }
        vector<int> max_subsequence_sum(diff.size(), 0);
        max_subsequence_sum[0] = diff[0];
        for (auto i = 1; i < diff.size(); i++) {
            max_subsequence_sum[i] = std::max(diff[i], diff[i] + max_subsequence_sum[i - 1]);
        }
        return *std::max_element(max_subsequence_sum.begin(), max_subsequence_sum.end());
    }
};

int main(){
    vector<int> input{7,1,5,3,6,4};
    Solution s;
    std::cout<<s.maxProfit(input)<<std::endl;
    return 0;
}