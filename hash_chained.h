#ifndef HASH_CHAINED_H
#define HASH_CHAINED_H

#include <vector>
#include <list>
#include <utility>
#include <functional>
#include <optional>
#include <cstddef>

template <class Key, class Value,
          class Hash = std::hash<Key>,
          class KeyEq = std::equal_to<Key>>
class HashMapChained {
public:
    explicit HashMapChained(std::size_t buckets = 16,
                            const Hash& h = Hash(),
                            const KeyEq& eq = KeyEq())
        : table_(buckets), hash_(h), eq_(eq), sz_(0) {}

    bool insert(const Key& k, const Value& v) {
        rehash_if_needed();
        auto& bucket = table_[index(k)];
        for (auto& [bk, bv] : bucket) {
            if (eq_(bk, k)) return false;
        }
        bucket.emplace_front(k, v);
        ++sz_;
        return true;
    }

    bool erase(const Key& k) {
        auto& bucket = table_[index(k)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (eq_(it->first, k)) {
                bucket.erase(it);
                --sz_;
                return true;
            }
        }
        return false;
    }

    std::optional<Value> find(const Key& k) const{
        const auto& bucket = table_[index(k)];
        for (const auto& [bk, bv] : bucket) {
            if (eq_(bk, k)) return bv;
        }
        return std::nullopt;
    }

    std::size_t size() const { return sz_; }
    bool empty() const { return sz_ == 0; }

private:
    using Bucket = std::list<std::pair<Key, Value>>;
    std::vector<Bucket> table_;
    Hash hash_;
    KeyEq eq_;
    std::size_t sz_;

    std::size_t index(const Key& k) const { return hash_(k) % table_.size(); }

    void rehash_if_needed() {
        const double load = static_cast<double>(sz_ + 1) / static_cast<double>(table_.size());
        if (load <= 1.0) return;
        rehash(table_.size() * 2);
    }

    void rehash(std::size_t newBuckets) {
        std::vector<Bucket> newTable(newBuckets);
        for (auto& bucket : table_) {
            for (auto& kv : bucket) {
                std::size_t idx = hash_(kv.first) % newBuckets;
                newTable[idx].push_front(std::move(kv));
            }
        }
        table_.swap(newTable);
    }
};

#endif
