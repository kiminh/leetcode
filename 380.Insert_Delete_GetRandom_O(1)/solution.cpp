#include <iostream>
#include "randomized_set.h"


class RandomizedSet {
public:
    /** Initialize your data structure here. */
    alg::randomized_set<int, int> s;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return s.insert(val, val);
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return s.erase(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return s.random_get();
    }
};

int main() {
    RandomizedSet s;
    std::cout<<s.insert(0)<<std::endl;
    std::cout<<s.insert(0)<<std::endl;
    std::cout<<s.insert(1)<<std::endl;
    std::cout<<s.insert(2)<<std::endl;
    std::cout<<s.insert(3)<<std::endl;
    std::cout<<s.insert(4)<<std::endl;
    std::cout<<s.insert(5)<<std::endl;
    std::cout<<s.insert(6)<<std::endl;
    std::cout<<s.remove(1)<<std::endl;
    std::cout<<s.remove(11)<<std::endl;
    std::cout<<s.remove(2)<<std::endl;
    std::cout<<s.remove(3)<<std::endl;
    std::cout<<s.remove(4)<<std::endl;
    std::cout<<s.remove(5)<<std::endl;
    std::cout<<s.remove(6)<<std::endl;
    return 0;
}