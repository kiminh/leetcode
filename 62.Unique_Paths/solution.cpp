#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::map<std::pair<int, int>, int> mp;
        mp[std::make_pair(0, 0)] = 1;
        for (int _m = 0; _m < m; _m++) {
            mp[make_pair(_m, 0)] = 1;
        }
        for (int _n = 0; _n < n; _n++) {
            mp[make_pair(0, _n)] = 1;
        }
        for (int _m = 1; _m < m; _m++) {
            for (int _n = 1; _n < n; _n++) {
                mp[make_pair(_m, _n)] = 0;
                if (_m > 0) {
                    mp[make_pair(_m, _n)] += mp[make_pair(_m - 1, _n)];
                }
                if (_n > 0) {
                    mp[make_pair(_m, _n)] += mp[make_pair(_m , _n - 1)];
                }
            }
        }
        return mp[make_pair(m - 1, n - 1)];
    }
};


int main() {
    Solution s;
    std::cout<<s.uniquePaths(7, 3)<<std::endl;
    return 0;
}