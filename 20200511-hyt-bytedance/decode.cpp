#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 题目描述：具体是给出一个字符串，再给出一个字段，要求算出有几种解码方式。


int main() {
    freopen("./input2.txt", "r", stdin);
    std::string text;
    cin>>text;
    int dict_cnt;
    cin >>dict_cnt;
    std::vector<std::string> words;
    std::string temp;
    for (int i = 0; i < dict_cnt; i++) {
        cin>>temp;
        words.push_back(temp);
    }
    int result = 0;
    std::vector<int> dp(text.size(), 0);
    for (int i = 0; i < dp.size(); i++) {
        for (auto& word : words) {
            int word_len = word.size();
            int begin  = i - word_len + 1;
            if (begin >= 0) {
                auto sub = text.substr(begin, word_len);
                if (word == sub) {
                    if (i-word_len < 0 || dp[i-word_len] != 0) {
                        dp[i]+=(i-word_len < 0 ? 1 : dp[i-word_len]);
                    }
                }
            }
        }
    }
    cout<<dp[dp.size()-1]%835672545;
    return 0;
}

