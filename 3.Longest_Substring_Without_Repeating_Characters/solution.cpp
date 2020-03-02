#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char, size_t> m;
        size_t max_len = 0;
        size_t begin_pos = 0;
        for (size_t end_pos = 0; end_pos < s.size(); end_pos++) {
            auto ch = s[end_pos];
            if (auto itr = m.find(ch); itr != m.end() && itr->second >= begin_pos) {
                begin_pos = m[ch] + 1;
            }
            max_len = std::max(max_len, end_pos - begin_pos + 1);
            m[ch] = end_pos;
            //printf("%s[%u:%u] ", s.c_str(), begin_pos, end_pos);
            //for(auto i = begin_pos; i <= end_pos; i++) {
            //    std::cout<<s[i];
            //}
            //std::cout<<" "<<max_len<<endl;
        }
        return max_len;
    }
};


int main() {
    Solution a;
    std::cout<<a.lengthOfLongestSubstring("abcabacbb")<<std::endl;
    std::cout<<a.lengthOfLongestSubstring("abba")<<std::endl;
    std::cout<<a.lengthOfLongestSubstring("idavswxjxziezopvwnrgmsqndyjvsexahyyauxltwvxvlnshcmpqefdjdmhyqeaaeyczvnstksovfhehvuzzzclfqsdjwdjbelc")<<std::endl;
    return 0;
}