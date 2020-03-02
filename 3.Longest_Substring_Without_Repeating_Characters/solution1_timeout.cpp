#include <string>
#include <iostream>
#include <map>
//#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
class Solution {
public:
    bool is_unique(string str) {
        std::set<char> s;
        for (auto ch : str) {
            if (s.find(ch) != s.end()) {
                return false;
            } else {
                s.insert(ch);
            }
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        size_t max_len = 0;
        for (auto b = 0; b < s.size(); b++) {
            for (auto len = 1; b + len <= s.size(); len++) {
                auto new_str = s.substr(b, len);
                if (is_unique(new_str) && len > max_len) {
                    max_len = len;
                }
            }
        }
        return max_len;
    }
};


int main() {
    Solution a;
    std::cout<<a.lengthOfLongestSubstring("abcabacbb")<<std::endl;
    std::cout<<a.lengthOfLongestSubstring("idavswxjxziezopvwnrgmsqndyjvsexahyyauxltwvxvlnshcmpqefdjdmhyqeaaeyczvnstksovfhehvuzzzclfqsdjwdjbelc")<<std::endl;
    // timeout
    std::cout<<a.lengthOfLongestSubstring(" ")<<std::endl;
    std::cout<<a.lengthOfLongestSubstring("abba")<<std::endl;
    return 0;
}