#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool ishui(std::string& str) {
        for (int b = 0, e = str.size() - 1; b < e; b++, e--) {
            if (str[b] != str[e]) {
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        string max_len;
        for (auto b = 0; b < s.size(); b++) {
            for (auto e = b; e < s.size(); e++) {
                auto sub = s.substr(b, e - b + 1);
                if (ishui(sub) && sub.size() > max_len.size()) {
                    max_len = sub;
                }
            }
        }
        return max_len;
    }
};


int main() {
    Solution a;
    std::cout<<a.longestPalindrome("abbaabbaabbaabba")<<std::endl;
    std::cout<<a.longestPalindrome("miycvxmqggnmmcwlmizfojwrurwhwygwfykyefxbgveixykdebenzitqnciigfjgrzzbtgeazyrbiirmejhdwcgjzwqolrturjlqpsgunuqerqjevbheblmbvgxyedxshswsokbhzapfuojgyfhctlaifrisgzqlczageirnukgnmnbwogknyyuynwsuwbumdmoqwxprykmazghcpmkdcjduepjmjdxrhvixxbfvhybjdpvwjbarmbqypsylgtzyuiqkexgvirzylydrhrmuwpmfkvqllqvekyojoacvyrzjevaupypfrdguhukzuqojolvycgpjaendfetkgtojepelhcltorueawwjpltehbbjrvznxhahtuaeuairvuklctuhcyzomwrrznrcqmovanxmiyilefybkbveesrxkmqrqkowyrimuejqtikcjfhizsmumajbqglxrvevexnleflocxoqgoyrzgqflwiknntdcykuvdcpzlakljidclhkllftxpinpvbngtexngdtntunzgahuvfnqjedcafzouopiixw")<<std::endl;
    return 0;
}