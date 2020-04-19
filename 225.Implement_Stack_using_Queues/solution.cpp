#include <iostream>
#include <queue>
#include <sstream>
#include <list>
#include "log.h"
using namespace std;

class MyStack {
public:
    using queue_t = std::queue<int>;
    queue_t ques[2];
    uint32_t current = 0;
    /** Initialize your data structure here. */

    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        ques[current].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto trans_cnt = ques[current].size() - 1;
        for (auto i = 0; i < trans_cnt; i++ ) {
            ques[(current + 1) % 2].push(ques[current].front());
            ques[current].pop();
        }
        auto top = ques[current].front();
        ques[current].pop();
        current = (current + 1) % 2;
        return top;
    }
    
    /** Get the top element. */
    int top() {
        auto trans_cnt = ques[current].size() - 1;
        for (auto i = 0; i < trans_cnt; i++ ) {
            ques[(current + 1) % 2].push(ques[current].front());
            ques[current].pop();
        }
        auto top = ques[current].front();
        ques[(current + 1) % 2].push(ques[current].front());
        ques[current].pop();
        current = (current + 1) % 2;
        return top;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
       return ques[current].empty();
    }
};


int main() {
    MyStack sta;
    sta.push(1);
    std::cout<<"top:"<<sta.top()<<std::endl;
    sta.push(2);
    std::cout<<"top:"<<sta.top()<<std::endl;
    std::cout<<sta.pop()<<std::endl;
    sta.push(3);
    std::cout<<"top:"<<sta.top()<<std::endl;
    sta.push(4);
    std::cout<<"top:"<<sta.top()<<std::endl;
    std::cout<<sta.pop()<<std::endl;
    std::cout<<"top:"<<sta.top()<<std::endl;
    std::cout<<sta.pop()<<std::endl;
    std::cout<<"top:"<<sta.top()<<std::endl;
    std::cout<<sta.pop()<<std::endl;
    return 0;
}