#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

namespace alg {


inline int parent(unsigned int i) {
    if (int res = (i - 1) / 2; res >= 0) {
        return res;
    }
    else {
        return -1;
    }
}

inline int left_child(unsigned int i, unsigned int end) {
    if (int res = i * 2 + 1; res <= end) {
        return res;
    }
    else {
        return -1;
    }
}

inline int right_child(unsigned int i, unsigned int end) {
    if (int res = i * 2 + 2; res <= end) {
        return res;
    }
    else {
        return -1;
    }
}

template <typename T>
bool default_cmp(const T& a, const T& b) {
    return a < b;
}

template < typename T >
using cmp_t = typename std::add_pointer<bool(const typename T::value_type&, const typename T::value_type&)>::type;

template <typename T>
void shift_down(T &data, unsigned begin, unsigned end, cmp_t<T> cmp) {
    auto root = begin;
    while (true) {
        auto swap = root;
        if (auto lchild = left_child(root, end); 
            lchild >=0 && cmp(data[lchild], data[root])) {
            swap = lchild;
        } 
        if (auto rchild = right_child(root, end); 
            rchild >= 0 && cmp(data[rchild], data[swap])) {
            swap = rchild;
        } 
        if (swap == root) {
            return;
        } else {
            std::swap(data[swap], data[root]);
            root = swap;
        }
    }
}
template <typename T>
void make_heap(T &data, cmp_t<T> cmp = default_cmp<typename T::value_type>) {
    for (auto root = parent(data.size() - 1); root >= 0; --root) {
        shift_down(data, root, data.size() - 1, cmp);
    }
}

template <typename T>
void heap_sort(T &data, cmp_t<T> cmp = default_cmp<typename T::value_type>) {
    make_heap(data, cmp);
    for (auto last = data.size() - 1; last > 0; --last) {
        std::swap(data[0], data[last]);
        shift_down(data, 0, last - 1, cmp);
    }
}


}

//g++ -std=c++17 -I../alg/include/ -I../common/util/include solution.cpp -o solution;./solution 
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
        if (false) {
            auto cmp = [](const pair_t& a, const pair_t& b){return a.second > b.second;};
            alg::make_heap(heap, cmp);
            for (auto i = 1; i <= k && i < heap.size() + 1; i++) {
                result.push_back(heap[0].first);
                std::swap(heap[0], heap[heap.size() - i]);
                alg::shift_down(heap, 0, heap.size() - 1 - i, cmp);
            }
        }
        if (true) {
            auto cmp_2 = [](const pair_t& a, const pair_t& b){return a.second < b.second;};
            std::make_heap(heap.begin(), heap.end(), cmp_2);
            for (auto i = 1; num_of_cnt.size() <= k + 1 && i < heap.size() + 1; i++) {
                std::pop_heap(heap.begin(), std::next(heap.end(), -1 * (i - 1)), cmp_2);
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
    Solution s;
    for (auto& s : s.topKFrequent(input, 3)) {
        std::cout<<s<<std::endl;
    }
    return 0;
}