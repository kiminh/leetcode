#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <cmath>

void get_divisor(unsigned int num, std::vector<unsigned int>& ans) {
    unsigned int square_root = (unsigned int) std::sqrt(num) + 1;
    for (int i = 2; i < square_root; i++) { 
        if (num % i == 0 && i * i != num) {
            ans.push_back(i);
            ans.push_back(num/i);
        }
        if (num % i == 0 && i * i == num) {
            ans.push_back(i);
        }
    }
}

using cache_t = std::map<unsigned int, std::vector<unsigned int> >;

std::vector<unsigned int>* yue(unsigned int num, cache_t& cache) {
    auto res = cache.find(num);
    if ( res != cache.end()) {
        return &(res->second);
    } else {
        cache[num] = {};
        get_divisor(num, cache[num]);
        return &cache[num];
    }
};

const unsigned int UINT_MAX_NUM = 0xFFFFFFFF;

int main() {
    //std::vector<unsigned int> res;
    //get_divisor(100, res);
    //for (auto i: res) {
    //    std::cout<<i<<",";
    //}
    //std::cout<<std::endl;
    unsigned int N = 4, M = 1000;
    std::cin>>N>>M;
    cache_t cache;
    std::map<unsigned int, std::map<unsigned int, unsigned int>> m;
    for (auto distance = 0; distance <= M - N; distance++) {
        for (auto t = N; t + distance <= M; t++) {
            m[t][t + distance] = UINT_MAX_NUM;
            if (distance == 0) {
                m[t][t + distance] = 0;
            } else {
                for (auto s : *yue(t, cache)) {
                    if (s == distance) {
                        m[t][t + distance] = 1;
                        break;
                    } else if (s < distance) {
                        if (m[t + s][t + distance] != UINT_MAX_NUM) {
                            m[t][t + distance] = std::min(m[t][t + distance],
                            1 + m[t + s][t + distance]);
                        }
                    }
                }
            }
            //std::cout<<t<<"-"<<t+distance<<":"<<m[t][t + distance]<<std::endl;
        }
    }
    std::cout<<m[N][M];
    return 0;
}