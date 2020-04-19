#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include "log.h"

using namespace std;

#define TRACE(asdf, ...)
class Solution {
public:
    using day_t = int;
    using id_t = size_t;
    using record_t = std::map<day_t, std::map<id_t, std::pair<day_t, day_t>>>;
    using used_id_t = std::set<id_t>;
    int maxEvents(vector<vector<int>>& events) {
        record_t m;
        for (auto id = 0; id < events.size(); id++) {
            for (auto day = events[id][0]; day <= events[id][1]; day++) {
                m[day][id] = {events[id][0], events[id][1]};
            }
        }
        std::sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        used_id_t used;
        TRACE("max day:[%d]", events[events.size() - 1][1]);
        size_t max_event_cnt = 0;
        search(m, events[events.size() - 1][1], used, max_event_cnt);
        return max_event_cnt;
    }
    void search(record_t& m, day_t day, used_id_t& idset, size_t& max_event_cnt) {
        max_event_cnt = std::max(max_event_cnt, idset.size());
        if (day < 1) {
            return;
        }
        for (auto& event : m[day]) {
            if (idset.find(event.first) == idset.end()) {
                TRACE("try day[%d(%d)] attend[%d]{%d-%d}", day, m[day].size(), event.first, event.second.first, event.second.second);
                idset.insert(event.first);
                search(m, day - 1, idset, max_event_cnt);
                idset.erase(event.first);
            }
        }
        TRACE("try day[%d(%d)] attend[null]{}", day, m[day].size());
        search(m, day - 1, idset, max_event_cnt);
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