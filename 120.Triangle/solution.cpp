#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (auto row = 1; row < triangle.size(); row++) {
            for (auto col = 0; col != triangle[row].size(); col++) {
                if (col == 0) {
                    triangle[row][col] += triangle[row - 1][col];
                } else if (col == triangle[row].size() - 1) {
                    triangle[row][col] += triangle[row - 1][col - 1];
                } else {
                    triangle[row][col] += std::min(triangle[row - 1][col], triangle[row - 1][col - 1]);
                }
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

int main() {
    vector<vector<int>> input
    {
      {2},
      {3,4},
      {6,5,7},
      {4,1,8,3}
    };
    Solution s;
    std::cout<<s.minimumTotal(input)<<std::endl;
    return 0;
}