#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool sign = false;
        unsigned int yax = x & (1<32 - 1);
        cout<<yax<<endl;
        if (x < 0) {
            sign = true;
        }
        // std::numeric_limits<int>::max():2^31-1 2147483647
        // std::numeric_limits<int>::min():-2^31  -2147483648

        unsigned int result = 0;
        while(yax) {
            auto mod = yax % 10;
            yax = yax / 10;
            cout<<yax<<" "<<mod<<" "<<result<<endl;
            if (!sign && result > (std::numeric_limits<int>::max() - mod) / 10) {
                return 0;
            }
            if (sign && result > (static_cast<unsigned int>(std::numeric_limits<int>::min()) - mod) / 10) {
                return 0;
            }
            result = result * 10 + mod;
        }
        if (sign) {
            return -1 * result;
        } else {
            return result;
        }
    }
};


int main() {
    Solution a;
    //cout<<std::numeric_limits<int>::max()<<endl;
    //cout<<static_cast<unsigned int>(std::numeric_limits<int>::min())<<endl;
    //cout<<a.reverse(1534236469)<<endl;
    //cout<<a.reverse(-2147483648)<<endl;
    cout<<a.reverse(-123)<<endl;
    return 0;
}