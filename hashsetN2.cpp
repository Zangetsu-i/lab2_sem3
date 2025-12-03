#include "hashset.h"

unsigned int HashSet::hashFunction(const std::string& str) const {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = (hash * 33) + static_cast<unsigned char>(c);
    }
    return hash % HASH_SIZE;
}

HashSet::HashSet() : size(0) {
    for (int i = 0; i < HASH_SIZE; ++i) {
        buckets[i] = nullptr;
    }
}

HashSet::~HashSet() {
    for (int i = 0; i < HASH_SIZE; ++i) {
        SetNode* current = buckets[i];
        while (current) {
            SetNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

bool HashSet::add(const std::string& element) {
    if (contains(element)) return false;
    
    unsigned int index = hashFunction(element);
    SetNode* newNode = new SetNode{element, buckets[index]};
    buckets[index] = newNode;
    ++size;
    return true;
}

bool HashSet::remove(const std::string& element) {
    unsigned int index = hashFunction(element);
    SetNode* current = buckets[index];
    SetNode* prev = nullptr;
    
    while (current) {
        if (current->data == element) {
            if (!prev) {
                buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            --size;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool HashSet::contains(const std::string& element) const {
    unsigned int index = hashFunction(element);
    SetNode* current = buckets[index];
    while (current) {
        if (current->data == element) return true;
        current = current->next;
    }
    return false;
}

void HashSet::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть '" << filename << "'\n";
        return;
    }
    
    for (int i = 0; i < HASH_SIZE; ++i) {
        for (SetNode* current = buckets[i]; current; current = current->next) {
            file << current->data << '\n';
        }
    }
}

void HashSet::print() const {
    std::cout << "HashSet size: " << size << " {";
    bool first = true;
    for (int i = 0; i < HASH_SIZE; ++i) {
        for (SetNode* node = buckets[i]; node; node = node->next) {
            if (!first) std::cout << ", ";
            std::cout << node->data;
            first = false;
        }
    }
    std::cout << "}\n";
}
