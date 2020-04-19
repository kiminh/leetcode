#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    std::stack<int> push_sta;
    std::stack<int> pop_sta;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if (push_sta.empty()) {
            while(!pop_sta.empty()) {
                push_sta.push(pop_sta.top());
                pop_sta.pop();
            }
        }
        push_sta.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (empty()) {
            return -1;
        }
        if (pop_sta.empty()) {
            while(!push_sta.empty()) {
                pop_sta.push(push_sta.top());
                push_sta.pop();
            }
        }
        auto res = pop_sta.top();
        pop_sta.pop();
        return res;
        
    }
    
    /** Get the front element. */
    int peek() {
        if (empty()) {
            return -1;
        }
        if (!pop_sta.empty()) {
            return pop_sta.top();
        } else {
            while(!push_sta.empty()) {
                pop_sta.push(push_sta.top());
                push_sta.pop();
            }
            return pop_sta.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return push_sta.empty() && pop_sta.empty();
        
    }
};


int main() {
    MyQueue que;
    que.push(1);
    que.push(2);
    que.push(3);
    std::cout<<que.peek()<<":"<<que.pop()<<std::endl;
    std::cout<<que.peek()<<":"<<que.pop()<<std::endl;
    que.push(4);
    std::cout<<que.peek()<<":"<<que.pop()<<std::endl;
    std::cout<<que.peek()<<":"<<que.pop()<<std::endl;
    return 0;
}