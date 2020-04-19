#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include "log.h"

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if (events.empty()) {
            return 0;
        }
        std::sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });
        std::unordered_set<int> set;
        int result = 0;
        for (auto eid = 0; eid < events.size(); eid++) {
            for (auto day = events[eid][0]; day < events[eid][1]; day++) {
                if (set.count(day) == 0) {
                    result++;
                    set.insert(day);
                    break;
                }
            }
        }
        return result;
    }
    
};

int main() {
    //vector<vector<int>> input{{1,2},{2,3},{3,4},{1,2}};
    //vector<vector<int>> input{{1,2},{1,2},{1,6},{1,2},{1,2}};
    vector<vector<int>> input{{1,100000}};
    Solution s;
    std::cout<<s.maxEvents(input)<<std::endl;
    return 0;
}