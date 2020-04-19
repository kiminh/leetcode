#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;


class Solution {
public:
    bool contain(string target, string s) {
        auto begin = target.begin();
        for (auto ch : s) {
            begin = std::find(begin, target.end(), ch);
            if (begin == target.end()) {
                return false;
            } else {
                begin ++;
            }
        }
        return true;

    }
    class cmp {
        public:
        bool operator()(const string& a, const string& b) {
            if (a.size() != b.size()) {
                if (a.size() > b.size()) {
                    return false;
                } else return true;
            } else {
                return a > b;
            }
        }
    };
    string findLongestWord(string target, vector<string>& dir) {
        std::priority_queue<string, std::vector<string>, cmp> results;
        std::sort(dir.begin(), dir.end(), [](const string& a, const string& b) {
            return b.size() < a.size();
        });
        for (auto& s : dir) {
            if (s.size() > target.size()) {
                continue;
            }
            if (contain(target, s)) {
                results.push(s);
            }
        }
        if (!results.empty()) {
            return results.top();
        }
        return "";
    }
};

int main() {
    string s = "abpcplea";
    std::vector<string> d{"ale","apple","monkey","plea"};
    Solution solu;
    std::cout<<Solution::cmp()("apple", "bpplea")<<std::endl;
    solu.contain("abpcpea", "apple");
    std::cout<<solu.findLongestWord(s, d)<<std::endl;
    return 0;
}

