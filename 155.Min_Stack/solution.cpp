#include <iostream>
#include <list>
#include "log.h"
using namespace std;
namespace alg::min_stack {

template <typename T>
class min_stack final {
    std::list<T> store;
    std::list<T> min_store;
public:
    bool empty() {
        return store.empty();
    }
    void push(const T& t) {
        if (min_store.empty()) {
            min_store.push_back(t);
        } else {
            min_store.push_back(std::min(t, min_store.back()));
        }
        store.push_back(t);
    }
    void pop() {
        store.pop_back();
        min_store.pop_back();
    }
    T& top() {
        return store.back();
    }
    T& min() {
        return min_store.back();
    }
};
}
class MinStack {
public:
    /** initialize your data structure here. */
    alg::min_stack::min_stack<int> msta;
    MinStack() : msta() {
        
    }
    
    bool empty() {
        return msta.empty();
    }
    
    void push(int x) {
        msta.push(x);
    }
    
    void pop() {
        msta.pop();
    }
    
    int top() {
        return msta.top();
    }
    
    int getMin() {
        return msta.min();
        
    }
};

int main() {
    MinStack msta;

    std::list<int> input{-2, 0, 1};
    for (auto i : input) {
        msta.push(i);
        TRACE("push: %d, min: %d", i, msta.getMin());
    }
    while (!msta.empty()) {
        TRACE("pop: %d, min: %d", msta.top(), msta.getMin());
        msta.pop();
    }
    return 0;
}