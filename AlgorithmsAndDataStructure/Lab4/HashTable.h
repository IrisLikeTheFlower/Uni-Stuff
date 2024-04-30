#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Person {
    string surname;
    string name;

    Person(string s, string n) : surname(s), name(n) {}
};

struct ListNode {
    Person data;
    ListNode* next;

    ListNode(Person p) : data(p), next(nullptr) {}
};

class HashTable {
private:
    static const int tableSize = 32;
    ListNode* table[tableSize];

    int hashFunction(string key) {
        return static_cast<unsigned char>(key[0]);
    }

public:
    HashTable() {
        for (int i = 0; i < tableSize; ++i) {
            table[i] = nullptr;
        }
    }

    void insertItem(Person p) {
        int index = hashFunction(p.surname);
        ListNode* newNode = new ListNode(p);
        newNode->next = table[index];
        table[index] = newNode;
    }

    Person* searchItem(string key) {
        int index = hashFunction(key);
        ListNode* currentNode = table[index];
        while (currentNode != nullptr) {
            if (currentNode->data.surname == key) {
                return &currentNode->data;
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }
};

