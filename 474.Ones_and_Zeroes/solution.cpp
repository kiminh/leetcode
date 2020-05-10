#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "log.h"
using namespace std;
#define TRACE(...)
using cnt_of_0_t = int;
using cnt_of_1_t = int;
using volume_t = std::pair<cnt_of_0_t, cnt_of_1_t>;
using volume_key_t = std::pair<int, volume_t>;
using result_t = std::vector<std::vector<int>>;

static volume_t Zero{0, 0};

volume_t operator-(const volume_t& a, const volume_t& b) {
    return {a.first - b.first, a.second - b.second};
}

bool operator>=(const volume_t& a, const volume_t& b) {
    if (a.first >= b.first && a.second >= b.second) {
        return true;
    }
    return false;
}

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        result_t result(m+1);
        for (auto& i : result) {
            i.resize(n+1);
            for (auto& k : i) {
                k = 0;
            }
        }
        std::vector<volume_t> articles;
        articles.reserve(strs.size());
        for (auto& str : strs) {
            int zero = 0, one = 0;
            for (auto ch : str) {
                if (ch == '0') {
                    zero ++;
                } else {
                    one ++;
                }
            }
            articles.push_back({zero, one});
        }
        for (int i = 0; i < articles.size(); i++) {
            for (int vol_pos_zero = m; vol_pos_zero >= 0; vol_pos_zero--) {
                for (int vol_pos_one = n; vol_pos_one >=0 ; vol_pos_one--) {
                    volume_t cur_vol{vol_pos_zero, vol_pos_one};
                    if (auto remain = cur_vol - articles[i]; remain >= Zero) {
                        auto yes = result[remain.first][remain.second] + 1;
                        if (yes > result[vol_pos_zero][vol_pos_one]) {
                            result[vol_pos_zero][vol_pos_one] = yes;
                        }
                    }
                }
            }
        }
        return result[m][n]; 
    }
};

//#define TRACE(...)
//using cnt_of_0_t = int;
//using cnt_of_1_t = int;
//using volume_t = std::pair<cnt_of_0_t, cnt_of_1_t>;
//using volume_key_t = std::pair<int, volume_t>;
//namespace std {
//template<> 
//struct hash<volume_t>
//{
//    std::size_t operator()(const volume_t& s) const noexcept
//    {
//        return s.first ^ (s.second << 1); 
//    }
//};
//}
//using result_t = std::vector<int>;
//static volume_t Zero{0, 0};
//volume_t operator-(const volume_t& a, const volume_t& b) {
//    return {a.first - b.first, a.second - b.second};
//}
//
//bool operator>=(const volume_t& a, const volume_t& b) {
//    if (a.first >= b.first && a.second >= b.second) {
//        return true;
//    }
//    return false;
//}
//bool operator<=(const volume_t& a, const volume_t& b) {
//    if (a.first <= b.first && a.second <= b.second) {
//        return true;
//    }
//    return false;
//}
//
//class SolutionTLE {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        result_t result((m+1)*(n+1));
//        for (auto& i : result) {
//            i = 0;
//        }
//        std::vector<volume_t> articles;
//        articles.reserve(strs.size());
//        for (auto& str : strs) {
//            int zero = 0, one = 0;
//            for (auto ch : str) {
//                if (ch == '0') {
//                    zero ++;
//                } else {
//                    one ++;
//                }
//            }
//            articles.push_back({zero, one});
//        }
//        vector<volume_t> volume_map((m+1)*(n+1));
//        size_t volume_map_cnt = 0;
//        std::map<volume_t, size_t> volume_map_reverse;
//        for (auto pos0 = 0; pos0 <= m; pos0++) {
//            for (auto pos1 = 0; pos1 <= n; pos1++) {
//                volume_t cur_vol{pos0, pos1};
//                volume_map[volume_map_cnt] = cur_vol;
//                volume_map_reverse[cur_vol] = volume_map_cnt;
//                volume_map_cnt++;
//            }
//        };
//        for (int i = 0; i < articles.size(); i++) {
//            for (int vol_pos = volume_map.size() - 1; vol_pos >=0 ; vol_pos--) {
//                volume_t cur_vol = volume_map[vol_pos];
//                TRACE("%d, {%d, %d} = %d", i, cur_vol.first, cur_vol.second, 
//                    result[vol_pos]);
//                if (auto remain = cur_vol - articles[i]; remain >= Zero) {
//                    auto reverse_index = volume_map_reverse[remain];
//                    auto yes = result[reverse_index] + 1;
//                    if (yes > result[vol_pos]) {
//                        result[vol_pos] = yes;
//                    }
//                    TRACE("%d, {%d, %d} = %d update", i, cur_vol.first, cur_vol.second, 
//                        result[vol_pos]);
//                }
//            }
//        }
//        return result[volume_map_reverse[{m, n}]]; 
//    }
//};


int main() {
    vector<string> input{"11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01","11","01"};
    //vector<string> input{"10","0","1"};
    Solution s;
    std::cout<<s.findMaxForm(input, 50, 50)<<std::endl;;
    return 0;
}