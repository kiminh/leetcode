#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <numeric>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (auto i = 1; i < prices.size(); i++) {
            if (auto diff = prices[i] - prices[i - 1]; diff > 0) {
                result += diff;
            }
        }
        return result;
    }
};

int main(){
    vector<int> input{7,1,5,3,6,4};
    Solution s;
    std::cout<<s.maxProfit(input)<<std::endl;
    return 0;
}