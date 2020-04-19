#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> v(n + 1, 0);
        v[1] = 1;
        for (auto i = 2; i <= n; i++) {
            for (auto x = 1; x <= i / 2 + 1; x++) {
                //{x, i - x}
                v[i] = std::max(v[i], v[x] * v[i - x]);
                v[i] = std::max(v[i], v[x] * (i - x));
                v[i] = std::max(v[i], x * v[i - x]);
                v[i] = std::max(v[i], x * (i - x));
            }
        }
        return v.back();
    }
};

int main() {
    Solution s;
    std::cout<<s.integerBreak(10)<<std::endl;
    return 0;
}
