#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            return result;
        }
        if (intervals.size() == 1) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), 
        [](vector<int> & a, vector<int> & b){
            return a[0] < b[0];
        });
        auto push = [&](int b,int e) {result.push_back({b, e});};

        int l = intervals[0][0];
        int r = intervals[0][1];
        auto last = intervals.begin(), cur = intervals.begin() + 1;
        for (;cur != intervals.end(); last++, cur++) {
            if ((*cur)[0] > r) {
                push(l, r);
                l = (*cur)[0];
                r = (*cur)[1]; 
            } else {
                r = std::max(r, (*cur)[1]);
            } 
        }
        push(l, r);
        return result;
    }
};


int main() {
    {
        vector<vector<int>> input{{1,3},{2,6},{8,10},{15,18}};
        Solution s;
        for (auto i : s.merge(input)) {
            for (auto t : i) {
                std::cout<<t<<",";
            }
            std::cout<<"    ";
        }
        std::cout<<std::endl;
    }
    {
        vector<vector<int>> input{{1,8}, {2,3}, {4,5}};
        Solution s;
        for (auto i : s.merge(input)) {
            for (auto t : i) {
                std::cout<<t<<",";
            }
            std::cout<<"    ";
        }
        std::cout<<std::endl;
    }
    return 0;
}