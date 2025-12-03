#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
#include <utility>
#include <cstddef>

template <class Key, class Value>
class LRUCache {
public:
    explicit LRUCache(std::size_t capacity)
        : capacity_(capacity) {}

    
    bool get(const Key& key, Value& out) {
        auto it = map_.find(key);
        if (it == map_.end()) {
            return false; // нет в кэше
        }
        
        list_.splice(list_.begin(), list_, it->second);
        out = it->second->second;
        return true;
    }


    void set(const Key& key, const Value& value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            it->second->second = value;
            list_.splice(list_.begin(), list_, it->second);
            return;
        }

        if (list_.size() == capacity_ && !list_.empty()) {
            auto last = list_.back();     
            map_.erase(last.first);       
            list_.pop_back();             
        }

        list_.emplace_front(key, value);
        map_[key] = list_.begin();
    }

    std::size_t size() const { return list_.size(); }
    std::size_t capacity() const { return capacity_; }

private:
    using ListIt = typename std::list<std::pair<Key, Value>>::iterator;

    std::size_t capacity_;
    std::list<std::pair<Key, Value>> list_;              
    std::unordered_map<Key, ListIt> map_;                
};

#endif 