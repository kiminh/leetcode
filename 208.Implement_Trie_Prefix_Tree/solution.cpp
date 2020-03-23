#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Trie {
public:
static const size_t ALPHABET_SIZE = 26;
    class node;
    std::shared_ptr<node> root = nullptr;
    class node {
    public:
        char data = ' ';
        bool is_word = false;
        std::shared_ptr<node> children[ALPHABET_SIZE];
        node(char ch) : data(ch), is_word(false) {
            for (auto i = 0; i < ALPHABET_SIZE; ++i) {
                children[i] = nullptr;
            }
        }
    };
    /** Initialize your data structure here. */
    Trie() {
        root = std::make_shared<node>(' ');
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto pos = root;
        for (auto ch : word) {
            auto index = ch - 'a';
            if (pos->children[index] == nullptr) {
                pos->children[index] = std::make_shared<node>(ch);
            } 
            pos = pos->children[index];
        }
        pos->is_word = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto pos = root;
        for (auto ch : word) {
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto pos = root;
        for (auto ch : prefix) {
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



int main() {
    Trie trie;
    trie.insert("apple");
    std::cout<<trie.search("apple")<<std::endl;   // returns true
    std::cout<<trie.search("app")<<std::endl;     // returns false
    std::cout<<trie.startsWith("app")<<std::endl; // returns true
    trie.insert("app");   
    std::cout<<trie.search("app")<<std::endl;     // returns true
    return 0;
}