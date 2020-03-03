#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string walk(const string& s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left --;
            right ++;
        }
        return s.substr(left + 1, right - left + 1 - 2);
    }
    string longestPalindrome(string s) {
        string max_len;
        for (auto i = 0; i < s.size(); i++) {
            string walk_res;
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                walk_res = walk(s, i, i + 1);
            } 
            if (walk_res.size() > max_len.size()) {
                max_len = walk_res;
            }
            walk_res = walk(s, i, i);
            if (walk_res.size() > max_len.size()) {
                max_len = walk_res;
            }
        }
        return max_len;
    }
};


int main() {
    Solution a;
    //std::cout<<a.walk("abcdefggfedcba", 5, 6)<<std::endl;
    //std::cout<<a.longestPalindrome("a")<<std::endl;
    std::cout<<a.longestPalindrome("ccc")<<std::endl;
    std::cout<<a.longestPalindrome("cbbd")<<std::endl;
    //std::cout<<a.longestPalindrome("abbaabbaabbaabba")<<std::endl;
    //std::cout<<a.longestPalindrome("miycvxmqggnmmcwlmizfojwrurwhwygwfykyefxbgveixykdebenzitqnciigfjgrzzbtgeazyrbiirmejhdwcgjzwqolrturjlqpsgunuqerqjevbheblmbvgxyedxshswsokbhzapfuojgyfhctlaifrisgzqlczageirnukgnmnbwogknyyuynwsuwbumdmoqwxprykmazghcpmkdcjduepjmjdxrhvixxbfvhybjdpvwjbarmbqypsylgtzyuiqkexgvirzylydrhrmuwpmfkvqllqvekyojoacvyrzjevaupypfrdguhukzuqojolvycgpjaendfetkgtojepelhcltorueawwjpltehbbjrvznxhahtuaeuairvuklctuhcyzomwrrznrcqmovanxmiyilefybkbveesrxkmqrqkowyrimuejqtikcjfhizsmumajbqglxrvevexnleflocxoqgoyrzgqflwiknntdcykuvdcpzlakljidclhkllftxpinpvbngtexngdtntunzgahuvfnqjedcafzouopiixw")<<std::endl;
    return 0;
}