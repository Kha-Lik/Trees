//
// Created by MykolaV on 14.03.2019.
//

#include "iostream"
#include "string.h"
#include "cstdlib"
using namespace std;

#include "LinkedHashEntry.cpp"

template <typename K, typename V>
class HashMap {

private:
    LinkedHashEntry **table;
    int size;

public:

    explicit HashMap(int sizeReceived) {
        this->size = sizeReceived;
        table = new LinkedHashEntry*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }


    V get(K key) {
        int hash = hashFunc(key);
        if (table[hash] == nullptr)
            return -1;
        else {
            LinkedHashEntry *entry = table[hash];
            while (entry != nullptr && entry->getKey() != key)
                entry = entry->getNext();
            if (entry == nullptr)
                return -1;
            else
                return entry->getValue();
        }
    }


    void put(K key, V value) {
        int hash = hashFunc(key);
        if (table[hash] == nullptr)
            table[hash] = new LinkedHashEntry(key, value);
        else {
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != nullptr)
                entry = entry->getNext();
            if (entry->getKey() == key)
                entry->setValue(value);
            else
                entry->setNext(new LinkedHashEntry(key, value));
        }
    }


    void remove(K key) {
        int hash = hashFunc(key);
        if (table[hash] != nullptr) {
            LinkedHashEntry *prevEntry = nullptr;
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != nullptr && entry->getKey() != key) {
                prevEntry = entry;
                entry = entry->getNext();
            }
            if (entry->getKey() == key) {
                if (prevEntry == nullptr) {
                    LinkedHashEntry *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                } else {
                    LinkedHashEntry *next = entry->getNext();
                    delete entry;
                    prevEntry->setNext(next);
                }
            }
        }
    }


    int hashFunc (int key) {
        key *= key;
        key >>= 11;
        return abs(key%size);
    }

    ~HashMap() {
        for (int i = 0; i < size; i++)
            if (table[i] != nullptr) {
                LinkedHashEntry *prevEntry = nullptr;
                LinkedHashEntry *entry = table[i];
                while (entry != nullptr) {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        delete[] table;
    }
};

