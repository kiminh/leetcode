#include <iostream>
#include <string>
#include "trie.h"
using namespace std;

;
class WordDictionary {
public:
    /** Initialize your data structure here. */
    trie t;
    WordDictionary() : t() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        t.insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool my_search(decltype(t.root) root, string word) {
        if (word.size() == 0) {
            return root->is_word;
        }
        if (word[0] == '.') {
            for (auto r : root->children) {
                if (r != nullptr && my_search(r, word.substr(1))) {
                    return true;
                }
            }
            return false;
        } else if (root->children[word[0] - 'a']) {
            return my_search(root->children[word[0] - 'a'], word.substr(1));
        }
        return false;
    }

    bool search(string word) {
        return my_search(t.root, word);
    }
};


int main() {

    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    std::cout<<wd.search("a")<<std::endl;
    std::cout<<wd.search(".at")<<std::endl;
    wd.addWord("bat");
    std::cout<<wd.search(".at")<<std::endl;
    std::cout<<wd.search("an.")<<std::endl;
    std::cout<<wd.search("a.d.")<<std::endl;
    std::cout<<wd.search("b.")<<std::endl;
    std::cout<<wd.search("a.d")<<std::endl;
    std::cout<<wd.search(".")<<std::endl;
    return 0; 
}