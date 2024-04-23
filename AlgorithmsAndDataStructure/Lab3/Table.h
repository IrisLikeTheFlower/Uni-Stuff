#pragma once
#include <string>
#include <iostream>

const int MAX_SIZE = 5;

struct KeyValue {
    std::string key;
    int value;
};
class Table
{
    KeyValue elements[MAX_SIZE];
    int size;
public:
    Table() {
        size = 0;
    }

    void addElement(std::string key, int value);
    int findValue(std::string key);
    void removeElement(std::string key);
};
