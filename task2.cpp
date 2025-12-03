#include "task2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

unsigned int hashFunction(const std::string& str) {
    unsigned int hash = 5381;
    for (char c : str) {
        hash = (hash * 33) + static_cast<unsigned char>(c);
    }
    return hash % HASH_SIZE;
}

void CreateHashSet(HashSet* set) {
    for (int i = 0; i < HASH_SIZE; i++) {
        set->buckets[i] = nullptr;
    }
    set->size = 0;
}

void DestroyHashSet(HashSet* set) {
    for (int i = 0; i < HASH_SIZE; i++) {
        SetNode* current = set->buckets[i];
        while (current != nullptr) {
            SetNode* temp = current;
            current = current->next;
            delete temp;
        }
        set->buckets[i] = nullptr;
    }
    set->size = 0;
}

void SETADD(HashSet* set, const std::string& element) {
    if (SET_AT(set, element)) {
        return;
    }

    unsigned int index = hashFunction(element);
    SetNode* newNode = new SetNode();
    newNode->data = element;
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
    set->size++;
}

void SETDEL(HashSet* set, const std::string& element) {
    unsigned int index = hashFunction(element);
    SetNode* current = set->buckets[index];
    SetNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data == element) {
            if (prev == nullptr) {
                set->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            set->size--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

bool SET_AT(HashSet* set, const std::string& element) {
    unsigned int index = hashFunction(element);
    SetNode* current = set->buckets[index];
    
    while (current != nullptr) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SaveHashSetToFile(HashSet* set, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл '" << filename << "' для записи" << std::endl;
        return;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        SetNode* current = set->buckets[i];
        while (current != nullptr) {
            file << current->data << std::endl;
            current = current->next;
        }
    }
    file.close();
}

void LoadHashSetFromFile(HashSet* set, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: не удалось открыть файл '" << filename << "' для чтения" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            SETADD(set, line);
        }
    }
    file.close();
}

void runTask2(int argc, char* argv[]) {
    if (argc < 5 || std::strcmp(argv[1], "--file") != 0 || std::strcmp(argv[3], "--query") != 0) {
        std::cout << "=== Задание 2: АТД Множество ===" << std::endl;
        std::cout << "Использование: ./program --file <путь_к_файлу> --query \"<команда> <элемент>\"" << std::endl;
        std::cout << "Команды: SETADD, SETDEL, SET_AT" << std::endl;
        std::cout << "Примеры:" << std::endl;
        std::cout << "  ./program --file data.txt --query \"SETADD apple\"" << std::endl;
        std::cout << "  ./program --file data.txt --query \"SET_AT apple\"" << std::endl;
        std::cout << "  ./program --file data.txt --query \"SETDEL apple\"" << std::endl;
        return;
    }

    std::string filename = argv[2];
    std::string query = argv[4];

    HashSet set;
    CreateHashSet(&set);

    LoadHashSetFromFile(&set, filename);

    std::istringstream iss(query);
    std::string command, element;
    iss >> command >> element;

    std::cout << "Файл: " << filename << std::endl;
    std::cout << "Команда: " << command << " " << element << std::endl;

    if (command == "SETADD") {
        SETADD(&set, element);
        SaveHashSetToFile(&set, filename);
        std::cout << "Результат: элемент '" << element << "' добавлен." << std::endl;
    } else if (command == "SETDEL") {
        SETDEL(&set, element);
        SaveHashSetToFile(&set, filename);
        std::cout << "Результат: элемент '" << element << "' удален." << std::endl;
    } else if (command == "SET_AT") {
        if (SET_AT(&set, element)) {
            std::cout << "Результат: элемент '" << element << "' найден." << std::endl;
        } else {
            std::cout << "Результат: элемент '" << element << "' не найден." << std::endl;
        }
    } else {
        std::cout << "Ошибка: неизвестная команда '" << command << "'" << std::endl;
        std::cout << "Доступные команды: SETADD, SETDEL, SET_AT" << std::endl;
    }

    std::cout << "Всего элементов в множестве: " << set.size << std::endl;
    DestroyHashSet(&set);
}