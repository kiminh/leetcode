#include <iostream>
#include <vector>
#include <map>
#include "sort.h"
using namespace std;

template<typename T>
std::ostream& operator << (std::ostream & out, const std::vector<T>& c) {
    for (auto i : c) {
        out << i << " ";
    }
    out<<std::endl;
    return out;
}

int main() {
    std::vector<int> input{9,8,7,6,5,4,3,2,1};
    std::cout<<input;
    selection_sort(input.begin(), input.end());
    std::cout<<input;
    std::sort();
    return 0;
}