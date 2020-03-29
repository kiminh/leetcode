#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <set>
#include "heap.h"
#include "log.h"
using namespace std;

//g++ -std=c++17 -I../alg/include/ -I../common/util/include solution.cpp ../common/util/src/log.cpp -o solution;./solution 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::vector<std::string> result;
        std::unordered_map<std::string, uint32_t> cnt;
        for (auto& str : words) {
            if (cnt.find(str) == cnt.end()) {
                cnt[str] = 0;
            }
            cnt[str]++;
        }
        using pair_t = std::pair<std::string, uint32_t>;
        std::vector<pair_t> heap;
        heap.reserve(cnt.size());
        for (auto & p : cnt) {
            heap.push_back(p);
        }
        std::vector<pair_t> temp_result;
        std::set<int> num_of_cnt;
        auto cmp = [](const pair_t& a, const pair_t& b){return a.second < b.second;};
        if (true) {
            alg::make_heap(heap, cmp);
            for (auto i = 1; num_of_cnt.size() <= k + 1 && i < heap.size() + 1; i++) {
                alg::pop_heap(heap, heap.size() - i, cmp);
                temp_result.push_back(*std::next(heap.end(), -1 * (i)));
                num_of_cnt.insert(std::next(heap.end(), -1 * (i))->second);
            }
        } else {
            std::make_heap(heap.begin(), heap.end(), cmp);
            for (auto i = 1; num_of_cnt.size() <= k + 1 && i < heap.size() + 1; i++) {
                std::pop_heap(heap.begin(), std::next(heap.end(), -1 * (i - 1)), cmp);
                temp_result.push_back(*std::next(heap.end(), -1 * (i)));
                num_of_cnt.insert(std::next(heap.end(), -1 * (i))->second);
            }
        }
        std::sort(temp_result.begin(), temp_result.end(),[](const pair_t& a, const pair_t& b){
            if (a.second > b.second) {
                return true;
            } else if (a.second < b.second) {
                return false;
            } else {
                return a.first < b.first;
            }
        });
        for (auto i = temp_result.begin(); i != temp_result.begin() + k; ++i) {
            result.push_back(i->first);
        }
        return result;
    }
};


int main() {
    std::vector<std::string> input{"the", "day", "is", "sunny", "the", 
    "uu", "uu",
    "the", "the", "sunny", "is", "is", "bug", "bug",
    "a", "b", "c", "d", "e"
    };
    //std::vector<std::string> input{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    Solution s;
    for (auto& s : s.topKFrequent(input, 4)) {
        std::cout<<"["<<s<<"]"<<std::endl;
    }
    return 0;
}