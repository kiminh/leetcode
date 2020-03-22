#include <vector>
#include <set> 
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    using coor_t = std::pair<uint32_t, uint32_t>;
    void dfs(const vector<vector<char>>& board, 
        uint32_t row, uint32_t col, 
        bool& is_s,  std::set<coor_t>& coors,
        uint32_t buttom , uint32_t right) {
        if (row == 0 || col == 0 || row == buttom|| col == right) {
            is_s = false;
        }
        if (coors.find(std::make_pair(row, col)) != coors.end()) {
            // already had visited
            return;
        }
        coors.insert(std::make_pair(row, col));
        if (row != 0 && board[row - 1][col] == 'O') {
            dfs(board, row - 1, col, is_s, coors, buttom, right);
        }
        if (row != buttom && board[row + 1][col] == 'O') {
            dfs(board, row + 1, col, is_s, coors, buttom, right);
        }
        if (col != 0 && board[row][col - 1] == 'O') {
            dfs(board, row, col - 1, is_s, coors, buttom, right);
        }
        if (col != right && board[row][col + 1] == 'O') {
            dfs(board, row, col + 1, is_s, coors, buttom, right);
        }
    }

    void solve(vector<vector<char>>& board) {
        std::set<coor_t> not_s;
        for (auto row = 0; row < board.size(); ++row) {
            for (auto col = 0; col< board[row].size(); ++col) {
                if (board[row][col] == 'X') {
                    continue;
                } else {
                    if (not_s.find(std::make_pair(row, col)) != not_s.end()) {
                        continue;
                    } else {
                        bool is_s = true;
                        std::set<coor_t> coors;
                        dfs(board, row, col, is_s, coors, board.size() - 1, board[row].size() - 1);
                        if (is_s) {
                            for (auto & c : coors) {
                                board[c.first][c.second] = 'X';
                            }
                        } else {
                            for (auto & c :coors) {
                                not_s.insert(c);
                            }
                        }
                    }
                }
            }
        }
    }
};


using map_t = vector<vector<char>>;
int main() {
    //map_t input = {
    //    {'X', 'X', 'X', 'X',},
    //    {'X', 'O', 'O', 'X',},
    //    {'X', 'X', 'O', 'X',},
    //    {'X', 'O', 'X', 'X',},
    //};
    map_t input = {
        {'O', 'X', 'O', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'O'},
        {'X', 'O', 'X', 'X', 'X', 'X'},
        {'O', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O', 'O', 'O'}
    };
    map_t result = {
        {'O', 'X', 'O', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X', 'O', 'O'},
        {'X', 'O', 'X', 'X', 'X', 'X'},
        {'O', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O', 'O', 'O'}
    };
    Solution s; 
    s.solve(input);
    for (auto & row : input) {
        for (auto& i : row) {
            std::cout<<i<<",";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    for (auto & row : result) {
        for (auto& i : row) {
            std::cout<<i<<",";
        }
        std::cout<<std::endl;
    }
    return 0;
}
