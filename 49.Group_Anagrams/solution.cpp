#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;



class Solution {
public:
    string hash(string in) {
        vector<int> cnt;
        cnt.resize(26);
        for (auto& i : cnt) {
            i = 0;
        }
        for (auto ch : in) {
            ++ cnt[ch - 'a'];
        }
        std::stringstream ss;
        for (auto i : cnt) {
            ss<<i<<"$";
        }
        return ss.str();

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        std::unordered_map<string, vector<string>> temp; 
        for (auto& str : strs) {
            auto h = hash(str);
            if (temp.find(h) == temp.end()) {
                temp.insert({h, decltype(temp)::value_type::second_type()});
            }
            temp[h].push_back(str);
        }
        result.reserve(temp.size());
        for (auto& i : temp) {
            result.push_back(i.second);
        }
        return result;
        
    }
};



int main() {
    vector<string> input{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    for (auto& v : s.groupAnagrams(input)) {
        for (auto& s : v) {
            std::cout<<s<<",";
        }
        std::cout<<std::endl;
    }
    return 0;
}