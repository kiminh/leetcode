#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        std::unordered_map<string, int> m;
        if (s.size() < 10) {
            return result;
        }
        for (auto pos = 0; pos <= s.size() - 10; ++pos) {
            auto sub = s.substr(pos, 10);
            if (m.find(sub) == m.end()) {
                m.insert({sub, 0});
            }
            m[sub] ++;
        }
        for (auto& p : m) {
            if (p.second >= 2) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    for (auto& i : s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")) {
        std::cout<<i<<std::endl;
    }
    return 0;
}