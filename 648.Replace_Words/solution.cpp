#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "trie.h"
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        std::stringstream ss;
        trie tr;
        for (auto w : dict) {
            tr.insert(w);
        }
        for (size_t begin = 0; begin < sentence.size();) {
            size_t end = begin;
            do{
                ++end;
            } while(sentence[end] != ' ' && end < sentence.size());
            auto word = sentence.substr(begin, end - begin);
            begin = end + 1;
        }
        return "asdf";
    }
};


int main() {
    vector<string> dict = {"cat", "bat", "rat", "ca"};
    Solution s;
    s.replaceWords(dict, "the cattle was rattled by the battery");

    return 0;
}