#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;

template <typename KT, typename VT>
class lru_cache {
public:
    using node_t = typename std::pair<KT, VT>;
    using list_t = typename std::list<node_t>;
    using map_t = typename std::unordered_map<KT, typename list_t::iterator>;
private:
    list_t _l;
    map_t _m;
    size_t cap;
public:
    lru_cache(int capacity) : cap(capacity) {}
    
    const VT* get(KT key) {
        if (auto pos = _m.find(key); pos != _m.end()) {
            _l.splice(_l.begin(), _l, pos->second);
            return &_l.front().second;
        } else {
            return nullptr;
        }
    }
    void put(KT key, const VT& value) {
        if (auto pos = _m.find(key); pos != _m.end()) {
            (*pos->second).second = value;
            _l.splice(_l.begin(), _l, pos->second);
        } else {
            _l.push_front(std::make_pair(key, value));
            _m[key] = _l.begin();
            if (_l.size() > cap) {
                _m.erase((*std::prev(_l.end())).first);
                _l.pop_back();
            } 
        }
    }
};

class LRUCache {
public:
    lru_cache<int, int> lru;
    LRUCache(int capacity) : lru(capacity) {}
    int get(int key) {
        if (auto res = lru.get(key); res != nullptr) {
            return *res;
        }
        return -1;
    }
    void put(int key, int value){
        lru.put(key, value);
    }
};

int main() {
    LRUCache lru(4);
    lru.put(1,11);
    lru.put(2,22);
    lru.put(3,33);
    lru.put(4,44);
    std::cout<<lru.get(1)<<std::endl;
    lru.put(5,55);
    lru.put(6,66);
    
    return 0;
}