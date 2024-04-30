#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
    setlocale(LC_CTYPE, "ukr");

    HashTable ht;
    ht.insertItem(Person("Пановик", "Петро"));
    ht.insertItem(Person("Туркевич", "Ірина"));
    ht.insertItem(Person("Михайлишин", "Людмила"));

    string searchKey = "Туркевич";
    Person* result = ht.searchItem(searchKey);
    if (result != nullptr) {
        cout << "Знайдено: " << result->name << " " << result->surname << endl;
    }
    else {
        cout << "Людини з прізвищем " << searchKey << " немає в таблиці." << endl;
    }
    
    return 0;
}
