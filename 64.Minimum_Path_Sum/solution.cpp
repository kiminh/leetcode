#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<int> path[2];
        path[0].resize(grid[0].size());
        path[1].resize(grid[0].size());
        size_t current_row = 0;
        for (auto row = 0; row < grid.size(); row ++) {
            for (auto col = 0; col < path[current_row].size(); col++) {
                if (row == 0) {
                    if (col == 0) {
                        path[current_row][col] = grid[row][col];
                    } else {
                        path[current_row][col] = path[current_row][col - 1] + grid[row][col];
                    }
                } else if (col == 0) {
                    if (row == 0) {
                        path[current_row][col] = grid[row][col];
                    } else {
                        path[current_row][col] = path[(current_row + 1) % 2][col] + grid[row][col];
                    }
                } else {
                        path[current_row][col] = std::min(path[(current_row + 1) % 2][col], 
                            path[current_row][col - 1]) + grid[row][col];
                }
            }
            current_row = (current_row + 1) % 2;
        }
        return path[(current_row + 1) % 2].back();
    }
};

int main() {
    vector<vector<int>> input{{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    std::cout<<s.minPathSum(input)<<std::endl;
    return 0;
}