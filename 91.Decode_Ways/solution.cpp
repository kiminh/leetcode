#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    size_t to_int(char a, char b) {
        if (a == '0') {
            return 0;
        }
        return (a - '0') * 10 + (b - '0');
    }
    int numDecodings(string s) {
        std::vector<size_t> res(s.size());
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        if (s.size() == 1) {
            return 1;
        }
        res[0] = 1;
        res[1] = s[1] != '0' ? 1 : 0;
        if (auto k = to_int(s[0], s[1]); k <= 26 && k >= 1) {
            res[1] += 1;
        }
        for (auto i = 2; i < s.size(); i++) {
            if (s[i] != '0') {
                res[i] = res[i - 1];
            } else {
                res[i] = 0;
            }
            if (auto k = to_int(s[i-1], s[i]); k <= 26 && k >= 1) {
                res[i] += res[i - 2];
            }
            if (res[i] == 0) {
                return 0;
            }
        }
        return res.back();
    }
};

int main() {
    Solution s;
    std::cout<<s.numDecodings("100")<<std::endl;
    return 0;
}