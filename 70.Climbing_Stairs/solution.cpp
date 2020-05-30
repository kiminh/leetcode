#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 1);
        v[0] = 1;
        v[1] = 1;
        for (auto i = 2; i <= n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }
        return v.back();
    }
};