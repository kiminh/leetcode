#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    inline int trans(char ch) {
        switch (ch) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
            default: return 0;
        }
        return 0;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        std::unordered_map<uint32_t, uint32_t> m;
        uint32_t bitmap = 0;
        const uint32_t mask = 0b11111111111111111111;
        for (size_t i = 0; i < s.size(); ++i) {
            bitmap = ((bitmap << 2) & mask) | trans(s[i]);
            if (i >= 9) {
                if (auto res = m.find(bitmap); res != m.end()) {
                    res->second++;
                } else {
                    m[bitmap] = 1;
                }
                if (m[bitmap] == 2) {
                    result.push_back(s.substr(i - 9 ,10));
                }
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