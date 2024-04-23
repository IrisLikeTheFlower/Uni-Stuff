#include "Table.h"

void Table::addElement(std::string key, int value)
{
    if (size < MAX_SIZE) {
        elements[size].key = key;
        elements[size].value = value;
        ++size;
    }
    else {
        std::cout << "Table Owerflow!\n";
    }
}

int Table::findValue(std::string key)
{
    for (int i = 0; i < size; i++) {
        if (elements[i].key == key) {
            return elements[i].value;
        }
    }
    std::cout << "Element with a key " << key << " not found!\n";
    return -1;
}

void Table::removeElement(std::string key) {
    for (int i = 0; i < size; ++i) {
        if (elements[i].key == key) {
            for (int j = i; j < size - 1; ++j) {
                elements[j] = elements[j + 1];
            }
            --size;
            return;
        }
    }
}
