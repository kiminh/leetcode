#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include "trie.h"
using namespace std;

class Solution {
public:
    string process(string& word, trie& tr) {
        auto pos = tr.root;
        size_t len = 1;
        for (auto i : word) {
            if (pos->children[i - 'a']) {
                if (pos->children[i - 'a']->is_word) {
                    return word.substr(0, len);
                } else {
                    pos = pos->children[i - 'a'];
                }
            } else {
                break;
            }
            ++len;
        } 
        return word;
    }
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
            ss << process(word, tr)<< " ";
            begin = end + 1;
        }
        return ss.str().substr(0, ss.str().size() - 1);
    }
};


int main() {
    vector<string> dict = {"cat", "bat", "rat"};
    Solution s;
    std::cout<<s.replaceWords(dict, "the cattle was rattled by the battery");

    return 0;
}