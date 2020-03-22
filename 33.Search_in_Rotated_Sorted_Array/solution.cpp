#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class rvector: public vector<T> {
public:
    template<typename ITR>
    rvector(ITR b, ITR e) : vector<T>(b, e) {}
    int pivot = 0;
    void set_pivot(int p) {
        pivot = p; 
    }
    T operator [](const int index) const  {
        return vector<T>::operator[]((index + pivot) % this->size());
    }
};


class Solution {
public:
    template<typename V>
    static int find_pivot(const V& vec) {
        size_t pivot = 0;
        auto i = vec.size() - 1;
        for (; i > 0; --i) {
            if (vec[i] < vec[i - 1]) {
                return i;
            }
        }
        return 0;
    }

    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            if (nums[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }
        rvector<int> rvec(nums.begin(), nums.end());
        auto pivot = find_pivot(nums);
        rvec.set_pivot(pivot);
        auto res = binary_search(rvec, target);
        if (res == -1) {
            return res;
        } else {
            return (binary_search(rvec, target) + pivot) % rvec.size();
        }
    }

    template<typename V, typename T>
    static int binary_search(const V& vec, const T& target) {
        int result_index = -1; // -1 is not found
        int low = 0, high = vec.size(); 
        while (low <= high) {
            auto mid = low + (high - low) / 2; //overflow
            if (target == vec[mid]) {
                result_index = mid;
                break;
            } else if (target < vec[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result_index;
    }
};

int main() {
    //vector<int> input1{4,5,6,7,0,1,2};
    vector<int> input1{};
    Solution s;
    std::cout<<s.search(input1, 5) <<std::endl;
    return 0;
}