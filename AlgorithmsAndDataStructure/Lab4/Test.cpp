#include "pch.h"
#include "../HashTable/HashTable.h"

TEST(HashTableTest, InsertAndSearch) {
    HashTable ht;

    ht.insertItem(Person("Коблан", "Христина"));

    Person* result = ht.searchItem("Коблан");
    ASSERT_NE(result, nullptr);
    ASSERT_EQ(result->name, "Христина");
}

TEST(HashTableTest, SearchItemTest) {
    HashTable ht;

    ht.insertItem(Person("Артим", "Богдан"));

    Person* result = ht.searchItem("Артим");
    ASSERT_NE(result, nullptr);
    ASSERT_EQ(result->name, "Богдан");
}

TEST(HashTableTest, InsertAndSearchMultiple) {
    HashTable ht;

    ht.insertItem(Person("Коваль", "Максим"));
    ht.insertItem(Person("Проць", "Михайло-Ігор"));
    ht.insertItem(Person("Мрака", "Ольга"));

    Person* result1 = ht.searchItem("Коваль");
    Person* result2 = ht.searchItem("Проць");
    Person* result3 = ht.searchItem("Мрака");

    ASSERT_NE(result1, nullptr);
    ASSERT_NE(result2, nullptr);
    ASSERT_NE(result3, nullptr);
}
