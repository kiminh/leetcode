#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class trie final {
public:
    static const size_t ALPHABET_SIZE = 26;
    class node;
    std::shared_ptr<node> root = nullptr;
    class node {
    public:
        char data = ' ';
        bool is_word = false;
        size_t cnt = 0;
        std::shared_ptr<node> children[ALPHABET_SIZE];
        node(char ch) : data(ch), is_word(false), cnt(0) {
            for (auto i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };

    trie() : root(std::make_shared<node>(' ')) {}
    trie(const trie& ) = delete;

    void insert(std::string str) { 
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                pos->children[index] = std::make_shared<node>(ch);
            } 
            pos->children[index]->cnt++;
            pos = pos->children[index];
        }
        pos->is_word = true;
    }

    bool find(std::string str) {
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                return false;
            } else {
                pos = pos->children[index];
            }
        }
        if (!pos->is_word) {
            return false;
        }
        return true;
    }
    bool startsWith(std::string str) {
        auto pos = root;
        for (auto ch : str) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                return false;
            } else {
                pos = pos->children[index];
            }
        }
        return true;
    }

};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        trie tr;
        for (auto & s : strs) {
            tr.insert(s);
        }
        auto root = tr.root;
        while (true) {
            size_t cnt = 0;
            char ch;
            for (auto pos = 0; pos < trie::ALPHABET_SIZE; pos++) {
                if (root->children[pos] != nullptr) {
                    cnt ++ ;
                    ch = 'a' + pos;
                }
            }
            if (cnt == 1 && root->children[ch - 'a']->cnt == strs.size()) {
                result.push_back(ch);
                root = root->children[ch - 'a'];
            } else {
                break;
            }
        }
        return result;
    }
};


int main() {
    //vector<string> input = {"flower","flow","flight"};
    //vector<string> input = {"dog","racecar","car"};
    vector<string> input = {"a","aa","aaa"};
    Solution s;
    std::cout<<s.longestCommonPrefix(input);
    return 0;
}