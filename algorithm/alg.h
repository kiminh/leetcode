// selection sort
#include <algorithm>
#include <vector>

template<typename Iter>
void selection_sort(Iter begin, Iter end) {
    for (;begin != end; ++begin) {
        std::iter_swap(begin, std::min_element(begin, end));
    }
}

template<typename T>
void print_permutation(std::vector<T>::iterator first, std::vector<T>::iterator last) {
    if (first == last) {
        auto pos = first;
        while(true) {
            if (pos == last)
        }

    }
}