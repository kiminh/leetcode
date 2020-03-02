#include <string>
#include <iostream>
#include <map>
//#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, size_t> exists;
        size_t max_len = 0;
        for (auto b = 0; b < s.size(); b++) {
            for (auto e = b; e < s.size(); e++) {
                auto last_ch = s[e];
                if (auto res = exists.find(last_ch); res != exists.end()) {
                    b = res->second;
                    exists.clear();
                    break;
                } else {
                    exists[last_ch] = e;
                    if (e - b + 1 > max_len) {
                        max_len = e - b + 1;
                    }
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
    std::cout<<a.lengthOfLongestSubstring("dvdf")<<std::endl;
    // timeout
    std::cout<<a.lengthOfLongestSubstring(" ")<<std::endl;
    std::cout<<a.lengthOfLongestSubstring("abba")<<std::endl;
    return 0;
}