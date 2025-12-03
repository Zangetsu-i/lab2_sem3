#ifndef TASK2_H
#define TASK2_H

#include <string>

const int HASH_SIZE = 10007;

struct SetNode {
    std::string data;
    SetNode* next;
};

struct HashSet {
    SetNode* buckets[HASH_SIZE];
    int size;
};

void CreateHashSet(HashSet* set);
void DestroyHashSet(HashSet* set);
void SETADD(HashSet* set, const std::string& element);
void SETDEL(HashSet* set, const std::string& element);
bool SET_AT(HashSet* set, const std::string& element);
void SaveHashSetToFile(HashSet* set, const std::string& filename);
void LoadHashSetFromFile(HashSet* set, const std::string& filename);
void runTask2(int argc, char* argv[]);

#endif