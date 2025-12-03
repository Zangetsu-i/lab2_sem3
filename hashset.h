#ifndef HASHSET_H
#define HASHSET_H
#include <string>
#include <iostream>
#include <fstream>

const int HASH_SIZE = 200007;  // Простое число для лучшего распределения

struct SetNode {
    std::string data;
    SetNode* next;
};

class HashSet {
private:
    SetNode* buckets[HASH_SIZE];
    size_t size;

    unsigned int hashFunction(const std::string& str) const;

public:
    HashSet();
    ~HashSet();
    
    bool add(const std::string& element);
    bool remove(const std::string& element);
    bool contains(const std::string& element) const;
    size_t getSize() const { return size; }
    
    void saveToFile(const std::string& filename) const;
    void print() const;
};
#endif
