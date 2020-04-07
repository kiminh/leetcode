#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto begin = t.begin();
        for (auto i : s) {
            if (begin == t.end()) {
                return false;
            }
            if (auto res = std::find_if(begin, t.end(), 
                [i](auto pos){return pos == i;}); res == t.end()) {
                return false;
            } else {
                begin = std::next(res);
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::cout<<s.isSubsequence("adbc", "annnbnnncnnnd");

    return 0;
}